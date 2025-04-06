#include <Utils/Headers.h>
#include <Utils/Ray.h>

namespace {
    void TestRayConstructor() {
        std::cout << "\t[Ray] Testing Constructor..." << std::endl;
        auto r1 = Ray(vec3(0), vec3(1));
        assert(r1.get_position() == vec3(0));
        assert(r1.get_direction() == vec3(1));

        try {
            auto r2 = Ray(vec3(1), vec3(0));
            assert(false);
        } catch (RayException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestRayAt() {
        std::cout << "\t[Ray] Testing at..." << std::endl;
        auto r1 = Ray(vec3(0), vec3(1));
        assert(r1.at(0) == r1.get_position());
        assert(r1.at(1) == r1.get_position() + r1.get_direction());

        try {
            auto _ = r1.at(infinity);
            assert(false);
        } catch (RayException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestRaySetPosition() {
        std::cout << "\t[Ray] Testing set_position..." << std::endl;
        auto r1 = Ray(vec3(0), vec3(1));
        r1.set_position(vec3(1));
        assert(r1.get_position() == vec3(1));
    }

    void TestRaySetDirection() {
        std::cout << "\t[Ray] Testing set_direction..." << std::endl;
        auto r1 = Ray(vec3(0), vec3(1));
        r1.set_direction(vec3(2));
        assert(r1.get_direction() == vec3(2));

        try {
            r1.set_direction(vec3(0));
            assert(false);
        } catch (RayException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestRayAll() {
        std::cout << "[Unit Testing] Testing Ray..." << std::endl;
        TestRayConstructor();
        TestRayAt();
        TestRaySetPosition();
        TestRaySetDirection();
    }
}