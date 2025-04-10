# Test Results

This documents the testing process and results.

# The Process

Tests in this codebase follow a common assertion-based strategy, with a suite of custom exceptions for defined graceful
failure.

Every function is checked against known good cases, edge cases, and known bad cases with defined behavior.

This behavior is defined in each header file (.h) in the source associated with each test.

Files and functions not tested are done so intentionally as their behavior derives directly from std, or testing them is
redundant as their implementation is a wrapper of other tested functions.

## Sunday, April 6th, 2025

All tests pass on current codebase.

Tests run include:

- BlunderTest::TestHeadersAll()
- BlunderTest::TestRayAll()
- BlunderTest::TestCameraAll()
- BlunderTest::TestSphereAll()
- BlunderTest::TestRendererAll()
- BlunderTest::TestColorAll()
- BlunderTest::TestSphereListAll()
- BlunderTest::TestRenderTargetAll()
- BlunderTest::TestHitRecordAll()

These tests were all developed according to the specifications highlighted in the source code file docstrings.

This sprint was heavy on testing as all cases had to be rigorously tested. Throughout the entire codebase, only one
function required modification to remain compliant.

This function was the case BlunderTest::TestHeadersRandomUnitVector(). A rewriting was ordered to generate unit vectors
whose length fell within compliance of the 1e-9 epsilon threshold.

## Tuesday, April 8th, 2025

All tests pass on the current codebase.

Tests run include:

- All previous unit tests
- BlunderTest::ImporterTestAll()

Go to [Home](https://github.com/gettingera/Blunder)
