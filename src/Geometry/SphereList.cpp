#include "SphereList.h"

void SphereList::Add(const shared_ptr<Sphere> &sphere) {
    /*
     * I am not checking for nullptr here. Why?
     * It is common to add shared_ptrs initialized to nullptr before configuring the objects.
     * It is better to check in the intersection code anyway.
     * If any are left uninitialized, it can be reported then.
     * It also means anyone who changes a previously good sphere pointer to nullptr could circumvent this entire check.
    */

    // Add sphere pointer
    spheres.push_back(sphere);
}

bool SphereList::Hit(const Ray &ray, const float tStart, const float tEnd, HitRecord &record) const {
    // Ensure tStart is finite
    if (!is_finite(tStart))
        throw SphereListException("SphereList::Hit(): tStart is not finite");

    // Ensure tEnd is finite
    if (!is_finite(tEnd))
        throw SphereListException("SphereList::Hit(): tEnd is not finite");

    // Ensure tStart is lesser than tEnd
    if (tStart >= tEnd)
        throw SphereListException("SphereList::Hit(): tStart is greater than or equal to tEnd");

    // Ensure tStart, tEnd greater than zero
    if (tStart < 0)
        throw SphereListException("SphereList::Hit(): tStart (and possible tEnd) is negative");

    // Begin intersection code
    HitRecord tempRecord{};
    bool hitAny = false;
    auto closestSoFar = tEnd;

    for (const auto &sphere: spheres) {

        if (sphere == nullptr)
            throw SphereListException("SphereList::Hit(): sphere is nullptr, did you forget to initialize a sphere?");

        if (sphere->Hit(ray, tStart, closestSoFar, tempRecord)) {
            hitAny = true;
            closestSoFar = tempRecord.get_t();
            record = tempRecord;
        }
    }
    // End intersection code

    // Return if there are hits on any spheres
    return hitAny;
}
