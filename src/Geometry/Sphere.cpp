#include "Sphere.h"

Sphere::Sphere(const vec3 &position, const float radius, const Color &color) {
    set_position(position);
    set_radius(radius);
    set_color(color);
}

bool Sphere::Hit(const Ray &ray, const float tStart, const float tEnd, HitRecord &hitRecord) const {
    // Ensure tStart is finite
    if (!is_finite(tStart))
        throw SphereException("Sphere::Hit(): tStart should be finite");

    // Ensure tEnd is finite
    if (!is_finite(tEnd))
        throw SphereException("Sphere::Hit(): tEnd should be finite");

    // Ensure tStart is lesser than tEnd
    if (tStart >= tEnd)
        throw SphereException("Sphere::Hit(): tStart should be lesser than tEnd");

    // Ensure tStart, tEnd greater than zero
    if (tStart < 0)
        throw SphereException("Sphere::Hit(): tStart (and possibly tEnd) should not be negative");

    // BEGIN CALCULATION CODE
    vec3 oc = ray.get_position() - get_position();
    auto a = length2(ray.get_direction());
    auto h = dot(ray.get_direction(), oc);
    auto c = length2(oc) - get_radius() * get_radius();

    auto discriminant = h * h - a * c;
    if (discriminant < 0)
        return false;

    auto sqrtd = std::sqrt(discriminant);

    auto root = (-h - sqrtd) / a;
    if (root < tStart || root > tEnd) {
        root = (-h + sqrtd) / a;
        if (root < tStart || root > tEnd)
            return false;
    }
    // END CALCULATION CODE

    // HitRecord logging
    hitRecord.set_t(root);
    hitRecord.set_point(ray.at(root));
    const dvec3 outward_normal = (hitRecord.get_point() - get_position()) / get_radius();
    hitRecord.set_normal(outward_normal);
    hitRecord.set_color(get_color());

    // Return true
    return true;
}

void Sphere::set_position(const vec3 &position) {
    // Ensure position is finite
    if (!is_finite(position))
        throw SphereException("Sphere::set_position(): position should be finite");

    // Set position
    this->position = position;
}

void Sphere::set_radius(const float radius) {
    // Ensure radius is finite
    if (!is_finite(radius))
        throw SphereException("Sphere::set_radius(): radius should be finite");

    // Ensure radius is positive
    if (radius <= 0)
        throw SphereException("Sphere::set_radius(): radius should be greater than zero");

    this->radius = radius;
}

void Sphere::set_color(const Color &color) {
    // All checking is done in Color
    this->color = color;
}
