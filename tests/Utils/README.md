# Utilities

Common utilities and classes seen throughout the project, and other items which are convenient to define centrally.

# Types of Utilities

- Headers
    - A file containing common headers and utility functions used throughout the project, useful for drastically
      shortening the amount of code and redundant headers in every file.
- Interval
    - A mathematically defined interval with a minimum and maximum used to perform binary set operations, and set
      inclusion and exclusion operations.
- Ray
    - A mathematically defined ray containing a position, direction, and a time value for motion blur. Also defines
      functions for ray parameterization (position * direction * t)