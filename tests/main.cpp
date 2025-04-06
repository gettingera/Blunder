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
void TestCamera();
void TestCameraPosition();
void TestCameraLookingAt();
void TestCameraSetPosition();
void TestCameraSetLookAt();
void TestCameraSetUpDirection();
void TestCameraSetFov();

//Geometry Tests
void TestHitRecordSetPoint();
void TestHitRecordSetNormal();
void TestHitRecordSetColor();
void TestHitRecordSetT();

void TestSphereHit();
void TestSphereSetPosition();
void TestSphereSetRadius();
void TestSphereSetColor();

void TestSphereListHit();
void TestSphereListSetPosition();
void TestSphereListSetRadius();
void TestSphereListSetColor();

// Utils Tests
void TestColorColor();
void TestColorSetColor();

void TestHeadersValueFinite();
void TestHeadersVectorFinite();
void TestHeadersValueNearZero();
void TestHeadersVectorNearZero();
void TestHeadersVectorsEqual();
void TestHeadersValueWithinClosedRange();
void TestHeadersVectorsWithinClosedRange();

void TestRayPosition();
void TestRayDirection();
void TestRaySetPosition();
void TestRaySetDirection();


// Main Function
int main() {
    // Test Camera
    printf("-----Testing Camera-----\n");

    // Camera
    printf("Test Camera: ");
    TestCamera();
    printf("Test Passed\n");

    // Position
    printf("Test Position: ");
    TestCameraPosition();
    printf("Test Passed\n");

    // Looking_at
    printf("Test Looking_at: ");
    TestCameraLookingAt();
    printf("Test Passed\n");

    // Set Position
    printf("Test Set Position: ");
    TestCameraSetPosition();
    printf("Test Passed\n");

    // Set Looking at
    printf("Test Set Looking at: ");
    TestCameraSetLookAt();
    printf("Test Passed\n");

    // Set Up Direction
    printf("Test Set Up Direction: ");
    TestCameraSetUpDirection();
    printf("Test Passed\n");

    // Set Fov
    printf("Test Set Fov: ");
    TestCameraSetFov();
    printf("Test Passed\n");

    // Test Geometry
    printf("\n-----Testing Geometry-----\n");

    // Hit Record Set Point
    printf("Test Hit Record Set Point: ");
    TestHitRecordSetPoint();
    printf("Test Passed\n");

    // Hit Record Set Normal
    printf("Test Hit Record Set Normal: ");
    TestHitRecordSetNormal();
    printf("Test Passed\n");

    // Hit Record Set Color
    printf("Test Hit Record Set Color: ");
    TestHitRecordSetColor();
    printf("Test Passed\n");

    // Hit Record Set T
    printf("Test Hit Record Set T: ");
    TestHitRecordSetT();
    printf("Test Passed\n");

    // Sphere Hit
    printf("\nTest Sphere Hit: ");
    TestSphereHit();
    printf("Test Passed\n");

    // Sphere Set Position
    printf("Test Sphere Set Position: ");
    TestSphereSetPosition();
    printf("Test Passed\n");

    // Sphere Set Radius
    printf("Test Sphere Set Radius: ");
    TestSphereSetRadius();
    printf("Test Passed\n");

    // Sphere Set Color
    printf("Test Sphere Set Color: ");
    TestSphereSetColor();
    printf("Test Passed\n");

    // Sphere Set T
    printf("\nTest Sphere Set T: ");
    TestSphereListHit();
    printf("Test Passed\n");

    // Sphere Set Sphere List Position
    printf("Test Sphere List Set Position: ");
    TestSphereListSetPosition();
    printf("Test Passed\n");

    // Sphere Set Sphere List Radius
    printf("Test Sphere List Set Radius: ");
    TestSphereListSetRadius();
    printf("Test Passed\n");

    // Sphere Set Sphere List Color
    printf("Test Sphere List Set Color: ");
    TestSphereListSetColor();
    printf("Test Passed\n");

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
    // s1.set_color(Color(2, 2, 2));
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