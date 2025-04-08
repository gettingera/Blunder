#include <Utils/Headers.h>
#include <Utils/Importer.h>

namespace BlunderTest {
    static void TestImporterRenderFile() {
        std::cout << "\t[Importer] Testing RenderFile..." << std::endl;

        try {
            Importer::RenderFile("SceneFileSchema.blunder", "test.ppm");
        } catch (...) {
            assert(false);
        }

        try {
            Importer::RenderFile("SceneFileSchemaBad.blunder", "test.ppm");
            assert(false);
        } catch (...) {
            assert(true);
        }

        try {
            Importer::RenderFile("", "");
            assert(false);
        } catch (ImporterException &e) {
            assert(true);
        } catch (...) {
            assert(false);
        }
    }

    static void TestImporterAll() {
        std::cout << "[Unit Test] Testing Importer..." << std::endl;
        TestImporterRenderFile();
    }
}
