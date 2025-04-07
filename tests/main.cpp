// Includes
#include<glm/glm.hpp>
#include <cstdio>

// Camera

// Geometry
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

#include "TestRay.cpp"
#include "TestCamera.cpp"
#include "TestSphere.cpp"
#include "TestRenderer.cpp"
#include "TestColor.cpp"
#include "TestHeaders.cpp"
#include "TestSphereList.cpp"

// Main Function
int main() {
    // Example Test Ray
    TestRayAll();
    TestCameraAll();
    TestSphereAll();
    TestRendererAll();
    TestColorAll();
    TestHeadersAll();
    TestSphereListAll();
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
