#include "aabb.h"

aabb surrounding(aabb box0, aabb box1) {
    vec3 small(std::fmin(box0._min.x(), box1._min.x()),
        std::fmin(box0._min.y(), box1._min.y()),
        std::fmin(box0._min.z(), box1._min.z()));
        
    vec3 big(std::fmax(box0._max.x(), box1._max.x()),
        std::fmax(box0._max.y(), box1._max.y()),
        std::fmax(box0._max.z(), box1._max.z()));
        
    return aabb(small, big);
}