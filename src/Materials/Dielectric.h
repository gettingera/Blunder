#ifndef DIELECTRIC_H
#define DIELECTRIC_H


class Dielectric : public Material {
public:
    // Constructors
    Dielectric(const double &index_of_refraction) {
        set_index_of_refraction(index_of_refraction);
    }

    // Methods
    bool Scatter(const Ray &rayIn, const HitRecord &record, dvec3 &attenuation, Ray &scattered) const override {
        attenuation = dvec3(1.0);
        double ri = record.is_front_face() ? (1.0 / get_index_of_refraction()) : get_index_of_refraction();

        dvec3 unit_direction = normalize(rayIn.Direction());
        double cos_theta = std::fmin(dot(-unit_direction, record.get_normal()), 1.0);
        double sin_theta = std::sqrt(1.0 - cos_theta * cos_theta);

        bool cannot_refract = ri * sin_theta > 1.0;
        vec3 direction;

        if (cannot_refract || reflectance(cos_theta, ri) > random_double())
            direction = reflect(unit_direction, record.get_normal());
        else
            direction = refract(unit_direction, record.get_normal(), ri);

        scattered = Ray(record.get_point(), direction);
        return true;
    }

    // Getters
    [[nodiscard]] double get_index_of_refraction() const {
        return index_of_refraction;
    }

    // Setters
    void set_index_of_refraction(const double index_of_refraction) {
        this->index_of_refraction = index_of_refraction;
    }

private:
    // Attributes
    double index_of_refraction;

    // Private methods
    static double reflectance(double cosine, double refraction_index) {
        // Use Schlick's approximation for reflectance.
        auto r0 = (1 - refraction_index) / (1 + refraction_index);
        r0 = r0 * r0;
        return r0 + (1 - r0) * std::pow((1 - cosine), 5);
    }
};


#endif //DIELECTRIC_H
