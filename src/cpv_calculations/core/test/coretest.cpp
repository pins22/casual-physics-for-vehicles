#include "gtest/gtest.h"
#include "Vector2Test.hpp"
#include "Vector3Test.hpp"
#include "FunctionCurve2Test.hpp"
#include "FunctionCurve3Test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}