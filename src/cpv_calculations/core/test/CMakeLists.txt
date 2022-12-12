enable_testing()

add_executable(
    core_test
    FunctionCurve2Test.cpp
    FunctionCurve3Test.cpp
    Vector2Test.cpp
    Vector3Test.cpp
)

target_link_libraries(
  core_test
  GTest::gtest_main
)

target_include_directories(core_test PRIVATE ../include)

include(GoogleTest)
gtest_discover_tests(core_test)