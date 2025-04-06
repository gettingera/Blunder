// Includes
#include<glm/glm.hpp>
#include <cstdio>

// Camera
#include <Camera/Camera.h>

// Geometry
#include <Geometry/Sphere.h>
#include <Geometry/HitRecord.h>
#include <Geometry/SphereList.h>

// Renderer

// Utils
#include <Utils/Color.h>
#include <Utils/Headers.h>
#include <Utils/Ray.h>

// Camera Tests
void TestCameraConstructor();
void TestCameraSetPosition();
void TestCameraSetLookAt();
void TestCameraSetUpDirection();
void TestCameraSetFov();
void TestCameraAll();

//Geometry Tests
void TestHitRecordSetPoint();
void TestHitRecordSetNormal();
void TestHitRecordSetColor();
void TestHitRecordSetT();
void TestHitRecordAll();

void TestSphereConstructor();
void TestSphereHit();
void TestSphereSetPosition();
void TestSphereSetRadius();
void TestSphereSetColor();
void TestSphereAll();

void TestSphereListHit();
void TestSphereListSetPosition();
void TestSphereListSetRadius();
void TestSphereListSetColor();
void TestSphereListAll();

// Utils Tests
void TestColorConstructor();
void TestColorSetColor();
void TestColorAll();

void TestHeadersValueFinite();
void TestHeadersVectorFinite();
void TestHeadersValueNearZero();
void TestHeadersVectorNearZero();
void TestHeadersVectorsEqual();
void TestHeadersValueWithinClosedRange();
void TestHeadersVectorsWithinClosedRange();
void TestHeadersAll();

#include "TestRay.cpp"

// Main Function
int main() {
    // Example Test Ray
    TestRayAll();
}

void TestCamera() {
    // Pass Case
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));

    // Fail Case
    //auto c2 = Camera(vec3(0, 0, 0), vec3(0, 0, 0));

}

// Camera Tests
void TestCameraPosition() {
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
    // Pass Case
    assert(c1.get_position() == vec3(0, 0, 0));

    // Fail Case
    // assert(c1.get_position() == vec3(1, 1, 1));

}

void TestCameraLookingAt() {
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
    // Pass Case
    assert(c1.get_look_at() == vec3(1, 1, 1));

    // Fail Case
    // assert(c1.get_look_at() == vec3(0, 0, 0));
}

void TestCameraSetPosition() {
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
    // Pass Case
    c1.set_position(vec3(2, 2, 2));

    // Fail Case
    // c1.set_position(vec3(1, 1, 1));

}

void TestCameraSetLookAt() {
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
    // Pass Case
    c1.set_look_at(vec3(2, 2, 2));

    // Fail Case
    // c1.set_look_at(vec3(0, 0, 0));

}


void TestCameraSetUpDirection() {
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
    // Pass Case
    c1.set_up_direction(vec3(1, 2, 3));

    // Fail Case
    // c1.set_up_direction(vec3(0, 0, 0));

}

void TestCameraSetFov() {
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
    // Pass Case
    c1.set_fov(45);

    // Fail Cases
    // c1.set_fov(0);
    // c1.set_fov(180);
    // c1.set_fov(-1);
    // c1.set_fov(181);
}

// Geometry Tests
void TestHitRecordSetPoint() {
    auto hr1 = HitRecord();
    // Pass Case
    hr1.set_point(vec3(0, 0, 0));

    // Fail Case
    // hr1.set_point(vec3(infinity, infinity, infinity));

}

void TestHitRecordSetNormal() {
    auto hr1 = HitRecord();
    // Pass Case
    hr1.set_normal(vec3(1, 1, 1));

    // Fail Case
    // hr1.set_normal(vec3(0, 0, 0));

}

void TestHitRecordSetColor() {
    auto hr1 = HitRecord();
    // Pass Case
    hr1.set_color(Color(0.5, 0.5, 0.5));

    // Fail Case
    // hr1.set_color(Color(2, 2,2));

}

void TestHitRecordSetT() {
    auto hr1 = HitRecord();
    // Pass Case
    hr1.set_t(1);
    hr1.set_t(0);

    // Fail Case
    // hr1.set_t(-1);
    // hr1.set_t(infinity);

}

void TestSphereHit() {
    auto s1 = Sphere(vec3(0, 0, 0), 1, Color(1, 1, 1));
    auto ray = Ray(vec3(0, -1, 0), vec3(0, 1, 0));
    auto hitRecord = HitRecord();
    // Pass Case
    s1.Hit(ray, 0, 10000, hitRecord);

    // Fail Case
    // s1.Hit(ray, 10000, 0, hitRecord);
    // s1.Hit(ray, -infinity, infinity, hitRecord);

}

void TestSphereSetPosition() {
    auto s1 = Sphere(vec3(0, 0, 0), 10, Color(1, 1, 1));
    // Pass Case
    s1.set_position(vec3(1, 1, 1));

    // Fail Case
    // s1.set_position(vec3(infinity, infinity, infinity));
}

void TestSphereSetRadius() {
    auto s1 = Sphere(vec3(0, 0, 0), 10, Color(1, 1, 1));
    // Pass Case
    s1.set_radius(1);

    // Fail Case
    // s1.set_radius(0);
    // s1.set_radius(-1);
    // s1.set_radius(infinity);
}

void TestSphereSetColor() {
    auto s1 = Sphere(vec3(0, 0, 0), 10, Color(1, 1, 1));
    // Pass Case
    s1.set_color(Color(0.5, 0.5, 0.5));

    // Fail Case
    // s1.set_color(Color(2, 2, 2))
}

void TestSphereListHit() {
    auto s1 = make_shared<Sphere>(vec3(0, 0, 0), 1, Color(1, 1, 1));
    auto ray = Ray(vec3(0, -1, 0), vec3(0, 1, 0));
    auto hitRecord = HitRecord();

    const auto spheres = make_shared<SphereList>();

    spheres->Add(s1);

}

void TestSphereListSetPosition() {
    printf("");
}

void TestSphereListSetRadius() {
    printf("");
}

void TestSphereListSetColor() {
    printf("");
}