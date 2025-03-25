#ifndef HITTABLELIST_H
#define HITTABLELIST_H


#include <vector>
#include <memory>
#include "Hittable.h"


class HittableList : public Hittable {
  public:
    // Constructors
    HittableList() {}

    HittableList(std::shared_ptr<Hittable> object) {
      this->Add(object);
    }

    // Methods
    void Clear() {
      this->objects.clear();
    }

    void Add(std::shared_ptr<Hittable> object) {
      this->objects.push_back(object);
    }

    // Override
    bool Hit(const Ray& ray, double timeMin, double timeMax, HitRecord& record) const override {
      HitRecord tempRecord;
      bool hitAny = false;
      auto closestSoFar = timeMax;

      for (auto object : this->objects) {
        if (object->Hit(ray, timeMin, closestSoFar, tempRecord)) {
          hitAny = true;
          closestSoFar = tempRecord.time;
          record = tempRecord;
        }
      }

      return hitAny;
    }

  private:
    // Attributes
    std::vector<std::shared_ptr<Hittable>> objects;
};


#endif //HITTABLELIST_H
