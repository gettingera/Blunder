#include "RenderTarget.h"
#include <vector>
#include <fstream>
#include <glm/vec3.hpp>

// Public members
RenderTarget::RenderTarget(int width, int height) {
    this->width = width;
    this->height = height;

    this->Initialize();
}

glm::vec3 RenderTarget::GetPixel(int x, int y) {
    return this->colors[y][x];
}

void RenderTarget::SetPixel(int x, int y, glm::vec3 color) {
    this->colors[y][x] = color;
}

void RenderTarget::WriteToFile(const std::string& filename) {
    std::ofstream file(filename);

    // PPM Header
    file << "P3\n" << this->width << " " << this->height << "\n255\n";

    // Generate PPM contents
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            // Get pixel
            glm::vec3 color = this->GetPixel(x, y);

            // Write integer converted color data to file
            file <<
                static_cast<int>(color.x) << " " <<
                static_cast<int>(color.y) << " " <<
                static_cast<int>(color.z) << "\n";
        }
    }

    file.close();
}

// Private members
void RenderTarget::Initialize() {
    this->colors = std::vector(height, std::vector<glm::vec3>(width, glm::vec3(0)));
}
