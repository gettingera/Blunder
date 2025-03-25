#ifndef HEADERS_H
#define HEADERS_H

#define GLM_ENABLE_EXPERIMENTAL

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <random>
#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>


// C++ Std Usings

using std::make_shared;
using std::shared_ptr;
using namespace glm;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double linear_to_gamma(double linear_component)
{
    if (linear_component > 0)
        return std::sqrt(linear_component);

    return 0;
}

inline double degrees_to_radians(double degrees) {
    return degrees * 3.1415926535897932385 / 180.0;
}

inline double random_double() {
    // Returns a random real in [0,1).
    return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double();
}

static dvec3 random_dvec3() {
    return {random_double(), random_double(), random_double()};
}

static dvec3 random_dvec3(double min, double max) {
    return {random_double(min,max), random_double(min,max), random_double(min,max)};
}

inline dvec3 random_unit_vector() {
    while (true) {
        auto p = random_dvec3(-1,1);
        auto lensq = length2(p);
        if (1e-160 < lensq && lensq <= 1)
            return p / sqrt(lensq);
    }
}

inline dvec3 random_on_hemisphere(const vec3& normal) {
    vec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}

// Common Headers

#include "Utils/Ray.h"
#include "Utils/Interval.h"

#endif //HEADERS_H
