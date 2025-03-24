#ifndef HITRECORD_H
#define HITRECORD_H


#include <glm/vec3.hpp>


struct HitRecord {
  glm::dvec3 point;
  glm::dvec3 normal;
  double time;
};



#endif //HITRECORD_H
