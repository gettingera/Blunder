#include <Utils/Headers.h>
#include <Camera/Camera.h>

namespace {
    void TestCameraConstructor() {
        std::cout << "\t[Camera] Testing Constructor..." << std::endl;
        auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
        assert(c1.get_position() == vec3(0, 0, 0));
        assert(c1.get_look_at() == vec3(1, 1, 1));

        try {
            auto c1 = Camera(vec3(0, 0, 0), vec3(0, 0, 0));
            assert(false);
        } catch (CameraException &e) {
            assert(true);
        } catch (...) {
            assert(true);
        }
    }

    void TestCameraPosition() {
        std::cout << "\t[Camera] Testing Position..." << std::endl;
        auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
        assert(c1.get_position() == vec3(0, 0, 0));

        try {
            auto c2 = Camera(vec3(0, 0, 0), vec3(0, 0, 0));
            assert(false);
        } catch (CameraException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestCameraLookAt() {
        std::cout << "\t[Camera] Testing Look At..." << std::endl;
        auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
        assert(c1.get_look_at() == vec3(1, 1, 1));

        try {
            auto c2 = Camera(vec3(0, 0, 0), vec3(0, 0, 0));
            assert(false);
        } catch (CameraException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
      }

    void TestCameraSetPosition() {
        std::cout << "\t[Camera] Testing SetPosition..." << std::endl;
        auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
        c1.set_position(vec3(2, 2, 2));
        assert(c1.get_position() == vec3(2, 2, 2));

        try {
            auto c2 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
            c2.set_position(vec3(1, 1, 1));
            assert(false);
        } catch (CameraException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestCameraSetLookAt() {
        std::cout << "\t[Camera] Testing SetLookAt..." << std::endl;
        auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
        c1.set_look_at(vec3(2, 2, 2));
        assert(c1.get_look_at() == vec3(2, 2, 2));

        try {
            auto c2 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
            c2.set_look_at(vec3(0, 0, 0));
            assert(false);
        } catch (CameraException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestCameraSetUpDirection() {
      std::cout << "\t[Camera] Testing SetUpDirection..." << std::endl;
        auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
        c1.set_up_direction(vec3(1, 2, 3));
        assert(c1.get_up_direction() == vec3(1, 2, 3));

        try {
            auto c2 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
            c2.set_up_direction(vec3(0, 0, 0));
            assert(false);
        } catch (CameraException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
      }

    void TestCameraSetFov() {
        std::cout << "\t[Camera] Testing SetFov..." << std::endl;
        auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
        c1.set_fov(45);
        assert(c1.get_fov() == 45);

        try {
            auto c2 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
            c2.set_fov(0);
            c2.set_fov(180);
            c2.set_fov(-1);
            c2.set_fov(181);
            assert(false);
        } catch (CameraException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestCameraAll() {
        std::cout << "[Unit Testing] Testing Camera..." << std::endl;
        TestCameraConstructor();
        TestCameraPosition();
        TestCameraLookAt();
        TestCameraSetPosition();
        TestCameraSetLookAt();
        TestCameraSetUpDirection();
        TestCameraSetFov();
    }
}
