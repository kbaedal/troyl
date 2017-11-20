#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "ray.h"
#include "rangen.h"

const double kPI = 3.141592653589793;

vec3 random_in_unit_disk()
{
    vec3 p;
    do {
        p = 2.0 * vec3(drand48(), drand48(), 0) - vec3(1.0, 1.0, 0.0);
    }
    while( dot(p, p) >= 1.0 );
    
    return p;
}

class camera 
{
    public:   
        camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float aperture, float focus_dist, float t0, float t1) { // vfov is top to bottom in degrees
            time0 = t0;
            time1 = t1;
            lens_radius = aperture / 2.0;
            float theta = vfov * kPI / 180.0;
            float half_height = tan(theta/2.0);
            float half_width = aspect * half_height;
            origin = lookfrom;
            w = unit_vector(lookfrom - lookat);
            u = unit_vector(cross(vup, w));
            v = cross(w, u);
            lower_left_corner = origin - half_width * focus_dist * u - half_height * focus_dist * v - focus_dist * w;
            horizontal = 2.0 * half_width * focus_dist * u;
            vertical = 2.0 * half_height * focus_dist * v;            
        }
        ray get_ray(float s, float t)
        {
            vec3 rd = lens_radius * random_in_unit_disk();
            vec3 offset = u * rd.x() + v * rd.y();
            float time = time0 + drand48() * (time1 - time0);
            return ray(origin + offset, lower_left_corner + s * horizontal + t * vertical - origin - offset, time);
        }
        
        vec3 lower_left_corner;
        vec3 horizontal;
        vec3 vertical;
        vec3 origin;
        vec3 u, v, w;
        float time0, time1;
        float lens_radius;
};

#endif // __CAMERA_H__