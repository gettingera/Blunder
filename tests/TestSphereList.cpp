#include <Utils/Headers.h>
#include <Geometry/SphereList.h>
#include <Geometry/Sphere.h>

namespace {
    void TestSphereList() {
        std::cout << "\t[SphereList] Testing SphereList..." << std::endl;
        auto s1 = make_shared<Sphere>(vec3(0, 0, 0), 1, Color(1, 1, 1));

        const auto spheres = make_shared<SphereList>();

        spheres->Add(s1);

    }


    void TestSphereListAll() {
        std::cout << "[Unit Testing] Testing SphereList..." << std::endl;
        TestSphereList();
    }
}
