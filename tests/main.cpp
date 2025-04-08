// Includes
#include "TestRay.cpp"
#include "TestCamera.cpp"
#include "TestSphere.cpp"
#include "TestRenderer.cpp"
#include "TestColor.cpp"
#include "TestHeaders.cpp"
#include "TestSphereList.cpp"
#include "TestRenderTarget.cpp"
#include "TestHitRecord.cpp"
#include "TestImporter.cpp"

// Main Function
int main() {
    std::cout << "[Unit Test] Beginning unit testing!" << std::endl;
    BlunderTest::TestHeadersAll();
    BlunderTest::TestRayAll();
    BlunderTest::TestCameraAll();
    BlunderTest::TestSphereAll();
    BlunderTest::TestRendererAll();
    BlunderTest::TestColorAll();
    BlunderTest::TestSphereListAll();
    BlunderTest::TestRenderTargetAll();
    BlunderTest::TestHitRecordAll();
    BlunderTest::TestImporterAll();
    std::cout << "[Unit Test] All tests pass!" << std::endl;
}
