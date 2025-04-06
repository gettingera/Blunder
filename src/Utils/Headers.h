#ifndef HEADERS_H
#define HEADERS_H

// Allow usage of experimental GLM functions (like length2)
#define GLM_ENABLE_EXPERIMENTAL

// Common system and lib headers
#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <random>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>

// C++ std usings, glm namespace
using std::make_shared;
using std::shared_ptr;
using namespace glm;

// Constants
/// Infinity.
constexpr float infinity = std::numeric_limits<float>::infinity();

/// Pi.
constexpr float pi = 3.14159265358979;

// Utility Functions
/**
 * Gets whether a value is finite.
 * @param val Value to check.
 * @return Whether val is finite valued.
 *
 * @note Test Cases:
 * constexpr float infinity = std::numeric_limits<float>::infinity()
 * is_finite(0) -> true
 * is_finite(infinity) -> false
 * is_finite(-infinity) -> false
 * is_finite(NAN) -> false
 */
inline bool is_finite(const float val) {
    return std::isfinite(val);
}

/**
 * Gets whether a vector is finite.
 * @param vec Vector to check.
 * @return Whether all components of the vector are finite valued.
 *
 * Test Cases:
 * constexpr float infinity = std::numeric_limits<float>::infinity()
 * is_finite(vec3(0, 0, 0)) -> true
 * is_finite(vec3(infinity, infinity, infinity)) -> false
 * is_finite(vec3(-infinity, -infinity, -infinity)) -> false
 * is_finite(vec3(NAN, NAN, NAN)) -> false
 */
inline bool is_finite(const vec3 &vec) {
    return is_finite(vec.x) && is_finite(vec.y) && is_finite(vec.z);
}

/**
 * Gets whether a value is near zero.
 * @param val Floating-point value to check.
 * @return Whether value is close to zero.
 *
 * @note Test Cases:
 * near_zero(1.0f) -> false
 * near_zero(0.0f) -> true
 * near_zero(1e-8) -> false
 * near_zero(1e-9) -> true
 */
inline bool is_near_zero(const float val) {
    return std::fabs(val) <= 1e-9;
}

/**
 * Gets whether a vector is near zero.
 * @param vec Vector to check.
 * @return Whether vector is near zero.
 *
 * @note Test Cases:
 * near_zero(vec3(1, 1, 1)) -> false
 * near_zero(vec3(0, 0, 0)) -> true
 * near_zero(vec3(1e-8, 1e-8, 1e-8)) -> false
 * near_zero(vec3(1e-9, 1e-9, 1e-9)) -> true
 */
inline bool is_near_zero(const vec3 &vec) {
    return is_near_zero(vec.x) && is_near_zero(vec.y) && is_near_zero(vec.z);
}

/**
 * Gets whether two vectors are nearly equal.
 * @param vec1 First vector.
 * @param vec2 Second vector.
 * @return Whether the first and second vector are nearly equal to each other.
 *
 * @note Test Cases:
 * near_equal(vec3(0, 0, 0), vec3(1, 1, 1)) -> false
 * near_equal(vec3(1, 1, 1), vec3(1, 1, 1)) -> true
 * near_equal(vec3(0, 0, 0), vec3(1e-8, 1e-8, 1e-8)) -> false
 * near_equal(vec3(0, 0, 0), vec3(1e-9, 1e-9, 1e-9)) -> true
 */
inline bool is_near_equal(const vec3 &vec1, const vec3 &vec2) {
    return is_near_zero(vec2 - vec1);
}

/**
 * Gets whether a value is within the bounds of min and max.
 * @param val Value to check bounds of.
 * @param min Minimum bound.
 * @param max Maximum bound.
 * @return Whether val is between min and max.
 *
 * @note Test Cases:
 * is_inside_closed_range(1, 0, 2) -> true
 * is_inside_closed_range(0, 0, 2) -> true
 * is_inside_closed_range(2, 0, 2) -> true
 * NOTE: if min > max, return false.
 * NOTE: if any arguments non-finite, return false
 */
