// Includes
#include<glm/glm.hpp>
#include <cstdio>

// Camera

// Geometry
#include <Geometry/Sphere.h>
#include <Geometry/HitRecord.h>
#include <Geometry/SphereList.h>

// Renderer

// Utils
#include <Utils/Color.h>
#include <Utils/Headers.h>
#include <Utils/Ray.h>

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
#include "TestCamera.cpp"

// Main Function
int main() {
    // Example Test Ray
    TestRayAll();
    TestCameraAll();
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