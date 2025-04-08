#include "Importer.h"
#include <fstream>
#include <sstream>
#include <Renderer/Renderer.h>
#include <Renderer/RenderTarget.h>

void Importer::RenderFile(const std::string &fileNameIn, const std::string &fileNameOut) {
    // Ensure fileNameIn is non-empty
    if (fileNameIn.empty())
        throw ImporterException("Importer::RenderFile: empty scene file name");

    // Ensure fileNameOut is non-empty
    if (fileNameOut.empty())
        throw ImporterException("Importer::RenderFile: empty output file name");

    // Ensure no weird name equals weirdness
    if (fileNameIn == fileNameOut)
        throw ImporterException("Importer::RenderFile: scene file name cannot be the same as output file name");

    // Try to open the file
    std::ifstream file(fileNameIn);
    if (!file.is_open())
        throw ImporterException("Importer::RenderFile: cannot open file (does the file exist?)");

    // Line currently being used throughout
    std::string line;

    // Require Blunder header
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        if (line != "#BLUNDER")
            throw ImporterException("Importer::RenderFile: no #BLUNDER header");

        break;
    }

    // SETTINGS
    int screenWidth, screenHeight, samples, bounces;

    // Require settings header
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        if (line != "#SETTINGS")
            throw ImporterException("Importer::RenderFile: no #SETTINGS header");

        break;
    }

    // Get width
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::istringstream(line) >> line >> screenWidth;
        if (line != "screen_width")
            throw ImporterException("Importer::RenderFile: expected screen_width");

        break;
    }

    // Get height
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::istringstream(line) >> line >> screenHeight;
        if (line != "screen_height")
            throw ImporterException("Importer::RenderFile: expected screen_height");

        break;
    }

    // Get samples
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::istringstream(line) >> line >> samples;
        if (line != "samples")
            throw ImporterException("Importer::RenderFile: expected samples");

        break;
    }

    // Get bounces
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::istringstream(line) >> line >> bounces;
        if (line != "bounces")
            throw ImporterException("Importer::RenderFile: expected bounces");

        break;
    }

    // CAMERA
    vec3 camera_position, look_at, up_direction;
    float fov;

    // Require camera header
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        if (line != "#CAMERA")
            throw ImporterException("Importer::RenderFile: no #CAMERA header");

        break;
    }

    // Get position
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::istringstream(line) >> line >> camera_position.x >> camera_position.y >> camera_position.z;
        if (line != "position")
            throw ImporterException("Importer::RenderFile: expected camera position");

        break;
    }

    // Get look_at
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::istringstream(line) >> line >> look_at.x >> look_at.y >> look_at.z;
        if (line != "look_at")
            throw ImporterException("Importer::RenderFile: expected camera look_at");

        break;
    }

    // Get fov
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::istringstream(line) >> line >> fov;
        if (line != "fov")
            throw ImporterException("Importer::RenderFile: expected camera fov");

        break;
    }

    // Get up_direction
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::istringstream(line) >> line >> up_direction.x >> up_direction.y >> up_direction.z;
        if (line != "up_direction")
            throw ImporterException("Importer::RenderFile: expected camera up_direction");

        break;
    }// Ignore empty lines

    // COLORS
    std::unordered_map<std::string, Color> colorMap;

    // Require color header
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        if (line != "#COLORS")
            throw ImporterException("Importer::RenderFile: no #COLORS header");

        break;
    }

    // Get color definitions
    while (std::getline(file, line) && line != "#SPHERES") {
        if (line.empty())
            continue;

        std::istringstream ss(line);
        std::string name;
        float r, g, b;

        if (!(ss >> name >> r >> g >> b))
            throw ImporterException("Importer::RenderFile: invalid color definition");

        colorMap[name] = Color(vec3(r, g, b));
    }

    // SPHERES
    auto spheres = make_shared<SphereList>();

    // Get sphere definitions
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        
        std::istringstream ss(line);
        float x, y, z, radius;
        std::string colorName;
        
        if (!(ss >> x >> y >> z >> colorName >> radius))
            throw ImporterException("Importer::RenderFile: invalid sphere definition");

        if (!colorMap.count(colorName))
            throw ImporterException("Importer::RenderFile: undefined color used in sphere");

        auto position = vec3(x, y, z);
        Color color(colorMap[colorName]);
        spheres->Add(make_shared<Sphere>(position, radius, color));
    }

    // ATTEMPT TO RENDER
    auto renderTarget = make_shared<RenderTarget>(screenWidth, screenHeight);

    auto camera = make_shared<Camera>(camera_position, look_at);
    camera->set_fov(fov);
    camera->set_up_direction(up_direction);

    auto renderer = Renderer(samples, bounces);
    renderer.render(spheres, camera, renderTarget);
    renderTarget->writeToFile(fileNameOut);
}
