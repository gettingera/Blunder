#ifndef RENDERTARGET_H
#define RENDERTARGET_H


#include <vector>
#include <string>
#include <glm/vec3.hpp>


class RenderTarget {
public:
    // Constructor
    RenderTarget(int width, int height);

    // Accessors
    glm::vec3 GetPixel(int x, int y);
    void SetPixel(int x, int y, glm::vec3 color);

    // Methods
    void WriteToFile(const std::string& filename);

private:
    // Attributes
    int width, height;
    std::vector<std::vector<glm::vec3>> colors;

    // Methods
    void Initialize();
};


#endif //RENDERTARGET_H
