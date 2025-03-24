#include "Ray.h"
#include <glm/vec3.hpp>


// Public
Ray::Ray(glm::dvec3 origin, glm::dvec3 direction) {
  this->origin = origin;
  this->direction = direction;
}

glm::dvec3 Ray::At(double time) {
  return origin + (direction * time);
}
