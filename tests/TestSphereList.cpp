#include <Utils/Headers.h>
#include <Geometry/SphereList.h>
#include <Geometry/Sphere.h>

namespace BlunderTest {
    static void TestSphereList() {
        std::cout << "\t[SphereList] Testing SphereList..." << std::endl;
        auto s1 = make_shared<Sphere>(vec3(0, 0, 0), 1, Color(1, 1, 1));
        auto ray = Ray(vec3(0, -1, 0), vec3(0, 1, 0));
        auto hitRecord = HitRecord();
        const auto spheres = make_shared<SphereList>();
        spheres->Add(s1);

        assert(spheres->Hit(ray, 0, 10000, hitRecord) == true);

        try {
            spheres->Hit(ray, -infinity, infinity, hitRecord);
            assert(false);
        } catch (SphereListException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    static void TestSphereListAll() {
        std::cout << "[Unit Testing] Testing SphereList..." << std::endl;
        TestSphereList();
    }
}
