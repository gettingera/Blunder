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
bool TestCamera();
bool TestCameraPosition();
bool TestCameraLookingAt();
bool TestCameraSetPosition();
bool TestCameraSetLookAt();
bool TestCameraSetUpDirection();
bool TestCameraSetFov();

//Geometry Tests
bool TestHitRecordSetPoint();
bool TestHitRecordSetNormal();
bool TestHitRecordSetColor();
bool TestHitRecordSetT();

bool TestSphereHit();
bool TestSphereSetPosition();
bool TestSphereSetRadius();
bool TestSphereSetColor();

bool TestSphereListHit();
bool TestSphereListSetPosition();
bool TestSphereListSetRadius();
bool TestSphereListSetColor();

// Utils Tests
bool TestColorColor();
bool TestColorSetColor();

bool TestHeadersValueFinite();
bool TestHeadersVectorFinite();
bool TestHeadersValueNearZero();
bool TestHeadersVectorNearZero();
bool TestHeadersVectorsEqual();
bool TestHeadersValueWithinClosedRange();
bool TestHeadersVectorsWithinClosedRange();

bool TestRayPosition();
bool TestRayDirection();
bool TestRaySetPosition();
bool TestRaySetDirection();


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

bool TestCamera() {
    // Pass Case
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));

    // Fail Case
    //auto c2 = Camera(vec3(0, 0, 0), vec3(0, 0, 0));

    return true;
}

// Camera Tests
bool TestCameraPosition() {
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
    // Pass Case
    assert(c1.get_position() == vec3(0, 0, 0));

    // Fail Case
    // assert(c1.get_position() == vec3(1, 1, 1));

    return true;
}

bool TestCameraLookingAt() {
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
    // Pass Case
    assert(c1.get_look_at() == vec3(1, 1, 1));

    // Fail Case
    // assert(c1.get_look_at() == vec3(0, 0, 0));

    return true;
}

bool TestCameraSetPosition() {
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
    // Pass Case
    c1.set_position(vec3(2, 2, 2));

    // Fail Case
    // c1.set_position(vec3(1, 1, 1));

    return true;
}

bool TestCameraSetLookAt() {
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
    // Pass Case
    c1.set_look_at(vec3(2, 2, 2));

    // Fail Case
    // c1.set_look_at(vec3(0, 0, 0));

    return true;
}


bool TestCameraSetUpDirection() {
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
    // Pass Case
    c1.set_up_direction(vec3(1, 2, 3));

    // Fail Case
    // c1.set_up_direction(vec3(0, 0, 0));
    return true;
}

bool TestCameraSetFov() {
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
    // Pass Case
    c1.set_fov(45);

    // Fail Cases
    // c1.set_fov(0);
    // c1.set_fov(180);
    // c1.set_fov(-1);
    // c1.set_fov(181);
    return true;
}

// Geometry Tests
bool TestHitRecordSetPoint() {
    return true;
}

bool TestHitRecordSetNormal() {
    return true;
}

bool TestHitRecordSetColor() {
    return true;
}

bool TestHitRecordSetT() {
    return true;
}

bool TestSphereHit() {
    return true;
}
bool TestSphereSetPosition() {
    return true;
}
bool TestSphereSetRadius() {
    return true;
}

bool TestSphereSetColor() {
    return true;
}

bool TestSphereListHit() {
    return true;
}

bool TestSphereListSetPosition() {
    return true;
}

bool TestSphereListSetRadius() {
    return true;
}

bool TestSphereListSetColor() {
    return true;
}