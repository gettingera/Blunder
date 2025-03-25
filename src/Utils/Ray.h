#ifndef RAY_H
#define RAY_H


#include <glm/vec3.hpp>


class Ray {
  public:
    // Constructor
    Ray(glm::dvec3 origin, glm::dvec3 direction) : origin(origin), direction(direction) {}

    // Methods
    glm::dvec3 At(double time) {
      return origin + (direction * time);
    }

    // Getters
    const glm::dvec3& Origin() const { return origin; }
    const glm::dvec3& Direction() const { return direction; }

  private:
    // Attributes
    glm::dvec3 origin, direction;

};


#endif //RAY_H
