#ifndef HITTABLE_H
#define HITTABLE_H
#include "Geometry/HitRecord.h"
#include "AABB.h"


/**
 * Abstract class for defining objects that rays can intersect.
 *
 * Useful for defining custom geometries and behavior.
 */
class Hittable {
public:
    // Methods
    /**
     * Virtual function to determine whether a ray intersects the hittable. Results stored in the HitRecord.
     *
     * @param ray Ray to query if it intersects the hittable.
     * @param rayTime Interval of which the ray is defined. (What part of the ray is intersection detected for)
     * @param record HitRecord reference updated by ray-hittable intersection.
     * @return Boolean whether ray intersects the hittable.
     */
    virtual bool Hit(const Ray &ray, const Interval &rayTime, HitRecord &record) const = 0;

    /**
     * 
     * @return AABB surrounding the hittable.
     */
    [[nodiscard]] virtual AABB BoundingBox() const = 0;

    // Destructor
    virtual ~Hittable() = default;
};


#endif //HITTABLE_H
