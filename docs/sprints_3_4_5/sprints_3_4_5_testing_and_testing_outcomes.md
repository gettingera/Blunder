# Testing/Testing Outcomes

Today’s computing environment poses countless challenges in the realm of cybersecurity. Therefore, extensive testing has been conducted on Blunder to ensure its functionality remains predictable and performs without critical errors. The following test files were created with the intention of minimizing issues from both a user’s perspective and the machine executing the program. The testing code is listed within each section to allow clients to evaluate exactly what functionality has been confirmed and how to identify errors if they are present.

## Ray Testing

    #include <Utils/Headers.h>
    #include <Utils/Ray.h>

    namespace BlunderTest {
      static void TestRayConstructor() {
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
  
      static void TestRayAt() {
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
  
      static void TestRaySetPosition() {
          std::cout << "\t[Ray] Testing set_position..." << std::endl;
          auto r1 = Ray(vec3(0), vec3(1));
          r1.set_position(vec3(1));
          assert(r1.get_position() == vec3(1));
      }
  
      static void TestRaySetDirection() {
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
  
      static void TestRayAll() {
          std::cout << "[Unit Testing] Testing Ray..." << std::endl;
          TestRayConstructor();
          TestRayAt();
          TestRaySetPosition();
          TestRaySetDirection();
      }
    }

## Camera Testing

    #include <Utils/Headers.h>
    #include <Camera/Camera.h>
    
    namespace BlunderTest {
        static void TestCameraConstructor() {
            std::cout << "\t[Camera] Testing Constructor..." << std::endl;
            auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
            assert(c1.get_position() == vec3(0, 0, 0));
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
    
        static void TestCameraPosition() {
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
    
        static void TestCameraLookAt() {
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
    
        static void TestCameraSetPosition() {
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
    
        static void TestCameraSetLookAt() {
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
    
        static void TestCameraSetUpDirection() {
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
    
        static void TestCameraSetFov() {
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
    
        static void TestCameraAll() {
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

## Sphere Testing

    #include <Utils/Headers.h>
    #include <Geometry/Sphere.h>
    
    namespace BlunderTest {
        static void TestSphereHit() {
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
    
        static void TestSphereSetPosition() {
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
    
        static void TestSphereSetRadius() {
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
    
        static void TestSphereSetColor() {
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
    
        static void TestSphereAll() {
            std::cout << "[Unit Testing] Testing Sphere..." << std::endl;
            TestSphereHit();
            TestSphereSetPosition();
            TestSphereSetRadius();
            TestSphereSetColor();
        }
    }

## Renderer Testing

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

## Color Testing

    #include <Utils/Headers.h>
    #include <Utils/Color.h>
    
    namespace BlunderTest {
        static void TestColor() {
            std::cout << "\t[Color] Testing Color..." << std::endl;
            auto c1 = Color(vec3(0, 0, 0));
            assert(c1.get_color() == Color(0, 0, 0).get_color());
    
            auto c2 = Color(vec3(1, 1, 1));
            assert(c2.get_color() == Color(1, 1, 1).get_color());
    
            try {
                auto c3 = Color(vec3(3, 3, 3));
                auto c4 = Color(vec3(-1, -1, -1));
                assert(false);
            } catch (ColorException &e) {
                assert(true);
            } catch (...) {
                assert(false);
            }
        }
    
        static void TestSetColor() {
            std::cout << "\t[Color] Testing SetColor..." << std::endl;
            auto c1 = Color(vec3(0, 0, 0));
            c1.set_color(vec3(1, 1, 1));
            assert(c1.get_color() == Color(1, 1, 1).get_color());
    
            try {
                c1.set_color(vec3(2, 2, 2));
                c1.set_color(vec3(-1, -1, -1));
                assert(false);
            } catch (ColorException &e) {
                assert(true);
            } catch (...) {
                assert(false);
            }
        }
    
        static void TestColorAll() {
            std::cout << "[Unit Testing] Testing Color..." << std::endl;
            TestColor();
            TestSetColor();
        }
    }

## Headers Testing

    #include <complex>
    #include <Utils/Headers.h>
    
    namespace BlunderTest {
        static void TestHeadersIsFiniteFloat() {
            std::cout << "\t[Headers] Testing is_finite(float)..." << std::endl;
            assert(is_finite(0) == true);
            assert(is_finite(infinity) == false);
            assert(is_finite(-infinity) == false);
            assert(is_finite(NAN) == false);
        }
    
        static void TestHeadersIsFiniteVec3() {
            std::cout << "\t[Headers] Testing is_finite(vec3)..." << std::endl;
            assert(is_finite(vec3(0)) == true);
            assert(is_finite(vec3(infinity)) == false);
            assert(is_finite(vec3(-infinity)) == false);
            assert(is_finite(vec3(NAN)) == false);
        }
    
        static void TestHeadersIsNearZeroFloat() {
            std::cout << "\t[Headers] Testing is_near_zero(float)..." << std::endl;
            assert(is_near_zero(0) == true);
            assert(is_near_zero(1) == false);
            assert(is_near_zero(1e-8) == false);
            assert(is_near_zero(1e-9) == true);
            assert(is_near_zero(infinity) == false);
            assert(is_near_zero(-infinity) == false);
            assert(is_near_zero(NAN) == false);
        }
    
        static void TestHeadersIsNearZeroVec3() {
            std::cout << "\t[Headers] Testing is_near_zero(vec3)..." << std::endl;
            assert(is_near_zero(vec3(0)) == true);
            assert(is_near_zero(vec3(1)) == false);
            assert(is_near_zero(vec3(infinity)) == false);
            assert(is_near_zero(vec3(-infinity)) == false);
            assert(is_near_zero(vec3(NAN)) == false);
            assert(is_near_zero(vec3(1e-8)) == false);
            assert(is_near_zero(vec3(1e-9)) == true);
        }
    
        static void TestHeadersIsNearEqual() {
            std::cout << "\t[Headers] Testing is_near_equal(vec3, vec3)..." << std::endl;
            assert(is_near_equal(vec3(0), vec3(0)) == true);
            assert(is_near_equal(vec3(1), vec3(0)) == false);
            assert(is_near_equal(vec3(1e-8), vec3(0)) == false);
            assert(is_near_equal(vec3(1e-9), vec3(0)) == true);
        }
    
        static void TestHeadersIsInsideClosedRangeFloat() {
            std::cout << "\t[Headers] Testing is_inside_closed_range(float, float, float)..." << std::endl;
            assert(is_inside_closed_range(1, 0, 2) == true);
            assert(is_inside_closed_range(-1, 0, 2) == false);
            assert(is_inside_closed_range(0, 0, 2) == true);
            assert(is_inside_closed_range(2, 0, 2) == true);
            assert(is_inside_closed_range(1, 2, 0) == false);
    
            try {
                is_inside_closed_range(NAN, NAN, NAN);
                assert(false);
            } catch (HeaderException &e) {
                assert(true);
            } catch (...) {
                assert(false);
            }
        }
    
        static void TestHeadersIsInsideClosedRangeVec3() {
            std::cout << "\t[Headers] Testing is_inside_closed_range(vec3, float, float)..." << std::endl;
            assert(is_inside_closed_range(vec3(1), 0, 2) == true);
            assert(is_inside_closed_range(vec3(-1), 0, 2) == false);
            assert(is_inside_closed_range(vec3(0), 0, 2) == true);
            assert(is_inside_closed_range(vec3(2), 0, 2) == true);
            assert(is_inside_closed_range(vec3(1), 2, 0) == false);
    
            try {
                is_inside_closed_range(vec3(NAN), NAN, NAN);
                assert(false);
            } catch (HeaderException &e) {
                assert(true);
            } catch (...) {
                assert(false);
            }
        }
    
        static void TestHeadersLinearToGamma() {
            std::cout << "\t[Headers] Testing linear_to_gamma(float)..." << std::endl;
            assert(linear_to_gamma(0) == 0);
            assert(linear_to_gamma(1) == 1);
            assert(linear_to_gamma(0.25) == 0.5);
    
            try {
                linear_to_gamma(-1);
                assert(false);
            } catch (HeaderException &e) {
                assert(true);
            } catch (...) {
                assert(false);
            }
        }
    
        static void TestHeadersDegreesToRadians() {
            std::cout << "\t[Headers] Testing degrees_to_radians(float)..." << std::endl;
            assert(degrees_to_radians(0) == 0);
        }
    
        static void TestHeadersRandomFloatNoArgs() {
            std::cout << "\t[Headers] Testing random_float()..." << std::endl;
            auto rand_float = random_float();
            assert(0 <= rand_float && rand_float <= 1);
        }
    
        static void TestHeadersRandomFloatFloat() {
            std::cout << "\t[Headers] Testing random_float(float)..." << std::endl;
            auto rand_float = random_float(0, 1);
            assert(0 <= rand_float && rand_float <= 1);
    
            try {
                rand_float = random_float(1, 1);
                assert(false);
            } catch (HeaderException &e) {
                assert(true);
            } catch (...) {
                assert(false);
            }
    
            try {
                rand_float = random_float(2, 1);
                assert(false);
            } catch (HeaderException &e) {
                assert(true);
            } catch (...) {
                assert(false);
            }
        }
    
        static void TestHeadersRandomVec3NoArgs() {
            std::cout << "\t[Headers] Testing random_vec3()..." << std::endl;
            auto rvec3 = random_vec3();
            assert(0 <= rvec3.x && rvec3.x <= 1);
            assert(0 <= rvec3.y && rvec3.y <= 1);
            assert(0 <= rvec3.z && rvec3.z <= 1);
        }
    
        static void TestHeadersRandomVec3Float() {
            std::cout << "\t[Headers] Testing random_vec3(float, float)..." << std::endl;
            auto rvec3 = random_vec3(0, 1);
            assert(0 <= rvec3.x && rvec3.x <= 1);
            assert(0 <= rvec3.y && rvec3.y <= 1);
            assert(0 <= rvec3.z && rvec3.z <= 1);
    
            try {
                random_vec3(1, 1);
                assert(false);
            } catch (HeaderException &e) {
                assert(true);
            } catch (...) {
                assert(false);
            }
    
            try {
                random_vec3(2, 1);
                assert(false);
            } catch (HeaderException &e) {
                assert(true);
            } catch (...) {
                assert(false);
            }
        }
    
        static void TestHeadersRandomUnitVector() {
            std::cout << "\t[Headers] Testing random_unit_vector()..." << std::endl;
            auto random_unit = random_unit_vector();
            assert(is_near_zero(length(random_unit) - 1.0f));
        }
    
        static void TestHeadersSampleSquare() {
            std::cout << "\t[Headers] Testing sample_square()..." << std::endl;
            auto sample = sampleSquare();
            assert(sample.x >= -0.5f && sample.x <= 0.5f);
            assert(sample.y >= -0.5f && sample.y <= 0.5f);
            assert(sample.z == 0);
        }
    
        static void TestHeadersAll() {
            std::cout << "[Unit Testing] Testing Headers..." << std::endl;
            TestHeadersIsFiniteFloat();
            TestHeadersIsFiniteVec3();
            TestHeadersIsNearZeroFloat();
            TestHeadersIsNearZeroVec3();
            TestHeadersIsNearEqual();
            TestHeadersIsInsideClosedRangeFloat();
            TestHeadersIsInsideClosedRangeVec3();
            TestHeadersLinearToGamma();
            TestHeadersDegreesToRadians();
            TestHeadersRandomFloatNoArgs();
            TestHeadersRandomFloatFloat();
            TestHeadersRandomVec3NoArgs();
            TestHeadersRandomVec3Float();
            TestHeadersRandomUnitVector();
            TestHeadersSampleSquare();
        }
    }

## SphereList Testing

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

## RenderTarget Testing

    #include <Utils/Headers.h>
    #include <Renderer/RenderTarget.h>
    
    namespace BlunderTest {
        static void TestRenderTargetInitialize() {
            std::cout << "\t[RenderTarget] Testing initialize..." << std::endl;
            auto rt1 = RenderTarget(100, 200);
            assert(rt1.get_pixel(20, 20).get_color() == vec3(0));
        }
    
        static void TestRenderTargetGetPixel() {
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
    
        static void TestRenderTargetSetPixel() {
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
    
        static void TestRenderTargetWriteToFile() {
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
    
        static void TestRenderTargetSetWidth() {
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
    
        static void TestRenderTargetSetHeight() {
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
    
        static void TestRenderTargetAll() {
            std::cout << "[Unit Test] Testing RenderTarget..." << std::endl;
            TestRenderTargetInitialize();
            TestRenderTargetGetPixel();
            TestRenderTargetSetPixel();
            TestRenderTargetWriteToFile();
            TestRenderTargetSetWidth();
            TestRenderTargetSetHeight();
        }
    }

Go to [Home](https://github.com/gettingera/Blunder)
