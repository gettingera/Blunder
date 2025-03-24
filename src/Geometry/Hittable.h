#ifndef HITTABLE_H
#define HITTABLE_H


#include "Utils/Ray.h"
#include "Geometry/HitRecord.h"


class Hittable {
  public:
    // Constructor
    virtual bool Hit(const Ray& ray, double time_min, double time_max, HitRecord& record) const = 0;
};



#endif //HITTABLE_H
