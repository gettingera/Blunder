#ifndef HITRECORD_H
#define HITRECORD_H


class Material;


class HitRecord {
public:
    // Constructors
    HitRecord() = default;

    // Methods
    void SetFaceNormal(const Ray &ray, const dvec3 &outwardNormal) {
        frontFace = dot(ray.Direction(), outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }

    // Getters
    [[nodiscard]] dvec3 get_point() const {
        return point;
    }

    [[nodiscard]] dvec3 get_normal() const {
        return normal;
    }

    [[nodiscard]] shared_ptr<Material> get_material() const {
        return material;
    }

    [[nodiscard]] double get_time() const {
        return time;
    }

    [[nodiscard]] bool is_front_face() const {
        return frontFace;
    }

    // Setters
    void set_point(const dvec3 &point) {
        this->point = point;
    }

    void set_normal(const dvec3 &normal) {
        this->normal = normal;
    }

    void set_material(const shared_ptr<Material> &material) {
        this->material = material;
    }

    void set_time(const double time) {
        this->time = time;
    }

    void set_front_face(const bool front_face) {
        frontFace = front_face;
    }

private:
    dvec3 point;
    dvec3 normal;
    shared_ptr<Material> material;
    double time;
    bool frontFace;

};


#endif //HITRECORD_H
