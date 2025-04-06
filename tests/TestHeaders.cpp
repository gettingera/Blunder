#include <complex>
#include <Utils/Headers.h>

namespace {
    void TestHeadersIsFiniteFloat() {
        std::cout << "\t[Headers] Testing is_finite(float)..." << std::endl;
        assert(is_finite(0) == true);
        assert(is_finite(infinity) == false);
        assert(is_finite(-infinity) == false);
        assert(is_finite(NAN) == false);
    }

    void TestHeadersIsFiniteVec3() {
        std::cout << "\t[Headers] Testing is_finite(vec3)..." << std::endl;
        assert(is_finite(vec3(0)) == true);
        assert(is_finite(vec3(infinity)) == false);
        assert(is_finite(vec3(-infinity)) == false);
        assert(is_finite(vec3(NAN)) == false);
    }

    void TestHeadersIsNearZeroFloat() {
        std::cout << "\t[Headers] Testing is_near_zero(float)..." << std::endl;
        assert(is_near_zero(0) == true);
        assert(is_near_zero(1) == false);
        assert(is_near_zero(1e-8) == false);
        assert(is_near_zero(1e-9) == true);
        assert(is_near_zero(infinity) == false);
        assert(is_near_zero(-infinity) == false);
        assert(is_near_zero(NAN) == false);
    }

    void TestHeadersIsNearZeroVec3() {
        std::cout << "\t[Headers] Testing is_near_zero(vec3)..." << std::endl;
        assert(is_near_zero(vec3(0)) == true);
        assert(is_near_zero(vec3(1)) == false);
        assert(is_near_zero(vec3(infinity)) == false);
        assert(is_near_zero(vec3(-infinity)) == false);
        assert(is_near_zero(vec3(NAN)) == false);
        assert(is_near_zero(vec3(1e-8)) == false);
        assert(is_near_zero(vec3(1e-9)) == true);
    }

    void TestHeadersIsNearEqual() {
        std::cout << "\t[Headers] Testing is_near_equal(vec3, vec3)..." << std::endl;
        assert(is_near_equal(vec3(0), vec3(0)) == true);
        assert(is_near_equal(vec3(1), vec3(0)) == false);
        assert(is_near_equal(vec3(1e-8), vec3(0)) == false);
        assert(is_near_equal(vec3(1e-9), vec3(0)) == true);
    }

    void TestHeadersIsInsideClosedRangeFloat() {
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

    void TestHeadersIsInsideClosedRangeVec3() {
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

    void TestHeadersLinearToGamma() {
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

    void TestHeadersDegreesToRadians() {
        std::cout << "\t[Headers] Testing degrees_to_radians(float)..." << std::endl;
        assert(degrees_to_radians(0) == 0);
    }

    void TestHeadersRandomFloatNoArgs() {
        std::cout << "\t[Headers] Testing random_float()..." << std::endl;
        auto rand_float = random_float();
        assert(0 <= rand_float && rand_float <= 1);
    }

    void TestHeadersRandomFloatFloat() {
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

    void TestHeadersRandomVec3NoArgs() {
        std::cout << "\t[Headers] Testing random_vec3()..." << std::endl;
        auto rvec3 = random_vec3();
        assert(0 <= rvec3.x && rvec3.x <= 1);
        assert(0 <= rvec3.y && rvec3.y <= 1);
        assert(0 <= rvec3.z && rvec3.z <= 1);
    }

    void TestHeadersRandomVec3Float() {
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

    void TestHeadersRandomUnitVector() {
        std::cout << "\t[Headers] Testing random_unit_vector()..." << std::endl;
        auto random_unit = random_unit_vector();
        assert(is_near_zero(length(random_unit) - 1.0f));
    }

    void TestHeadersSampleSquare() {
        std::cout << "\t[Headers] Testing sample_square()..." << std::endl;
        auto sample = sampleSquare();
        assert(sample.x >= -0.5f && sample.x <= 0.5f);
        assert(sample.y >= -0.5f && sample.y <= 0.5f);
        assert(sample.z == 0);
    }

    void TestHeadersAll() {
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