inline bool is_inside_closed_range(const float val, const float min, const float max) {
    bool is_inside = false;

    if (!is_finite(val) || !is_finite(min) || !is_finite(max)) {
        is_inside = false;
    } else if (min > max) {
        is_inside = false;
    } else if (min <= val && val <= max) {
        is_inside = true;
    }

    return is_inside;
}

/**
 * Gets whether all the components of a vector are within the bounds of min and max.
 * @param vec1 Vector to check bounds of.
 * @param min Minimum bound.
 * @param max Maximum bound.
 * @return Whether all the components of a vector are between min and max.
 *
 * @note Test Cases:
 * is_inside_closed_range(vec3(1, 1, 1), 0, 2) -> true
 * is_inside_closed_range(vec3(0, 0, 0), 0, 2) -> true
 * is_inside_closed_range(vec3(2, 2, 2), 0, 2) -> true
 * is_inside_closed_range(vec3(3, 3, 3), 0, 2) -> false
 * is_inside_closed_range(vec3(-1, -1, -1), 0, 2) -> false
 * NOTE: same conditions apply as previous definition
 */
inline bool is_inside_closed_range(const vec3 &vec1, const float min, const float max) {
    return  is_inside_closed_range(vec1.x, min, max) &&
            is_inside_closed_range(vec1.y, min, max) &&
            is_inside_closed_range(vec1.z, min, max);
}

/**
 * Converts linear color space to gamma corrected color space.
 *
 * @param linear_component Color component to be gamma corrected.
 * @return Gamma corrected color component.
 */
inline float linear_to_gamma(float linear_component) {
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
inline float degrees_to_radians(float degrees) {
    return degrees * 3.1415926535897932385 / 180.0;
}

/**
 * Gets a random float in [0, 1).
 *
 * @return Random float in [0, 1).
 */
inline float random_float() {
    return std::rand() / (RAND_MAX + 1.0);
}

/**
 * Gets a random number between a minimum and maximum.
 *
 * @param min Minimum number.
 * @param max Maximum number.
 * @return Random number between the minimum and maximum.
 */
inline float random_float(float min, float max) {
    // Returns a random real in [min,max).
    return min + (max - min) * random_float();
}

/**
 * Returns a random integer between min and max.
 * @param min Minimum integer.
 * @param max Maximum integer.
 * @return Random integer between min and max.
 */
inline int random_int(int min, int max) {
    return static_cast<int>(random_float(min, max + 1));
}

/**
 * Gets a random vector in [0, 1)^3
 *
 * @return Component randomized 3D vector.
 */
static vec3 random_vec3() {
    return {random_float(), random_float(), random_float()};
}

/**
 * Gets a random vector in [min, max)^3
 * @param min Minimum number.
 * @param max Maximum number.
 * @return Component randomized 3D vector.
 */
static vec3 random_vec3(float min, float max) {
    return {random_float(min, max), random_float(min, max), random_float(min, max)};
}

/**
 * Gets a random unit vector.
 *
 * @return Normalized random unit vector.
 */
inline vec3 random_unit_vector() {
    while (true) {
        auto p = random_vec3(-1, 1);
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
inline vec3 random_on_hemisphere(const vec3 &normal) {
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
inline vec3 random_in_unit_disk() {
    while (true) {
        auto p = vec3(random_float(-1, 1), random_float(-1, 1), 0);
        if (length2(p) < 1)
            return p;
    }
}

/**
 * Gets a random point on the unit square, centered at (0, 0).
 * @return Random point on the unit square.
 */
[[nodiscard]] static vec3 sampleSquare() {
    return {random_float() - 0.5, random_float() - 0.5, 0};
}

// Common custom headers
#include <Utils/Exceptions.h>
#include <Utils/Ray.h>
#include <Utils/Color.h>

#endif //HEADERS_H
