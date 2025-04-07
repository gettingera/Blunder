#ifndef HEADERS_H
#define HEADERS_H
#define GLM_ENABLE_EXPERIMENTAL
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

// Exceptions
#include <Utils/Exceptions.h>

// Constants
/// Infinity.
constexpr float infinity = std::numeric_limits<float>::infinity();

// Utility Functions
/**
 * Gets whether a value is finite.
 * @param val Value to check.
 * @return Whether val is finite valued.
 *
 * @note Test Cases:\n
 * constexpr float infinity = std::numeric_limits<float>::infinity()\n
 * is_finite(0) -> true\n
 * is_finite(infinity) -> false\n
 * is_finite(-infinity) -> false\n
 * is_finite(NAN) -> false\n
 */
bool is_finite(float val);

/**
 * Gets whether a vector is finite.
 * @param vec Vector to check.
 * @return Whether all components of the vector are finite valued.
 *
 * Test Cases:\n
 * constexpr float infinity = std::numeric_limits<float>::infinity()\n
 * is_finite(vec3(0, 0, 0)) -> true\n
 * is_finite(vec3(infinity, infinity, infinity)) -> false\n
 * is_finite(vec3(-infinity, -infinity, -infinity)) -> false\n
 * is_finite(vec3(NAN, NAN, NAN)) -> false\n
 */
bool is_finite(const vec3 &vec);

/**
 * Gets whether a value is near zero.
 * @param value Floating-point value to check.
 * @return Whether value is close to zero.
 *
 * @note Test Cases:\n
 * is_near_zero(1.0f) -> false\n
 * is_near_zero(0.0f) -> true\n
 * is_near_zero(1e-8) -> false\n
 * is_near_zero(1e-9) -> true\n
 */
bool is_near_zero(float value);

/**
 * Gets whether a vector is near zero.
 * @param vec Vector to check.
 * @return Whether vector is near zero.
 *
 * @note Test Cases:\n
 * is_near_zero(vec3(1, 1, 1)) -> false\n
 * is_near_zero(vec3(0, 0, 0)) -> true\n
 * is_near_zero(vec3(1e-8, 1e-8, 1e-8)) -> false\n
 * is_near_zero(vec3(1e-9, 1e-9, 1e-9)) -> true\n
 */
bool is_near_zero(const vec3 &vec);

/**
 * Gets whether two vectors are nearly equal.
 * @param v1 First vector.
 * @param v2 Second vector.
 * @return Whether the first and second vector are nearly equal to each other.
 *
 * @note Test Cases:\n
 * near_equal(vec3(0, 0, 0), vec3(1, 1, 1)) -> false\n
 * near_equal(vec3(1, 1, 1), vec3(1, 1, 1)) -> true\n
 * near_equal(vec3(0, 0, 0), vec3(1e-8, 1e-8, 1e-8)) -> false\n
 * near_equal(vec3(0, 0, 0), vec3(1e-9, 1e-9, 1e-9)) -> true\n
 */
bool is_near_equal(const vec3 &v1, const vec3 &v2);

/**
 * Gets whether a value is within the bounds of min and max.
 * @param val Value to check bounds of.
 * @param min Minimum bound.
 * @param max Maximum bound.
 * @return Whether val is between min and max.
 *
 * @note Test Cases:\n
 * is_inside_closed_range(1, 0, 2) -> true\n
 * is_inside_closed_range(0, 0, 2) -> true\n
 * is_inside_closed_range(2, 0, 2) -> true\n
 * NOTE: if min > max, return false.\n
 * NOTE: if any arguments non-finite, error\n
 */
bool is_inside_closed_range(float val, float min, float max);

/**
 * Gets whether all the components of a vector are within the bounds of min and max.
 * @param vec1 Vector to check bounds of.
 * @param min Minimum bound.
 * @param max Maximum bound.
 * @return Whether all the components of a vector are between min and max.
 *
 * @note Test Cases:\n
 * is_inside_closed_range(vec3(1, 1, 1), 0, 2) -> true\n
 * is_inside_closed_range(vec3(0, 0, 0), 0, 2) -> true\n
 * is_inside_closed_range(vec3(2, 2, 2), 0, 2) -> true\n
 * is_inside_closed_range(vec3(3, 3, 3), 0, 2) -> false\n
 * is_inside_closed_range(vec3(-1, -1, -1), 0, 2) -> false\n
 * NOTE: same conditions apply as previous definition\n
 */
bool is_inside_closed_range(const vec3 &vec1, float min, float max);

/**
 * Converts linear color space to gamma corrected color space.
 * @param linear_component Color component to be gamma corrected.
 * @return Gamma corrected color component.
 *
 * @note Test Cases:\n
 * linear_to_gamma(1.0) -> should return 1.0\n
 * linear_to_gamma(0.25) -> should return 0.5\n
 * linear_to_gamma(0) -> should return 0.0\n
 * linear_to_gamma(-1) -> ERROR: will throw a HeaderException (linear component cannot be negative)\n
 */
float linear_to_gamma(float linear_component);

/**
 * Converts an angle in degrees to an angle in radians.
 * @param degrees Angle in degrees.
 * @return Angle in radians.
 *
 * @note Test Cases:\n
 * degrees_to_radians(0) -> should return 0\n
 */
float degrees_to_radians(float degrees);

/**
 * Gets a random float in [0, 1).
 * @return Random float in [0, 1).
 *
 * @note Test Cases:\n
 * random_float() -> should be between 0 and 1\n
 */
float random_float();

/**
 * Gets a random number between a minimum and maximum.
 * @param min Minimum number.
 * @param max Maximum number.
 * @return Random number between the minimum and maximum.
 *
 * @note Test Cases:\n
 * random_float(0, 1) -> should be between 0 and 1\n
 * random_float(1, 1) -> ERROR: will return a HeaderException(min must be lesser than max)\n
 * random_float(2, 1) -> ERROR: will return a HeaderException(min must be lesser than max)\n
 */
float random_float(float min, float max);

/**
 * Gets a random vector in [0, 1)^3
 * @return Component randomized 3D vector.
 *
 * @note Test Cases:\n
 * random_vec3() -> all components should be between 0 and 1\n
 */
vec3 random_vec3();

/**
 * Gets a random vector in [min, max)^3
 * @param min Minimum number.
 * @param max Maximum number.
 * @return Component randomized 3D vector.
 *
 * @note Test Cases:\n
 * random_vec3(0, 1) -> all components should be between 0 and 1\n
 * random_vec3(1, 1) -> ERROR: will return a HeaderException(min must be lesser than max)\n
 * random_vec3(2, 1) -> ERROR: will return a HeaderException(min must be lesser than max)\n
 */
vec3 random_vec3(float min, float max);

/**
 * Gets a random unit vector.
 * @return Normalized random unit vector.
 *
 * @note Test Cases:\n
 * random_unit_vector() -> length(random_unit_vector) should be nearly 1\n
 */
vec3 random_unit_vector();

/**
 * Gets a random point on the unit square, centered at (0, 0).
 * @return Random point on the unit square.
 *
 * @note Test Cases:\n
 * sampleSquare() -> first, second components should be between -0.5 and 0.5. last component is always 0\n
 */
vec3 sampleSquare();

// Common custom headers
#include <Utils/Ray.h>
#include <Utils/Color.h>

#endif //HEADERS_H
