#include "HitRecord.h"

void HitRecord::set_point(const vec3 &point) {
    // Ensure point is finite
    if (!is_finite(point))
        throw HitRecordException("HitRecord::set_point(): point is not finite");

    // Set point
    this->point = point;
}

void HitRecord::set_normal(const vec3 &normal) {
    // Ensure normal is finite
    if (!is_finite(normal))
        throw HitRecordException("HitRecord::set_normal(): normal is not finite");

    // Ensure normal is not zero
    if (is_near_zero(normal))
        throw HitRecordException("HitRecord::set_normal(): normal is zero");

    // Set normal
    this->normal = normalize(normal);
}

void HitRecord::set_color(const Color &color) {
    // Nothing to check, Color is already checked
    this->color = color;
}

void HitRecord::set_t(const double t) {
    // Ensure t is finite
    if (!is_finite(t))
        throw HitRecordException("HitRecord::set_t(): t is not finite");

    // NOTE: t being negative is almost always bad behavior but will research before actually disallowing it

    // Set t
    this->t = t;
}
