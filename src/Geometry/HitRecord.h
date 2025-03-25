#ifndef HITRECORD_H
#define HITRECORD_H


class HitRecord {
public:
    // Public attributes
    glm::dvec3 point;
    glm::dvec3 normal;
    double time;
    bool frontFace;

    // Methods
    void SetFaceNormal(const Ray &ray, const glm::dvec3 &outwardNormal) {
        this->frontFace = glm::dot(ray.Direction(), outwardNormal) < 0;
        this->normal = this->frontFace ? outwardNormal : -outwardNormal;
    }
};


#endif //HITRECORD_H
