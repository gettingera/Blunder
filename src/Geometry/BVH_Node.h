#ifndef BVH_NODE_H
#define BVH_NODE_H
#include "Hittable.h"
#include "HittableList.h"
#include "AABB.h"
#include <algorithm>


class BVH_Node : public Hittable {
    /// Pointer to left object, for tree structure.
    shared_ptr<Hittable> left;

    /// Pointer to right object, for tree structure.
    shared_ptr<Hittable> right;

    /// Bounding box surrounding the interior left and right objects.
    AABB bounding_box;

public:
    // Constructors
    /**
     * A simplified constructor for the BVH.
     *
     * @param collection Collection of objects to be stored in the BVH.
     */
    explicit BVH_Node(HittableList collection) : BVH_Node(collection.get_objects(), 0, collection.get_objects().size()) {};

    BVH_Node(std::vector<shared_ptr<Hittable>> &objects, const size_t start, const size_t end) {
        // Build bounding box of source objects
        set_bounding_box({});
        for (size_t object_index = start; object_index < end; object_index++) {
            set_bounding_box(AABB(get_bounding_box(), objects[object_index]->BoundingBox()));
        }
        const int axis = get_bounding_box().LongestAxis();

        auto comparator = (axis == 0)
            ? box_x_compare : (axis == 1)
            ? box_y_compare
            : box_z_compare;

        size_t object_span = end - start;

        if (object_span == 1) {
            set_left(objects[start]);
            set_right(objects[start]);
        } else if (object_span == 2) {
            set_left(objects[start]);
            set_right(objects[start + 1]);
        } else {
            std::sort(std::begin(objects) + start, std::begin(objects) + end, comparator);
            auto mid = start + (object_span / 2);
            set_left(make_shared<BVH_Node>(objects, start, mid));
            set_right(make_shared<BVH_Node>(objects, mid, end));
        }

        set_bounding_box(AABB(get_left()->BoundingBox(), get_right()->BoundingBox()));
    }

    // Methods
    bool Hit(const Ray &ray, const Interval &rayTime, HitRecord &record) const override {
        if (!get_bounding_box().Hit(ray, rayTime)) {
            return false;
        }

        bool hit_left = get_left()->Hit(ray, rayTime, record);
        bool hit_right = get_right()->Hit(ray, Interval(rayTime.get_min(), hit_left ? record.get_time() : rayTime.get_max()), record);

        return hit_left || hit_right;
    };

    [[nodiscard]] AABB BoundingBox() const override {
        return get_bounding_box();
    };

    static bool box_compare(const shared_ptr<Hittable> &a, const shared_ptr<Hittable> &b, const int axis_index) {
        auto a_axis_interval = a->BoundingBox().AxisInterval(axis_index);
        auto b_axis_interval = b->BoundingBox().AxisInterval(axis_index);
        return a_axis_interval.get_min() < b_axis_interval.get_min();
    }

    static bool box_x_compare(const shared_ptr<Hittable> &a, const shared_ptr<Hittable> &b) {
        return box_compare(a, b, 0);
    }

    static bool box_y_compare(const shared_ptr<Hittable> &a, const shared_ptr<Hittable> &b) {
        return box_compare(a, b, 1);
    }

    static bool box_z_compare(const shared_ptr<Hittable> &a, const shared_ptr<Hittable> &b) {
        return box_compare(a, b, 2);
    }

    // Getters
    [[nodiscard]] shared_ptr<Hittable> get_left() const {
        return left;
    }

    [[nodiscard]] shared_ptr<Hittable> get_right() const {
        return right;
    }

    [[nodiscard]] AABB get_bounding_box() const {
        return bounding_box;
    }

    // Setters
    void set_left(const shared_ptr<Hittable> &left) {
        this->left = left;
    }

    void set_right(const shared_ptr<Hittable> &right) {
        this->right = right;
    }

    void set_bounding_box(const AABB &bounding_box) {
        this->bounding_box = bounding_box;
    }
};

#endif //BVH_NODE_H
