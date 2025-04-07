#include "Headers.h"

bool is_finite(float val) {
    return std::isfinite(val);
}

bool is_finite(const vec3 &vec) {
    return is_finite(vec.x) && is_finite(vec.y) && is_finite(vec.z);
}

bool is_near_zero(float value) {
    // Finite check not required, inf, -inf, nan will not trigger issues

    // Return if value is near zero
    return std::fabs(value) <= 1e-9;
}

bool is_near_zero(const vec3 &vec) {
    return is_near_zero(vec.x) && is_near_zero(vec.y) && is_near_zero(vec.z);
}

bool is_near_equal(const vec3 &v1, const vec3 &v2) {
    return is_near_zero(v2 - v1);
}

bool is_inside_closed_range(float val, float min, float max) {
    // Ensure value is finite
    if (!is_finite(val))
        throw HeaderException("Headers -> is_inside_closed_range(): value is not finite");

    // Ensure min is finite
    if (!is_finite(min))
        throw HeaderException("Headers -> is_inside_closed_range(): min is not finite");

    // Ensure max is finite
    if (!is_finite(max))
        throw HeaderException("Headers -> is_inside_closed_range(): max is not finite");

    // Calculate results
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

bool is_inside_closed_range(const vec3 &vec1, float min, float max) {
    // Min, max finite-ness checked by is_inside_closed_range(float, float, float) function overload
    return is_inside_closed_range(vec1.x, min, max) &&
           is_inside_closed_range(vec1.y, min, max) &&
           is_inside_closed_range(vec1.z, min, max);
}

float linear_to_gamma(float linear_component) {
    // Ensure linear_component is finite
    if (!is_finite(linear_component))
        throw HeaderException("Headers -> linear_to_gamma(): linear_component is not finite");

    // Ensure linear_component is greater than or equal to zero
    if (linear_component < 0)
        throw HeaderException("Headers -> linear_to_gamma(): linear_component is negative");

    // Calculate result
    return std::sqrt(linear_component);
}

float degrees_to_radians(float degrees) {
    // Ensure degrees is finite
    if (!is_finite(degrees))
        throw HeaderException("Headers -> degrees_to_radians(): degrees is not finite");

    // Calculate results
    return degrees * 3.14159265f / 180.0f;
}

float random_float() {
    // Calculate result
    return static_cast<float>(std::rand()) / (RAND_MAX + 1.0f);
}

float random_float(float min, float max) {
    // Ensure min is finite
    if (!is_finite(min))
        throw HeaderException("Headers -> random_float(): min is not finite");

    // Ensure max is finite
    if (!is_finite(max))
        throw HeaderException("Headers -> random_float(): max is not finite");

    // Ensure min is lesser than max
    if (min >= max)
        throw HeaderException("Headers -> random_float(): min should be lesser than max");

    // Returns a random real in [min,max).
    return min + (max - min) * random_float();
}

vec3 random_vec3() {
    return {random_float(), random_float(), random_float()};
}

vec3 random_vec3(float min, float max) {
    // Finite-ness, min < max validity checked in random_float(float, float) function overload
    return {random_float(min, max), random_float(min, max), random_float(min, max)};
}

vec3 random_unit_vector() {
    while (true) {
        vec3 v = random_vec3(-1.0f, 1.0f);
        float len = length(v);
        if (len > 1e-6f) {
            // Avoid division by near-zero
            vec3 n = normalize(v);
            if (abs(length(n) - 1.0f) <= 1e-9f)
                return n;
        }
    }
}


vec3 sampleSquare() {
    return {random_float() - 0.5, random_float() - 0.5, 0};
}
