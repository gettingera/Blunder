// Includes
#include "Utils/Importer.h"

// Main method
int main(const int argc, char *argv[]) {
    if (argc != 3)
        throw ImporterException("Must pass an input file and specify an output file!");

    const std::string inputFile = argv[1];
    const std::string outputFile = argv[2];

    try {
        Importer::RenderFile(inputFile, outputFile);
    } catch (ImporterException &e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "ERROR: Unexpected exception. Stop." << std::endl;
    }

    return 0;
}
