#include "Ray.h"

Ray::Ray(const vec3 &position, const vec3 &direction) {
    set_position(position);
    set_direction(direction);
}

vec3 Ray::at(const float t) const {
    // Ensure t is finite
    if (!is_finite(t)) {
        throw RayException("Ray::at(): t should be finite");
    }

    // Calculate result
    const auto result = get_position() + (t * get_direction());

    // Ensure result is finite before returning
    if (!is_finite(result)) {
        throw RayException("Ray::at(): result should be finite");
    }

    // Return result
    return result;
}

void Ray::set_position(const vec3 &position) {
    // Ensure position is finite
    if (!is_finite(position)) {
        throw RayException("Ray::set_position(): position should be finite");
    }

    // Set position
    this->position = position;
}

void Ray::set_direction(const vec3 &direction) {
    // Ensure direction is finite
    if (!is_finite(direction)) {
        throw RayException("Ray::set_direction(): direction should be finite");
    }

    // Ensure direction is not a zero vector
    if (is_near_zero(direction)) {
        throw RayException("Ray::set_direction(): direction should not be equal to zero");
    }

    // Set direction
    this->direction = direction;
}
