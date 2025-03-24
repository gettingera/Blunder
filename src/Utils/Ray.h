#ifndef RAY_H
#define RAY_H


#include <glm/vec3.hpp>


class Ray {
  public:
    // Constructor
    Ray(glm::dvec3 origin, glm::dvec3 direction);

    // Methods
    glm::dvec3 At(double time);

  private:
    // Attributes
    glm::dvec3 origin, direction;

};


#endif //RAY_H
