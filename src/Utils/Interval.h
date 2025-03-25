#ifndef INTERVAL_H
#define INTERVAL_H


class Interval {
public:
    // Constructors
    Interval() : min(+infinity), max(-infinity) {
    } // Default interval is empty

    Interval(const double min, const double max) {
        set_min(min);
        set_max(max);
    }

    // Methods
    [[nodiscard]] double size() const {
        return get_max() - get_min();
    }

    [[nodiscard]] bool contains(const double x) const {
        return get_min() <= x && x <= get_max();
    }

    [[nodiscard]] bool surrounds(const double x) const {
        return get_min() < x && x < get_max();
    }

    // Getters
    [[nodiscard]] double get_min() const {
        return min;
    }

    [[nodiscard]] double get_max() const {
        return max;
    }

    // Setters
    void set_min(const double min) {
        this->min = min;
    }

    void set_max(const double max) {
        this->max = max;
    }

    // Static intervals, useful later
    static const Interval empty, universe;

private:
    // Attributes
    double min{}, max{};
};


const Interval Interval::empty = Interval(+infinity, -infinity);
const Interval Interval::universe = Interval(-infinity, +infinity);

#endif //INTERVAL_H
