#ifndef SPHERELIST_H
#define SPHERELIST_H
#include <Utils/Headers.h>
#include <Geometry/Sphere.h>
#include <vector>

/**
 * List for spheres.
 * Use this list to store collections of sphere spheres which can be queried by Hit().
 */
class SphereList final {
    /// List of pointers to hittable spheres.
    std::vector<shared_ptr<Sphere> > spheres{};

public:
    // Constructors
    /**
     * Creates a new SphereList.
     */
    SphereList() = default;

    // Methods
    /**
     * Adds a sphere pointer to the list.
     * @param sphere Pointer of sphere to be added to the list.
     */
    void Add(const shared_ptr<Sphere> &sphere);

    // Methods
    /**
     * Determines whether the incoming ray intersects the sphere or not.
     * If so, record the information in hitRecord and return true.
     * @param ray Ray that could possibly be intersecting the sphere.
     * @param tStart Minimum t value to begin checking.
     * @param tEnd Maximum t value to finish checking.
     * @param hitRecord Hit information if the ray intersects the sphere.
     * @return True if ray intersects spheres and logs closest sphere intersection information in hitRecord.
     * False if there is no intersection between all the spheres in the list.
     *
     * @note Test Cases:\n
     * I know this looks scary: Here's what I would do.\n
     * Simply add your sphere from the previous test code to this list and make sure you still get the same result.\n
     * For advanced testing, set the pointer to nullptr and run it again. You should catch a SphereListException.\n
     */
    bool Hit(const Ray &ray, float tStart, float tEnd, HitRecord &hitRecord) const;
};


#endif //SPHERELIST_H
