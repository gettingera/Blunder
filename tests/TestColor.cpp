#include <Utils/Headers.h>
#include <Utils/Color.h>

namespace {
    void TestColor() {
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

    void TestSetColor() {
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

    void TestColorAll() {
        std::cout << "[Unit Testing] Testing Color..." << std::endl;
        TestColor();
        TestSetColor();
    }
}