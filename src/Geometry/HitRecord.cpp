#include "HitRecord.h"

void HitRecord::set_point(const vec3 &point) {
    // Ensure point is finite
    if (!is_finite(point))
        throw HitRecordException("HitRecord::set_point(): point should be finite");

    // Set point
    this->point = point;
}

void HitRecord::set_normal(const vec3 &normal) {
    // Ensure normal is finite
    if (!is_finite(normal))
        throw HitRecordException("HitRecord::set_normal(): normal should be finite");

    // Ensure normal is not zero
    if (is_near_zero(normal))
        throw HitRecordException("HitRecord::set_normal(): normal should not be zero");

    // Set normal
    this->normal = normalize(normal);
}

void HitRecord::set_color(const Color &color) {
    // Nothing to check, Color is already checked
    this->color = color;
}

void HitRecord::set_t(const float t) {
    // Ensure t is finite
    if (!is_finite(t))
        throw HitRecordException("HitRecord::set_t(): t should be finite");

    // Ensure t is non-negative
    if (t < 0)
        throw HitRecordException("HitRecord::set_t(): t should not be negative");

    // Set t
    this->t = t;
}
