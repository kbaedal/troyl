#ifndef __HITABLES_H__
#define __HITABLES_H__

#include "ray.h"
#include "aabb.h"

class material;

struct hit_record
{
    float       t,
                u,
                v;
    vec3        p,
                normal;
    material    *mat_ptr;
};

class hitable
{
    public:
        virtual bool hit(const ray &r, float tmin, float tmax, hit_record &rec) const = 0;
        virtual bool bounding_box(float t0, float t1, aabb &box) const = 0;
};

class hitable_list : public hitable
{
    public:
        hitable_list() {}
        hitable_list(hitable **l, int n) { list = l; list_size = n; }
        
        virtual bool hit(const ray &r, float tmin, float tmax, hit_record &rec) const;
        virtual bool bounding_box(float t0, float t1, aabb &box) const;
        
        hitable **list;
        int list_size;
};

//
// SPHERE
//

class sphere : public hitable
{
    public:
        sphere() : center(vec3(0.0, 0.0, 0.0)), radius(1.0), mat_ptr(nullptr) {};
        sphere(vec3 cen, float r, material *mp) : center(cen), radius(r), mat_ptr(mp) {}
        
        virtual bool hit(const ray &r, float tmin, float tmax, hit_record &rec) const;
        virtual bool bounding_box(float t0, float t1, aabb &box) const;
        
        vec3    center;
        float   radius;
        material *mat_ptr;
};

//
// MOVING SPHERE
//

class moving_sphere : public hitable
{
    public:
        moving_sphere() {};
        moving_sphere(vec3 c0, vec3 c1, float t0, float t1, float r, material *m) :
            center0(c0), center1(c1), time0(t0), time1(t1), radius(r), mat_ptr(m) {}
    
        virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
        virtual bool bounding_box(float t0, float t1, aabb &box) const;
        
        vec3    center(float time) const;
        
        vec3    center0, center1;
        float   time0, time1;
        float   radius;
        material *mat_ptr;
};

//
// RECTANGLES
//

class rect_xy : public hitable
{
    public:
        rect_xy() {}
        rect_xy(float _x0, float _x1, float _y0, float _y1, float _k, material *_mp) :
            x0(_x0), x1(_x1), y0(_y0), y1(_y1), k(_k), mp(_mp) {}
            
        virtual bool hit(const ray &r, float tmin, float tmax, hit_record &rec) const;
        virtual bool bounding_box(float t0, float t1, aabb &box) const
        {
            box = aabb(vec3(x0, y0, k-0.0001), vec3(x1, y1, k+0.0001));
            return true;
        }
                
        float x0, x1, y0, y1, k;
        material *mp;
};

class rect_xz : public hitable
{
    public:
        rect_xz() {}
        rect_xz(float _x0, float _x1, float _z0, float _z1, float _k, material *_mp) :
            x0(_x0), x1(_x1), z0(_z0), z1(_z1), k(_k), mp(_mp) {}
            
        virtual bool hit(const ray &r, float tmin, float tmax, hit_record &rec) const;
        virtual bool bounding_box(float t0, float t1, aabb &box) const
        {
            box = aabb(vec3(x0, k-0.0001, z0), vec3(x1, k+0.0001, z1));
            return true;
        }
        
        float x0, x1, z0, z1, k;
        material *mp;
};

class rect_yz : public hitable
{
    public:
        rect_yz() {}
        rect_yz(float _y0, float _y1, float _z0, float _z1, float _k, material *_mp) :
            y0(_y0), y1(_y1), z0(_z0), z1(_z1), k(_k), mp(_mp) {}
            
        virtual bool hit(const ray &r, float tmin, float tmax, hit_record &rec) const;
        virtual bool bounding_box(float t0, float t1, aabb &box) const
        {
            box = aabb(vec3(k-0.0001, y0, z0), vec3(k+0.0001, y1, z1));
            return true;
        }
        
        float y0, y1, z0, z1, k;
        material *mp;
};

//
// FLIP NORMALS
//

class flip_normals : public hitable
{
    public:
        flip_normals(hitable *p) : ptr(p) {}
        virtual bool hit(const ray &r, float tmin, float tmax, hit_record &rec) const
        {
            if(ptr->hit(r, tmin, tmax, rec)) {
                rec.normal = -rec.normal;
                return true;
            }
            else {
                return false;
            }
        }
        virtual bool bounding_box(float t0, float t1, aabb &box) const
        {
            return ptr->bounding_box(t0, t1, box);
        }
  
    hitable *ptr;
};

//
// BOX
//

class box : public hitable
{
    public:
        box();
        box(const vec3 &p0, const vec3 &p1, material *mat_ptr);
        virtual bool hit(const ray &r, float tmin, float tmax, hit_record &rec) const;
        virtual bool bounding_box(float t0, float t1, aabb &box) const 
        {
            box = aabb(pmin, pmax);
            return true;
        }
    
    vec3 pmin, pmax;
    hitable *list_ptr;
};

#endif // __HITABLE_H__