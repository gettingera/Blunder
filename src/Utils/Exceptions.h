#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <utility>

/**
 * Camera-specific exceptions useful for debugging and unit testing.
 */
class CameraException final : public std::exception {
    /// Custom error message the exception may choose to set upon throwing.
    std::string message;

public:
    /// Creates the new exception with a custom error message.
    explicit CameraException(std::string message) : message(std::move(message)) {}

    /// Use the new error message when throwing the exception.
    [[nodiscard]] const char *what() const noexcept override {
        return message.c_str();
    }
};

/**
 * Ray-specific exceptions useful for debugging and unit testing.
 */
class RayException final : public std::exception {
    /// Custom error message the exception may choose to set upon throwing.
    std::string message;

public:
    /// Creates the new exception with a custom error message.
    explicit RayException(std::string message) : message(std::move(message)) {}

    /// Use the new error message when throwing the exception.
    [[nodiscard]] const char *what() const noexcept override {
        return message.c_str();
    }
};

#endif //EXCEPTIONS_H
