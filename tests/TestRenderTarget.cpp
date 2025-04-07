#include <Utils/Headers.h>
#include <Renderer/RenderTarget.h>

namespace {
    void TestRenderTargetInitialize() {
        std::cout << "\t[RenderTarget] Testing initialize..." << std::endl;
        auto rt1 = RenderTarget(100, 200);
        assert(rt1.get_pixel(20, 20).get_color() == vec3(0));
    }

    void TestRenderTargetGetPixel() {
        std::cout << "\t[RenderTarget] Testing get_pixel..." << std::endl;
        auto rt1 = RenderTarget(101, 101);
        assert(rt1.get_pixel(0, 0).get_color() == vec3(0));
        assert(rt1.get_pixel(50, 50).get_color() == vec3(0));
        assert(rt1.get_pixel(100, 100).get_color() == vec3(0));

        try {
            auto col = rt1.get_pixel(-1, -1);
            assert(false);
        } catch (RenderTargetException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }

        try {
            auto col = rt1.get_pixel(101, 101);
            assert(false);
        } catch (RenderTargetException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestRenderTargetSetPixel() {
        std::cout << "\t[RenderTarget] Testing set_pixel..." << std::endl;
        auto rt1 = RenderTarget(101, 101);
        auto white = Color(vec3(1));
        rt1.set_pixel(0, 0, white);
        assert(rt1.get_pixel(0, 0).get_color() == vec3(1));
        rt1.set_pixel(50, 50, white);
        assert(rt1.get_pixel(50, 50).get_color() == vec3(1));
        rt1.set_pixel(100, 100, white);
        assert(rt1.get_pixel(100, 100).get_color() == vec3(1));

        try {
            rt1.set_pixel(-1, -1, white);
            assert(false);
        } catch (RenderTargetException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }

        try {
            rt1.set_pixel(101, 101, white);
            assert(false);
        } catch (RenderTargetException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestRenderTargetWriteToFile() {
        std::cout << "\t[RenderTarget] Testing writeToFile..." << std::endl;
        auto rt1 = RenderTarget(100, 200);
        auto name = "test";

        try {
            rt1.writeToFile(name);
        } catch (...) {
            assert(false);
        }

        try {
            auto badname = "";
            rt1.writeToFile(badname);
            assert(false);
        } catch (RenderTargetException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestRenderTargetSetWidth() {
        std::cout << "\t[RenderTarget] Testing set_width..." << std::endl;
        auto rt1 = RenderTarget(100, 200);
        rt1.set_width(1000);
        assert(rt1.get_width() == 1000);
        rt1.set_width(1);
        assert(rt1.get_width() == 1);

        try {
            rt1.set_width(0);
            assert(false);
        } catch (RenderTargetException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }

        try {
            rt1.set_width(-1);
            assert(false);
        } catch (RenderTargetException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestRenderTargetSetHeight() {
        std::cout << "\t[RenderTarget] Testing set_height..." << std::endl;
        auto rt1 = RenderTarget(100, 200);
        rt1.set_height(1000);
        assert(rt1.get_height() == 1000);
        rt1.set_height(1);
        assert(rt1.get_height() == 1);

        try {
            rt1.set_height(0);
            assert(false);
        } catch (RenderTargetException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }

        try {
            rt1.set_height(-1);
            assert(false);
        } catch (RenderTargetException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    void TestRenderTargetAll() {
        std::cout << "[Unit Test] Testing RenderTarget..." << std::endl;
        TestRenderTargetInitialize();
        TestRenderTargetGetPixel();
        TestRenderTargetSetPixel();
        TestRenderTargetWriteToFile();
        TestRenderTargetSetWidth();
        TestRenderTargetSetHeight();
    }
}
