#include <Utils/Headers.h>
#include <Renderer/Renderer.h>

namespace BlunderTest {
    static void TestRendererConstructor() {
        std::cout << "\t[Renderer] Testing Constructor..." << std::endl;
        auto r1 = Renderer(10, 20);
        assert(r1.get_samples() == 10);
        assert(r1.get_max_depth() == 20);

        try {
            auto r2 = Renderer(0, 0);
            assert(false);
        } catch (RendererException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }

        try {
            auto r3 = Renderer(-1, -1);
            assert(false);
        } catch (RendererException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    static void TestRendererRender() {
        std::cout << "\t[Renderer] Testing render..." << std::endl;
        auto r1 = Renderer(10, 20);
        auto sl = make_shared<SphereList>();
        auto s1 = make_shared<Sphere>(vec3(0), 0.1, Color(0, 0, 1));
        sl->Add(s1);
        auto c1 = make_shared<Camera>(vec3(3), vec3(0));
        auto rtt1 = make_shared<RenderTarget>(1, 1);

        try {
            r1.render(sl, c1, rtt1);
        } catch (...) {
            assert(false);
        }

        try {
            shared_ptr<SphereList> nsl = nullptr;
            r1.render(nsl, c1, rtt1);
            assert(false);
        } catch (RendererException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }

        try {
            shared_ptr<Camera> nc1 = nullptr;
            r1.render(sl, nc1, rtt1);
            assert(false);
        } catch (RendererException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }

        try {
            shared_ptr<RenderTarget> nrtt1 = nullptr;
            r1.render(sl, c1, nrtt1);
            assert(false);
        } catch (RendererException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    static void TestRendererInitializeRTCamera() {
        std::cout << "\t[Renderer] Testing initializeRTCamera..." << std::endl;
        auto r1 = Renderer(10, 20);
        auto camera = make_shared<Camera>(vec3(0), vec3(1));
        auto rtt = make_shared<RenderTarget>(100, 100);

        try {
            auto rtcv = Renderer::initializeRTCamera(camera, rtt);
        } catch (...) {
            assert(false);
        }

        try {
            shared_ptr<Camera> newCam = nullptr;
            auto rtcv = Renderer::initializeRTCamera(newCam, rtt);
            assert(false);
        } catch (RendererException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }

        try {
            shared_ptr<RenderTarget> newRt = nullptr;
            auto rtcv = Renderer::initializeRTCamera(camera, newRt);
            assert(false);
        } catch (RendererException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    static void TestRendererGetRayAtPixel() {
        std::cout << "\t[Renderer] Testing getRayAtPixel..." << std::endl;
        auto r1 = Renderer(10, 20);
        auto camera = make_shared<Camera>(vec3(0), vec3(1));
        auto rtt = make_shared<RenderTarget>(100, 100);
        auto rtcv = Renderer::initializeRTCamera(camera, rtt);

        try {
            r1.getRayAtPixel(1, 1, rtcv);
        } catch (...) {
            assert(false);
        }

        try {
            r1.getRayAtPixel(-1, -1, rtcv);
            assert(false);
        } catch (RendererException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    static void TestRendererGetRayColor() {
        std::cout << "\t[Renderer] Testing getRayColor..." << std::endl;
        auto r1 = Renderer(10, 20);
        auto ray = Ray(vec3(0), vec3(1));
        auto spheres = make_shared<SphereList>();

        try {
            auto col = r1.getRayColor(ray, spheres);
            spheres->Add(make_shared<Sphere>(vec3(0), 0.2, Color(1, 1, 0)));
            col = r1.getRayColor(ray, spheres);
        } catch (...) {
            assert(false);
        }

        try {
            spheres = nullptr;
            auto col = r1.getRayColor(ray, spheres);
            assert(false);
        } catch (RendererException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    static void TestRendererGetSkyColor() {
        std::cout << "\t[Renderer] Testing getSkyColor..." << std::endl;
        auto color = Renderer::getSkyColor(Ray(vec3(0), vec3(1)));
    }

    static void TestRendererScatter() {
        std::cout << "\t[Renderer] Testing scatter..." << std::endl;
        auto hit_record = HitRecord{};
        auto ray = Ray(vec3(0), vec3(1));
        auto r1 = Renderer(10, 20);
        assert(r1.scatter(hit_record, ray) == true);
    }

    static void TestRendererSetSamples() {
        std::cout << "\t[Renderer] Testing set_samples..." << std::endl;
        auto r1 = Renderer(10, 10);
        r1.set_samples(20);
        assert(r1.get_samples() == 20);
        r1.set_samples(1);
        assert(r1.get_samples() == 1);

        try {
            r1.set_samples(0);
            assert(false);
        } catch (RendererException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }

        try {
            r1.set_samples(-1);
            assert(false);
        } catch (RendererException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    static void TestRendererSetMaxDepth() {
        std::cout << "\t[Renderer] Testing set_max_depth..." << std::endl;
        auto r1 = Renderer(10, 10);
        r1.set_max_depth(20);
        assert(r1.get_max_depth() == 20);
        r1.set_max_depth(1);
        assert(r1.get_max_depth() == 1);

        try {
            r1.set_max_depth(0);
            assert(false);
        } catch (RendererException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }

        try {
            r1.set_max_depth(-1);
            assert(false);
        } catch (RendererException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    static void TestRendererAll() {
        std::cout << "[Unit Test] Testing Renderer..." << std::endl;
        TestRendererConstructor();
        TestRendererRender();
        TestRendererInitializeRTCamera();
        TestRendererGetRayAtPixel();
        TestRendererGetRayColor();
        TestRendererGetSkyColor();
        TestRendererSetSamples();
        TestRendererSetMaxDepth();
    }
}
