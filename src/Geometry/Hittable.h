#ifndef HITTABLE_H
#define HITTABLE_H


#include "Geometry/HitRecord.h"


class Hittable {
public:
    // Constructor
    virtual bool Hit(const Ray &ray, Interval rayTime, HitRecord &record) const = 0;

    // Destructor
    virtual ~Hittable() = default;

};


#endif //HITTABLE_H
