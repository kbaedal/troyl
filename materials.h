#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "hitables.h"
#include "textures.h"

class material
{
    public:
        virtual bool scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &scattered) const = 0;
        virtual vec3 emitted(float u, float v, const vec3 &p) const { return vec3(0.0, 0.0, 0.0); }
        virtual ~material() {};
};

//
// LAMBERTIAN
//

class lambertian : public material
{
    public:
        lambertian(texture *a) : albedo(a) {}
        virtual bool scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &scattered) const
        {
            vec3 target = rec.p + rec.normal + random_in_unit_sphere();
            scattered = ray(rec.p, target - rec.p);
            attenuation = albedo->value(rec.u, rec.v, rec.p);
            
            return true;
        }
        
        texture *albedo;
};

//
// METAL
//

class metal : public material
{
    public:
        metal(const vec3 &a, float f) : albedo(a) { fuzz = f < 1.0 ? f : 1.0; }
        virtual bool scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &scattered) const
        {
            vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
            scattered = ray(rec.p, reflected + fuzz * random_in_unit_sphere());
            attenuation = albedo;
            
            return ( dot(scattered.direction(), rec.normal) > 0.0 );
        }
        
        vec3 albedo;
        float fuzz;
};

//
// DIELECTRIC
//

class dielectric : public material
{
    public:
        dielectric(float ri) : ref_idx(ri) {}        
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;
        
        float ref_idx;
};

//
// DIFFUSE LIGHT
//

class diffuse_light : public material
{
    public:
        diffuse_light() {}
        diffuse_light(texture *a) : emit(a) {}
        virtual bool scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &scattered) const
        {
            return false;
        }
        virtual vec3 emitted(float u, float v, const vec3 &p) const
        {
            return emit->value(u, v, p);
        }
        
        texture *emit;
};

//
// ISOTROPIC
//

class isotropic : public material
{
    public:
        isotropic(texture *a) : albedo(a) {}
        virtual bool scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &scattered) const
        {
            scattered = ray(rec.p, random_in_unit_sphere());
            attenuation = albedo->value(rec.u, rec.v, rec.p);
            
            return true;
        }
        
        texture *albedo;
};

#endif // __MATERIAL_H__