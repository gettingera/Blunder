#ifndef INTERVAL_H
#define INTERVAL_H


/**
 * Represents an interval and some set operations defined mathematically.
 *
 * Useful for simplified interaction with ranges of values.
 */
class Interval {
    /// Minimum value the interval takes on.
    double min{};

    /// Maximum value the interval takes on.
    double max{};

public:
    // Constructors
    /**
     * Makes an empty interval.
     */
    Interval() : min(+infinity), max(-infinity) {
    }

    /**
     * Makes an interval ranging from the minimum value to the maximum value.
     *
     * @param min Minimum value.
     * @param max Maximum value.
     */
    Interval(const double min, const double max) {
        set_min(min);
        set_max(max);
    }

    // Methods
    /**
     * Gets length of interval.
     *
     * @return Length of interval.
     */
    [[nodiscard]] double size() const {
        return get_max() - get_min();
    }

    /**
     * Gets whether value is within interval.
     *
     * @param x Value to check.
     * @return Whether value is within interval.
     */
    [[nodiscard]] bool contains(const double x) const {
        return get_min() <= x && x <= get_max();
    }

    /**
     * Gets whether value is within interval. (identical to above)
     * @param x Value to check.
     * @return Whether value is within interval.
     */
    [[nodiscard]] bool surrounds(const double x) const {
        return get_min() < x && x < get_max();
    }

    /**
     * Clamps value to interval.
     *
     * @param x Value to clamp.
     * @return Value clamped to interval.
     */
    [[nodiscard]] double clamp(const double x) const {
        if (x < get_min()) return get_min();
        if (x > get_max()) return get_max();
        return x;
    }

    // Getters
    /**
     * Gets min.
     *
     * @return Minimum.
     */
    [[nodiscard]] double get_min() const {
        return min;
    }

    /**
     * Gets max.
     *
     * @return Maximum.
     */
    [[nodiscard]] double get_max() const {
        return max;
    }

    // Setters
    /**
     * Sets min.
     *
     * @param min Minimum.
     */
    void set_min(const double min) {
        this->min = min;
    }

    /**
     * Sets max.
     *
     * @param max Maximum.
     */
    void set_max(const double max) {
        this->max = max;
    }

    // Static intervals, useful later
    static const Interval empty;
    static const Interval universe;
};

/// Empty interval.
const Interval Interval::empty = Interval(+infinity, -infinity);

/// Universe.
const Interval Interval::universe = Interval(-infinity, +infinity);


#endif //INTERVAL_H
