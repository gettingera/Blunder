#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <utility>

/**
 * A simplified BaseException class that provides an easier interface for registering custom exceptions.
 */
class BaseException : public std::exception {
    /// Custom error message the exception may choose to set upon throwing.
    std::string message;

public:
    /// Sets the message
    explicit BaseException(std::string what) : message(std::move(what)) {}

    /// Function that returns the error message
    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
};

/**
 * Camera-specific exceptions useful for debugging and unit testing.
 */
class CameraException final : public BaseException {
public:
    explicit CameraException(std::string message) : BaseException(std::move(message)) {};
};

/**
 * Ray-specific exceptions useful for debugging and unit testing.
 */
class RayException final : public BaseException {
public:
    explicit RayException(std::string message) : BaseException(std::move(message)) {};
};

/**
 * Color-specific exceptions useful for debugging and unit testing.
 * Ensures proper color standards are utilized throughout.
 */
class ColorException final : public BaseException {
public:
    explicit ColorException(std::string message) : BaseException(std::move(message)) {};
};

/**
 * RenderTarget-specific exceptions useful for debugging and unit testing.
 */
class RenderTargetException final : public BaseException {
public:
    explicit RenderTargetException(std::string message) : BaseException(std::move(message)) {};
};

/**
 * Sphere-specific exceptions useful for debugging and unit testing.
 */
class SphereException final : public BaseException {
public:
    explicit SphereException(std::string message) : BaseException(std::move(message)) {};
};

/**
 * SphereList-specific exceptions useful for debugging and unit testing.
 */
class SphereListException final : public BaseException {
public:
    explicit SphereListException(std::string message) : BaseException(std::move(message)) {};
};

/**
 * HitRecord-specific exceptions useful for debugging and unit testing.
 */
class HitRecordException final : public BaseException {
public:
    explicit HitRecordException(std::string message) : BaseException(std::move(message)) {};
};

#endif //EXCEPTIONS_H
