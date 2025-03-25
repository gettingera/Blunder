#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H


#include "Material.h"


class Lambertian final : public Material {
public:
    // Constructors
    Lambertian(const dvec3 &albedo) {
        set_albedo(albedo);
    }

    // Methods
    bool Scatter(const Ray &rayIn, const HitRecord &record, dvec3 &attenuation, Ray &scattered) const override {
        dvec3 direction = record.get_normal() + random_unit_vector();

        // Fix possible bug
        if (near_zero(direction))
            direction = record.get_normal();

        scattered = Ray(record.get_point(), direction);
        attenuation = albedo;

        return true;
    }

    // Getters
    [[nodiscard]] dvec3 get_albedo() const {
        return albedo;
    }

    // Setters
    void set_albedo(const dvec3 &albedo) {
        this->albedo = albedo;
    }

private:
    dvec3 albedo;
};


#endif //LAMBERTIAN_H
