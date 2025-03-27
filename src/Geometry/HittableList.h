#ifndef HITTABLELIST_H
#define HITTABLELIST_H
#include <vector>
#include "Hittable.h"


/**
 * List for hittable objects.
 *
 * Use this list to store collections of hittable objects which can be queried by Hit().
 */
class HittableList final : public Hittable {
    /// List of pointers to hittable objects.
    std::vector<shared_ptr<Hittable> > objects;
public:
    // Constructors
    /**
     * Creates a new HittableList.
     */
    HittableList() = default;

    // Methods
    /**
     * Adds a hittable pointer to the list.
     * 
     * @param object Pointer of hittable to be added to the list.
     */
    void Add(const shared_ptr<Hittable> &object) {
        objects.push_back(object);
    }

    /**
     * Clears the list.
     */
    void Clear() {
        objects.clear();
    }

    // Override
    /**
     * Determines if ray intersects any objects in the list. Sets the hit record to the closest intersection.
     */
    bool Hit(const Ray &ray, const Interval &rayTime, HitRecord &record) const override {
        HitRecord tempRecord{};
        bool hitAny = false;
        auto closestSoFar = rayTime.get_max();

        for (const auto &object: objects) {
            if (object->Hit(ray, Interval(rayTime.get_min(), closestSoFar), tempRecord)) {
                hitAny = true;
                closestSoFar = tempRecord.get_time();
                record = tempRecord;
            }
        }

        return hitAny;
    }

    // Getters
    /**
     * Gets objects.
     *
     * @return List of pointers to hittable objects.
     */
    [[nodiscard]] std::vector<shared_ptr<Hittable>> get_objects() const {
        return objects;
    }

    // Setters
    /**
     * Sets objects.
     *
     * @param objects List of pointers to hittable objects.
     */
    void set_objects(const std::vector<shared_ptr<Hittable>> &objects) {
        this->objects = objects;
    }
};


#endif //HITTABLELIST_H
