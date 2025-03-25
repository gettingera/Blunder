#ifndef HITTABLELIST_H
#define HITTABLELIST_H


#include <vector>
#include "Hittable.h"


class HittableList final : public Hittable {
public:
    // Constructors
    HittableList() = default;

    // Methods
    void Add(const shared_ptr<Hittable> &object) {
        objects.push_back(object);
    }

    void Clear() {
        objects.clear();
    }

    // Override
    bool Hit(const Ray &ray, const Interval &rayTime, HitRecord &record) const override {
        HitRecord tempRecord{};
        bool hitAny = false;
        auto closestSoFar = rayTime.max;

        for (const auto &object: objects) {
            if (object->Hit(ray, Interval(rayTime.min, closestSoFar), tempRecord)) {
                hitAny = true;
                closestSoFar = tempRecord.get_time();
                record = tempRecord;
            }
        }

        return hitAny;
    }

private:
    // Attributes
    std::vector<shared_ptr<Hittable> > objects;
};


#endif //HITTABLELIST_H
