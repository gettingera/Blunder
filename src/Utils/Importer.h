#ifndef IMPORTER_H
#define IMPORTER_H
#include <Utils/Headers.h>

class Importer {
public:
    /**
     * Renders a Blunder scene file to the specified fileNameOut file.
     * @param fileNameIn Blunder scene file to be rendered.
     * @param fileNameOut Name of the file the image will be written to, in ppm format.
     *
     * @note Test Cases:\n
     * Importer::RenderFile("good.blunder", "out.ppm") -> renders good.blunder to out.ppm\n
     * Importer::RenderFile("bad.blunder", "out.ppm") -> ERROR: will throw an ImporterException (Blunder scene file is not exactly to format specifications)\n
     * Importer::RenderFile("", "out.ppm") -> ERROR: will throw an ImporterException (Blunder scene file name cannot be empty)\n
     * Importer::RenderFile("bad.blunder", "") -> ERROR: will throw an ImporterException (Output file name cannot be empty)\n
     */
    static void RenderFile(const std::string& fileNameIn, const std::string& fileNameOut);
};

#endif //IMPORTER_H
