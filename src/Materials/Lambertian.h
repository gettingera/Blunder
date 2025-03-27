#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H


/**
 * Lambertian material.
 *
 * Useful for giving objects a matte appearance.
 */
class Lambertian final : public Material {
    /// Color.
    dvec3 color{};

public:
    // Constructors
    /**
     * Makes a new lambertian material.
     * @param color Color.
     */
    explicit Lambertian(const dvec3 &color) {
        set_color(color);
    }

    // Methods
    bool Scatter(const Ray &rayIn, const HitRecord &record, dvec3 &attenuation, Ray &scattered) const override {
        dvec3 direction = record.get_normal() + random_unit_vector();

        // Fix possible bug
        if (near_zero(direction))
            direction = record.get_normal();

        scattered = Ray(record.get_point(), direction);
        attenuation = color;

        return true;
    }

    // Getters
    /**
     * Gets color.
     * @return Color
     */
    [[nodiscard]] dvec3 get_color() const {
        return color;
    }

    // Setters
    /**
     * Sets color.
     *
     * @param color Color.
     */
    void set_color(const dvec3 &color) {
        this->color = color;
    }
};


#endif //LAMBERTIAN_H
