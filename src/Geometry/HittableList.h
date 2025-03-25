#ifndef HITTABLELIST_H
#define HITTABLELIST_H


#include <vector>
#include "Hittable.h"


class HittableList : public Hittable {
public:
    // Constructors
    HittableList() = default;

    HittableList(const std::shared_ptr<Hittable> &object) {
        this->Add(object);
    }

    // Methods
    void Clear() {
        this->objects.clear();
    }

    void Add(const std::shared_ptr<Hittable>& object) {
        this->objects.push_back(object);
    }

    // Override
    bool Hit(const Ray &ray, Interval rayTime, HitRecord &record) const override {
        HitRecord tempRecord;
        bool hitAny = false;
        auto closestSoFar = rayTime.max;

        for (auto object: this->objects) {
            if (object->Hit(ray, Interval(rayTime.min, closestSoFar), tempRecord)) {
                hitAny = true;
                closestSoFar = tempRecord.time;
                record = tempRecord;
            }
        }

        return hitAny;
    }

private:
    // Attributes
    std::vector<std::shared_ptr<Hittable> > objects;
};


#endif //HITTABLELIST_H
