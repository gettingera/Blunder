// Includes
#include <Camera/Camera.h>
#include <Utils/Ray.h>

// Main method
int main() {
    auto c1 = Camera(vec3(0, 0, 0), vec3(1, 1, 1));
    auto r1 = Ray(vec3(1), vec3(1));
    return 0;
}
