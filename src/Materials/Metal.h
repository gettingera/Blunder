#ifndef METAL_H
#define METAL_H
#include "Material.h"


class Metal : public Material {
public:
    // Constructors
    Metal(const dvec3 &albedo, const double &fuzz) {
        set_albedo(albedo);
        set_fuzz(fuzz);
    }

    // Methods
    bool Scatter(const Ray &rayIn, const HitRecord &record, dvec3 &attenuation, Ray &scattered) const override {
        dvec3 reflected = reflect(rayIn.Direction(), record.get_normal());
        reflected = normalize(reflected) + fuzz * random_unit_vector();
        scattered = Ray(record.get_point(), reflected);
        attenuation = albedo;
        return dot(scattered.Direction(), record.get_normal()) > 0;
    }

    // Getters
    [[nodiscard]] dvec3 get_albedo() const {
        return albedo;
    }

    [[nodiscard]] double get_fuzz() const {
        return fuzz;
    }

    // Setters
    void set_albedo(const dvec3 &albedo) {
        this->albedo = albedo;
    }

    void set_fuzz(const double fuzz) {
        this->fuzz = fuzz;
    }

private:
    dvec3 albedo;
    double fuzz;
};


#endif //METAL_H
