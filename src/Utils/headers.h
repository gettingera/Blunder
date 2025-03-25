#ifndef HEADERS_H
#define HEADERS_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <random>
#include <glm/glm.hpp>


// C++ Std Usings

using std::make_shared;
using std::shared_ptr;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    // Returns a random real in [0,1).
    return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double();
}

static glm::dvec3 random_dvec3() {
    return {random_double(), random_double(), random_double()};
}

static glm::dvec3 random_dvec3(double min, double max) {
    return {random_double(min,max), random_double(min,max), random_double(min,max)};
}

// Common Headers

#include "Utils/Ray.h"
#include "Utils/Interval.h"

#endif //HEADERS_H
