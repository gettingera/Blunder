#ifndef MATERIAL_H
#define MATERIAL_H


#include "Geometry/Hittable.h"


class Material {
public:
    virtual ~Material() = default;

    virtual bool Scatter(const Ray &rayIn, const HitRecord &record, dvec3 &attenuation, Ray &scattered) const {
        return false;
    }
};


// Include other materials now
#include "Lambertian.h"
#include "Metal.h"
#include "Dielectric.h"


#endif //MATERIAL_H
