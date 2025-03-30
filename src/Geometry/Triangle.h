#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <complex>


/**
 * Triangle object.
 *
 * Use this to render perfectly triangular objects. This implementation relies on COUNTERCLOCKWISE WINDING ORDER.
 * This means for normals to appear correctly, vertices must be defined counterclockwise in the world.
 */
class Triangle final : public Hittable {
    /// Time dependent vertices that create the triangle.
    Ray a{};
    Ray b{};
    Ray c{};

    /// Pointer to the sphere material.
    shared_ptr<Material> material;

public:
    // Constructors
    /**
     * Creates a stationary triangle.
     * @param a First vertex of triangle.
     * @param b Second vertex of triangle.
     * @param c Third vertex of triangle.
     * @param material Material controlling how light will be scattered.
     */
    Triangle(const dvec3 &a, const dvec3 &b, const dvec3 &c, const shared_ptr<Material> &material) {
        set_a(Ray(a, dvec3(0)));
        set_b(Ray(b, dvec3(0)));
        set_c(Ray(c, dvec3(0)));
        set_material(material);
    }

    /**
     * Creates a moving triangle.
     * @param a Ray of movement for first vertex of triangle.
     * @param b Ray of movement for second vertex of triangle.
     * @param c Ray of movement for third vertex of triangle.
     * @param material Material controlling how light will be scattered.
     */
    Triangle(const Ray &a, const Ray &b, const Ray &c, const shared_ptr<Material> &material) {
        set_a(Ray(a.get_origin(), a.get_direction() - a.get_origin()));
        set_b(Ray(b.get_origin(), b.get_direction() - b.get_origin()));
        set_c(Ray(c.get_origin(), c.get_direction() - c.get_origin()));
        set_material(material);
    }

    // Methods, uses the Moller Trumbore triangle intersection algorithm
    bool Hit(const Ray &ray, const Interval &rayTime, HitRecord &record) const override {
        // Real direction
        dvec3 ray_direction = ray.get_direction();

        // Current vertex coordinates
        dvec3 curr_a = get_a().At(ray.get_time());
        dvec3 curr_b = get_b().At(ray.get_time());
        dvec3 curr_c = get_c().At(ray.get_time());

        // Make edges
        dvec3 edge1 = curr_b - curr_a;
        dvec3 edge2 = curr_c - curr_a;
        dvec3 ray_cross_edge2 = cross(ray_direction, edge2);
        double determinant = dot(edge1, ray_cross_edge2);

        // Determinant close to zero means nearly parallel
        if (near_zero(determinant))
            return false;

        double inverse_determinant = 1.0 / determinant;

        // Compute u
        dvec3 s = ray.get_origin() - curr_a;
        double u = inverse_determinant * dot(s, ray_cross_edge2);

        // If u is outside [0,1], the intersection is outside the triangle
        if (u < 0.0 || u > 1.0)
            return false;

        // Compute v
        dvec3 s_cross_edge1 = cross(s, edge1);
        double v = inverse_determinant * dot(ray_direction, s_cross_edge1);

        // If v is outside [0,1] or u+v > 1, the intersection is outside the triangle
        if (v < 0.0 || (u + v) > 1.0)
            return false;

        // At this point, it is intersecting the triangle. Determine if it is in front of or behind the ray origin
        double t = inverse_determinant * dot(edge2, s_cross_edge1);

        // Intersecting if t positive
        if (rayTime.surrounds(t)) {
            record.set_time(t);
            record.set_point(ray.At(t));
            record.SetFaceNormal(ray, normalize(cross(edge1, edge2)));
            record.set_material(get_material());

            // Triangle was intersected!
            return true;
        }

        // Is behind the camera, no viable intersection
        return false;
    }

    /**
     * Inverts the normals of the triangle by swapping vertices a and b, inverting the orientation.
     */
    void InvertNormals() {
        const Ray temp = get_a();
        set_a(get_b());
        set_b(temp);
    }

    // Getters
    /**
     * Gets the first vertex of the triangle.
     *
     * @return First vertex of the triangle.
     */
    [[nodiscard]] Ray get_a() const {
        return a;
    }

    /**
     * Gets the second vertex of the triangle.
     *
     * @return Second vertex of the triangle.
     */
    [[nodiscard]] Ray get_b() const {
        return b;
    }

    /**
     * Gets the third vertex of the triangle.
     *
     * @return third vertex of the triangle.
     */
    [[nodiscard]] Ray get_c() const {
        return c;
    }

    /**
     * Gets pointer to material.
     * @return Pointer to material.
     */
    [[nodiscard]] shared_ptr<Material> get_material() const {
        return material;
    }

    // Setters
    void set_a(const Ray &a) {
        this->a = a;
    }

    void set_b(const Ray &b) {
        this->b = b;
    }

    void set_c(const Ray &c) {
        this->c = c;
    }

    /**
     * Sets pointer to material.
     *
     * @param material Pointer to material.
     */
    void set_material(const shared_ptr<Material> &material) {
        this->material = material;
    }
};


#endif //TRIANGLE_H
