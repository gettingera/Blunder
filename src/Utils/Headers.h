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

/// Infinity.
const double infinity = std::numeric_limits<double>::infinity();

/// Pi.
const double pi = 3.1415926535897932385;

// Utility Functions

/**
 * Gets whether a vector is near zero.
 *
 * @param vec Vector.
 * @return Whether vector is near zero.
 */
inline bool near_zero(const dvec3 &vec) {
    // Return true if the vector is close to zero in all dimensions.
    const auto s = 1e-8;
    return (std::fabs(vec.x) < s) && (std::fabs(vec.y) < s) && (std::fabs(vec.z) < s);
}

/**
 * Gets whether a value is close to 0.
 *
 * @param val Value to check.
 * @return Whether value is close to zero.
 */
inline bool near_zero(const double val) {
    const auto s = 1e-8;
    return std::fabs(val) < s;
}

/**
 * Converts linear color space to gamma corrected color space.
 *
 * @param linear_component Color component to be gamma corrected.
 * @return Gamma corrected color component.
 */
inline double linear_to_gamma(double linear_component) {
    if (linear_component > 0)
        return std::sqrt(linear_component);

    return 0;
}

/**
 * Converts an angle in degrees to an angle in radians.
 *
 * @param degrees Angle in degrees.
 * @return Angle in radians.
 */
inline double degrees_to_radians(double degrees) {
    return degrees * 3.1415926535897932385 / 180.0;
}

/**
 * Gets a random double in [0, 1).
 *
 * @return Random double in [0, 1).
 */
inline double random_double() {
    return std::rand() / (RAND_MAX + 1.0);
}

/**
 * Gets a random number between a minimum and maximum.
 *
 * @param min Minimum number.
 * @param max Maximum number.
 * @return Random number between the minimum and maximum.
 */
inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max - min) * random_double();
}

/**
 * Returns a random integer between min and max.
 * @param min Minimum integer.
 * @param max Maximum integer.
 * @return Random integer between min and max.
 */
inline int random_int(int min, int max) {
    return static_cast<int>(random_double(min, max + 1));
}

/**
 * Gets a random vector in [0, 1)^3
 *
 * @return Component randomized 3D vector.
 */
static dvec3 random_dvec3() {
    return {random_double(), random_double(), random_double()};
}

/**
 * Gets a random vector in [min, max)^3
 * @param min Minimum number.
 * @param max Maximum number.
 * @return Component randomized 3D vector.
 */
static dvec3 random_dvec3(double min, double max) {
    return {random_double(min, max), random_double(min, max), random_double(min, max)};
}

/**
 * Gets a random unit vector.
 *
 * @return Normalized random unit vector.
 */
inline dvec3 random_unit_vector() {
    while (true) {
        auto p = random_dvec3(-1, 1);
        auto lensq = length2(p);
        if (1e-160 < lensq && lensq <= 1)
            return p / sqrt(lensq);
    }
}

/**
 * Gets a unit vector mapped on the hemisphere created by a surface normal.
 *
 * @param normal Normal of surface.
 * @return Random unit vector on hemisphere.
 */
inline dvec3 random_on_hemisphere(const vec3 &normal) {
    vec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}

/**
 * Gets a random point in the unit disk.
 *
 * @return Random point in the unit disk.
 */
inline dvec3 random_in_unit_disk() {
    while (true) {
        auto p = dvec3(random_double(-1, 1), random_double(-1, 1), 0);
        if (length2(p) < 1)
            return p;
    }
}

// Common Headers

#include "Utils/Ray.h"
#include "Utils/Interval.h"

#endif //HEADERS_H
