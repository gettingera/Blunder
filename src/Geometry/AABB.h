#ifndef AABB_H
#define AABB_H
#include "../Utils/Interval.h"
#include "../../lib/glm/glm/vec3.hpp"


class AABB {
    /// Axis-aligned x interval
    Interval x;

    /// Axis-aligned y interval
    Interval y;

    /// Axis-aligned z interval
    Interval z;

public:
    // Constructors
    AABB() = default;

    /**
     * Constructs an AABB from three axis-aligned intervals.
     *
     * @param x x axis interval.
     * @param y y axis interval.
     * @param z z axis interval.
     */
    AABB(const Interval& x, const Interval& y, const Interval& z) {
        set_x(x);
        set_y(y);
        set_z(z);
    }

    /**
     * Constructs an AABB from two opposing corners of a bounding box.
     * @param a Corner point of the bounding box.
     * @param b Opposite corner point of the bounding box.
     */
    AABB(const dvec3 &a, const dvec3 &b) {
        set_x(a.x < b.x ? Interval(a.x, b.x) : Interval(b.x, a.x));
        set_y(a.y < b.y ? Interval(a.y, b.y) : Interval(b.y, a.y));
        set_z(a.z < b.z ? Interval(a.z, b.z) : Interval(b.z, a.z));
    }

    AABB(const AABB &a, const AABB &b) {
        set_x(Interval(a.get_x(), b.get_x()));
        set_y(Interval(a.get_y(), b.get_y()));
        set_z(Interval(a.get_z(), b.get_z()));
    }

    // Methods
    /**
     * Selects an axis based on an interger input.
     *
     * @param n Alternating axis.
     * @return Axis corresponding to n.
     */
    [[nodiscard]] Interval AxisInterval(const int n) const {
        Interval ret = get_x();
        if (n == 1)
            ret = get_y();
        if (n == 2)
            ret = get_z();
        return ret;
    }

    [[nodiscard]] int LongestAxis() const {
        if (get_x().size() > get_y().size())
            return get_x().size() > get_z().size() ? 0 : 2;
        return get_y().size() > get_z().size() ? 1 : 2;
    }

    bool Hit(const Ray &ray, Interval rayTime) const {
        const dvec3 &rayOrigin = ray.get_origin();
        const dvec3 &rayDirection = ray.get_direction();

        for (int axis = 0; axis < 3; axis++) {
            const Interval &ax = AxisInterval(axis);
            const double adInv = 1 / rayDirection[axis];

            auto t0 = (ax.get_min() - rayOrigin[axis]) * adInv;
            auto t1 = (ax.get_max() - rayOrigin[axis]) * adInv;

            if (t0 < t1) {
                if (t0 > rayTime.get_min())
                    rayTime.set_min(t0);
                if (t1 < rayTime.get_max())
                    rayTime.set_max(t1);
            } else {
                if (t1 > rayTime.get_min())
                    rayTime.set_min(t1);
                if (t0 < rayTime.get_max())
                    rayTime.set_max(t0);
            }

            if (rayTime.get_max() < rayTime.get_min())
                return false;
        }

        return true;
    }

    // Getters
    [[nodiscard]] Interval get_x() const {
        return x;
    }

    [[nodiscard]] Interval get_y() const {
        return y;
    }

    [[nodiscard]] Interval get_z() const {
        return z;
    }

    // Setters
    void set_x(const Interval &x) {
        this->x = x;
    }

    void set_y(const Interval &y) {
        this->y = y;
    }

    void set_z(const Interval &z) {
        this->z = z;
    }

    // Static constants
    static const AABB empty;
    static const AABB universe;
};


const AABB AABB::empty = AABB(Interval::empty, Interval::empty, Interval::empty);
const AABB AABB::universe = AABB(Interval::universe, Interval::universe, Interval::universe);


#endif //AABB_H
