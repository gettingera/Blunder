#include <Utils/Headers.h>
#include <Geometry/HitRecord.h>

namespace BlunderTest {
    static void TestHitRecordSetPoint() {
        std::cout << "\t[HitRecord] Testing set_point..." << std::endl;
        auto hr1 = HitRecord{};
        hr1.set_point(vec3(0));
        assert(hr1.get_point() == vec3(0));

        try {
            hr1.set_point(vec3(infinity));
            assert(false);
        } catch (HitRecordException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    static void TestHitRecordSetNormal() {
        std::cout << "\t[HitRecord] Testing set_normal..." << std::endl;
        auto hr1 = HitRecord{};
        hr1.set_normal(vec3(1, 1, 1));
        assert(is_near_equal(normalize(vec3(1, 1, 1)), hr1.get_normal()));

        try {
            hr1.set_normal(vec3(0));
            assert(false);
        } catch (HitRecordException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }

        try {
            hr1.set_normal(vec3(infinity));
            assert(false);
        } catch (HitRecordException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    static void TestHitRecordSetColor() {
        std::cout << "\t[HitRecord] Testing set_color..." << std::endl;
        auto hr1 = HitRecord{};
        hr1.set_color(Color(vec3(1)));
        assert(hr1.get_color().get_color() == vec3(1));
    }

    static void TestHitRecordSetT() {
        std::cout << "\t[HitRecord] Testing set_t..." << std::endl;
        auto hr1 = HitRecord{};
        hr1.set_t(1);
        assert(hr1.get_t() == 1);
        hr1.set_t(0);
        assert(hr1.get_t() == 0);

        try {
            hr1.set_t(-1);
            assert(false);
        } catch (HitRecordException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }

        try {
            hr1.set_t(infinity);
            assert(false);
        } catch (HitRecordException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    static void TestHitRecordAll() {
        std::cout << "[Unit Test] Testing HitRecord..." << std::endl;
        TestHitRecordSetPoint();
        TestHitRecordSetNormal();
        TestHitRecordSetColor();
        TestHitRecordSetT();
    }
}
