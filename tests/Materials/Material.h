#ifndef MATERIAL_H
#define MATERIAL_H
#include "Geometry/Hittable.h"


/**
 * Abstract material class for defining ray scattering behavior.
 *
 * Useful for implementing any kinds of physically based materials.
 */
class Material {
public:
    /**
     * Virtual scatter function to scatter incoming light.
     *
     * @param rayIn Incoming ray.
     * @param record Hit record of incoming intersection.
     * @param attenuation Color of the material.
     * @param scattered Where the next ray will go.
     * @return Whether ray scattered or not.
     */
    virtual bool Scatter(const Ray &rayIn, const HitRecord &record, dvec3 &attenuation, Ray &scattered) const {
        return false;
    }

    // Destructor
    virtual ~Material() = default;
};


// Include other materials now
#include "Lambertian.h"
#include "Metal.h"
#include "Dielectric.h"


#endif //MATERIAL_H
