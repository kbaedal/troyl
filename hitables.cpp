#include "hitables.h"

const double kPI = 3.141592653589793;

//
// HITABLE LIST
//

bool hitable_list::hit(const ray &r, float tmin, float tmax, hit_record &rec) const
{
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = tmax;
    
    for(int i = 0; i < list_size; ++i) {
        if(list[i]->hit(r, tmin, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}

bool hitable_list::bounding_box(float t0, float t1, aabb &box) const
{
    if (list_size < 1) return false;

    aabb temp_box;
    bool first_true = list[0]->bounding_box(t0, t1, temp_box);

    if (!first_true)
        return false;
    else 
        box = temp_box;

    for (int i = 1; i < list_size; ++i) {
        if(list[0]->bounding_box(t0, t1, temp_box)) {
            box = surrounding(box, temp_box);
        }
        else
            return false;
    }
 
    return true;
}

//
// SPHERE
//

void get_sphere_uv(const vec3 &p, float &u, float &v) {
    float phi = std::atan2(p.z(), p.x());
    float theta = std::asin(p.y());
    u = 1 - (phi + kPI) / (2 * kPI);
    v = (theta + (kPI/2)) / kPI;
}

bool sphere::hit(const ray &r, float tmin, float tmax, hit_record &rec) const
{
    vec3 oc = r.origin() - center;
    
    float a = dot(r.direction(), r.direction());
    float b = 2.0 * dot(oc, r.direction());
    float c = dot(oc, oc) - radius * radius;
    
    float discriminant = b * b - 4.0 * a * c;
    
    if( discriminant > 0.0) {
        float temp = (-b - sqrt(discriminant)) / (2.0 * a);
        
        if(temp < tmax && temp > tmin) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            get_sphere_uv((rec.p-center)/radius, rec.u, rec.v);
            rec.normal = (rec.p - center) / radius;
            rec.mat_ptr = this->mat_ptr;
            
            return true;
        }
        
        temp = (-b + sqrt(discriminant)) / (2.0 * a);
        
        if(temp < tmax && temp > tmin) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            get_sphere_uv((rec.p-center)/radius, rec.u, rec.v);
            rec.normal = (rec.p - center) / radius;
            rec.mat_ptr = this->mat_ptr;
            
            return true;
        }        
    }
    
    return false;
}

bool sphere::bounding_box(float t0, float t1, aabb &box) const
{
    box = aabb(center - vec3(radius, radius, radius), center + vec3(radius, radius, radius));
    return true;
}

//
// MOVING SPHERE
//

bool moving_sphere::hit(const ray& r, float tmin, float tmax, hit_record& rec) const
{
    vec3 oc = r.origin() - center(r.time());
    
    float a = dot(r.direction(), r.direction());
    float b = 2.0 * dot(oc, r.direction());
    float c = dot(oc, oc) - radius * radius;
    
    float discriminant = b * b - 4.0 * a * c;
    
    if( discriminant > 0.0) {
        float temp = (-b - sqrt(discriminant)) / (2.0 * a);
        
        if(temp < tmax && temp > tmin) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center(r.time())) / radius;
            rec.mat_ptr = this->mat_ptr;
            
            return true;
        }
        
        temp = (-b + sqrt(discriminant)) / (2.0 * a);
        
        if(temp < tmax && temp > tmin) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center(r.time())) / radius;
            rec.mat_ptr = this->mat_ptr;
            
            return true;
        }        
    }
    
    return false;
}

vec3 moving_sphere::center(float time) const
{
    return center0 + ((time - time0) / (time1 - time0)) * (center1 - center0);
}

bool moving_sphere::bounding_box(float t0, float t1, aabb &box) const
{
    aabb boxt0(center(t0) - vec3(radius, radius, radius), center(t0) + vec3(radius, radius, radius));
    aabb boxt1(center(t1) - vec3(radius, radius, radius), center(t1) + vec3(radius, radius, radius));
    
    box = surrounding(boxt0, boxt1);
    
    return true;
}

//
// RECTANGLES
//

bool rect_xy::hit(const ray &r, float tmin, float tmax, hit_record &rec) const
{
    float t = (k - r.origin().z()) / r.direction().z();
    
    if( t < tmin || t > tmax)
        return false;
        
    float x = r.origin().x() + t * r.direction().x();
    float y = r.origin().y() + t * r.direction().y();
    
    if( (x < x0) || (x > x1) || (y < y0) || (y > y1) )
        return false;
        
    rec.u = (x - x0) / (x1 - x0);
    rec.v = (y - y0) / (y1 - y0);
    rec.t = t;
    rec.mat_ptr = mp;
    rec.p = r.point_at_parameter(t);
    rec.normal = vec3(0.0, 0.0, 1.0);
    
    return true;
}

bool rect_xz::hit(const ray &r, float tmin, float tmax, hit_record &rec) const
{
    float t = (k - r.origin().y()) / r.direction().y();
    
    if( t < tmin || t > tmax)
        return false;
        
    float x = r.origin().x() + t * r.direction().x();
    float z = r.origin().z() + t * r.direction().z();
    
    if( (x < x0) || (x > x1) || (z < z0) || (z > z1) )
        return false;
        
    rec.u = (x - x0) / (x1 - x0);
    rec.v = (z - z0) / (z1 - z0);
    rec.t = t;
    rec.mat_ptr = mp;
    rec.p = r.point_at_parameter(t);
    rec.normal = vec3(0.0, 1.0, 0.0);
    
    return true;
}

bool rect_yz::hit(const ray &r, float tmin, float tmax, hit_record &rec) const
{
    float t = (k - r.origin().x()) / r.direction().x();
    
    if( t < tmin || t > tmax)
        return false;
        
    float y = r.origin().y() + t * r.direction().y();
    float z = r.origin().z() + t * r.direction().z();
    
    if( (y < y0) || (y > y1) || (z < z0) || (z > z1) )
        return false;
        
    rec.u = (y - y0) / (y1 - y0);
    rec.v = (z - z0) / (z1 - z0);
    rec.t = t;
    rec.mat_ptr = mp;
    rec.p = r.point_at_parameter(t);
    rec.normal = vec3(1.0, 0.0, 0.0);
    
    return true;
}

//
// BOX
//

box::box(const vec3 &p0, const vec3 &p1, material *mat_ptr)
{
    pmin = p0;
    pmax = p1;
    hitable **list = new hitable*[6];
    
    list[0] = new rect_xy(p0.x(), p1.x(), p0.y(), p1.y(), p1.z(), mat_ptr);
    list[1] = new flip_normals(new rect_xy(p0.x(), p1.x(), p0.y(), p1.y(), p0.z(), mat_ptr));
    list[2] = new rect_xz(p0.x(), p1.x(), p0.z(), p1.z(), p1.y(), mat_ptr);
    list[3] = new flip_normals(new rect_xz(p0.x(), p1.x(), p0.z(), p1.z(), p0.y(), mat_ptr));
    list[4] = new rect_yz(p0.y(), p1.y(), p0.z(), p1.z(), p1.x(), mat_ptr);
    list[5] = new flip_normals(new rect_yz(p0.y(), p1.y(), p0.z(), p1.z(), p0.x(), mat_ptr));
    
    list_ptr = new hitable_list(list, 6);
}

bool box::hit(const ray &r, float tmin, float tmax, hit_record &rec) const
{
    return list_ptr->hit(r, tmin, tmax, rec);
}


