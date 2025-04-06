#include <Utils/Headers.h>
#include <Geometry/Sphere.h>

namespace {

    void TestSphereHit() {
        std::cout << "\t[Sphere] Testing Sphere Hit..." << std::endl;
        auto s1 = Sphere(vec3(0, 0, 0), 1, Color(1, 1, 1));
        auto ray = Ray(vec3(0, -1, 0), vec3(0, 1, 0));
        auto hitRecord = HitRecord();
        assert(s1.Hit(ray, 0, 100000, hitRecord) == true);

        try {
            s1.Hit(ray, 0, 100000, hitRecord);
            s1.Hit(ray, -infinity, infinity, hitRecord);
            assert(false);
        } catch (SphereException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestSphereSetPosition() {
        std::cout << "\t[Sphere] Testing SetPosition..." << std::endl;
        auto s1 = Sphere(vec3(0, 0, 0), 1, Color(1, 1, 1));
        s1.set_position(vec3(1, 1, 1));
        assert(s1.get_position() == vec3(1, 1, 1));

        try {
            s1.set_position(vec3(infinity, infinity, infinity));
            assert(false);
        } catch (SphereException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestSphereSetRadius() {
        std::cout << "\t[Sphere] Testing SetRadius..." << std::endl;
        auto s1 = Sphere(vec3(0, 0, 0), 1, Color(1, 1, 1));
        s1.set_radius(1);
        assert(s1.get_radius() == 1);

        try {
            s1.set_radius(0);
            s1.set_radius(-1);
            s1.set_radius(infinity);
            assert(false);
        } catch (SphereException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestSphereSetColor() {
        std::cout << "\t[Sphere] Testing SetColor..." << std::endl;
        auto s1 = Sphere(vec3(0, 0, 0), 10, Color(1, 1, 1));
        s1.set_color(Color(0.5, 0.5, 0.5));
        assert(s1.get_color().get_color() == Color(0.5, 0.5, 0.5).get_color());

        try {
            s1.set_color(Color(2, 2, 2));
            assert(false);
        } catch (ColorException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestSphereAll() {
        std::cout << "[Unit Testing] Testing Sphere..." << std::endl;
        TestSphereHit();
        TestSphereSetPosition();
        TestSphereSetRadius();
        TestSphereSetColor();
    }
}