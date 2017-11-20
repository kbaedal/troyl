#include "vec3.h"

vec3 random_in_unit_sphere()
{
    vec3 p;
    int test = 0;
    do {
        p = 2.0*vec3(drand48(), drand48(), drand48()) - vec3(1.0, 1.0, 1.0);
        ++test;
        
        if(test > 50)
            std::cout << "MECAGONSATAN\n";
            
    }
    while( dot(p, p) >= 1.0 );
    
    return p;
}

vec3 reflect(const vec3 &v, const vec3 &n)
{
    return v - 2.0 * dot(v, n) * n;
}

bool refract(const vec3 &v, const vec3 &n, float ni_over_nt, vec3 &refracted)
{
    vec3 uv = unit_vector(v);
    float dt = dot(uv, n);
    float discriminant = 1.0 - ni_over_nt * ni_over_nt * (1.0 - dt * dt);
    if( discriminant > 0.0 ) {
        refracted = ni_over_nt * (uv - n * dt) - n * sqrt(discriminant);
        return true;        
    }
    else
        return false;
}