#ifndef METAL_H
#define METAL_H


/**
 * Metal material.
 *
 * Useful for giving objects a distinctive metal appearance.
 */
class Metal final : public Material {
    /// Color.
    dvec3 color{};

    /// Roughness.
    double roughness{};

public:
    // Constructors
    /**
     * Makes a new metal material.
     *
     * @param color Color.
     * @param roughness Roughness.
     */
    Metal(const dvec3 &color, const double &roughness) {
        set_color(color);
        set_roughness(roughness);
    }

    // Methods
    bool Scatter(const Ray &rayIn, const HitRecord &record, dvec3 &attenuation, Ray &scattered) const override {
        dvec3 reflected = reflect(rayIn.get_direction(), record.get_normal());
        reflected = normalize(reflected) + roughness * random_unit_vector();
        scattered = Ray(record.get_point(), reflected);
        attenuation = color;
        return dot(scattered.get_direction(), record.get_normal()) > 0;
    }

    // Getters
    /**
     * Gets color.
     *
     * @return Color.
     */
    [[nodiscard]] dvec3 get_color() const {
        return color;
    }

    /**
     * Gets roughness.
     *
     * @return Roughness.
     */
    [[nodiscard]] double get_roughness() const {
        return roughness;
    }

    // Setters
    /**
     * Sets color.
     * @param color Color.
     */
    void set_color(const dvec3 &color) {
        this->color = color;
    }

    /**
     * Sets roughness.
     * 
     * @param roughness Roughness.
     */
    void set_roughness(const double roughness) {
        this->roughness = roughness;
    }
};


#endif //METAL_H
