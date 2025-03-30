#ifndef BVH_NODE_H
#define BVH_NODE_H
#include "Hittable.h"
#include "HittableList.h"
#include "AABB.h"
#include <algorithm>


/**
 * A hierarchical data structure designated to optimize ray-world intersections.
 *
 * This is intended to reduce the complexity of intersecting a ray with a scene of many objects to a complexity of log(n).
 * This performs best in scenes with large amounts of objects, or scenes where primitive intersection calculations can be expensive.
 * The overhead cost incurred by its usage will slow down rendering of scenes with fewer objects.
 */
class BVH_Node final : public Hittable {
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
    explicit BVH_Node(HittableList collection) : BVH_Node(collection.get_objects(), 0,
                                                          collection.get_objects().size()) {
    };

    /**
     * A verbose constructor for the BVH.
     *
     * @param objects List of objects to be built into the BVH.
     * @param start Beginning index of objects.
     * @param end Last index of objects.
     */
    BVH_Node(std::vector<shared_ptr<Hittable> > &objects, const size_t start, const size_t end) {
        // Build bounding box of source objects
        set_bounding_box({});
        for (size_t object_index = start; object_index < end; object_index++) {
            set_bounding_box(AABB(get_bounding_box(), objects[object_index]->BoundingBox()));
        }
        const int axis = get_bounding_box().LongestAxis();

        auto comparator = (axis == 0)
                              ? box_x_compare
                              : (axis == 1)
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
        bool hit_right = get_right()->Hit(
            ray, Interval(rayTime.get_min(), hit_left ? record.get_time() : rayTime.get_max()), record);

        return hit_left || hit_right;
    };

    [[nodiscard]] AABB BoundingBox() const override {
        return get_bounding_box();
    };

    /**
     * Compares two objects for sorting logic.
     *
     * @param a First object to be tested.
     * @param b Second object to be tested.
     * @param axis_index Integer corresponding to the axis of sorting.
     * @return Which object has a lesser position. (Required for sorting algorithm)
     */
    static bool box_compare(const shared_ptr<Hittable> &a, const shared_ptr<Hittable> &b, const int axis_index) {
        auto a_axis_interval = a->BoundingBox().AxisInterval(axis_index);
        auto b_axis_interval = b->BoundingBox().AxisInterval(axis_index);
        return a_axis_interval.get_min() < b_axis_interval.get_min();
    }

    /**
     * Compares two objects on the x-axis for sorting logic.
     *
     * @param a First object to be tested.
     * @param b Second object to be tested.
     * @return Which object has a lesser x position.
     */
    static bool box_x_compare(const shared_ptr<Hittable> &a, const shared_ptr<Hittable> &b) {
        return box_compare(a, b, 0);
    }

    /**
     * Compares two objects on the y-axis for sorting logic.
     *
     * @param a First object to be tested.
     * @param b Second object to be tested.
     * @return Which object has a lesser y position.
     */
    static bool box_y_compare(const shared_ptr<Hittable> &a, const shared_ptr<Hittable> &b) {
        return box_compare(a, b, 1);
    }

    /**
     * Compares two objects on the z-axis for sorting logic.
     *
     * @param a First object to be tested.
     * @param b Second object to be tested.
     * @return Which object has a lesser z position.
     */
    static bool box_z_compare(const shared_ptr<Hittable> &a, const shared_ptr<Hittable> &b) {
        return box_compare(a, b, 2);
    }

    // Getters
    /**
     * Gets the pointer to the left-side object.
     * @return Pointer to left-side object.
     */
    [[nodiscard]] shared_ptr<Hittable> get_left() const {
        return left;
    }

    /**
     * Gets the pointer to the right-side object.
     *
     * @return Pointer to right-side object.
     */
    [[nodiscard]] shared_ptr<Hittable> get_right() const {
        return right;
    }

    /**
     * Gets the bounding box surrounding the BVH node.
     *
     * @return Bounding box surrounding the BVH node.
     */
    [[nodiscard]] AABB get_bounding_box() const {
        return bounding_box;
    }

    // Setters
    /**
     * Sets the left side object pointer.
     *
     * @param left left side object pointer.
     */
    void set_left(const shared_ptr<Hittable> &left) {
        this->left = left;
    }

    /**
     * Sets the right side object pointer.
     *
     * @param right right side object pointer.
     */
    void set_right(const shared_ptr<Hittable> &right) {
        this->right = right;
    }

    /**
     * Sets the bounding box of the BVH node.
     *
     * @param bounding_box Bounding box of the BVH node.
     */
    void set_bounding_box(const AABB &bounding_box) {
        this->bounding_box = bounding_box;
    }
};

#endif //BVH_NODE_H
