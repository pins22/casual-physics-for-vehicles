#include <gtest/gtest.h>
#include "core/FunctionCurve2.h"


TEST(FunctionCurve2, DefaultConstructor)
{
  cpv::FunctionCurve2 f;

  ASSERT_EQ(f.getYValue(0), 0);
}

TEST(FunctionCurve2, ConstructorWithPoints)
{
  std::vector<cpv::Vector2> points;
  points.push_back(cpv::Vector2(0, 0));
  points.push_back(cpv::Vector2(1, 1));
  points.push_back(cpv::Vector2(2, 2));
  points.push_back(cpv::Vector2(3, 3));
  points.push_back(cpv::Vector2(4, 4));
  points.push_back(cpv::Vector2(5, 5));
  points.push_back(cpv::Vector2(6, 6));
  points.push_back(cpv::Vector2(7, 7));
  points.push_back(cpv::Vector2(8, 8));
  points.push_back(cpv::Vector2(9, 9));
  points.push_back(cpv::Vector2(10, 10));

  cpv::FunctionCurve2 f(std::move(points));

  ASSERT_EQ(f.getYValue(0), 0);
  ASSERT_EQ(f.getYValue(1), 1);
  ASSERT_EQ(f.getYValue(2), 2);
  ASSERT_EQ(f.getYValue(3), 3);
  ASSERT_EQ(f.getYValue(4), 4);
  ASSERT_EQ(f.getYValue(5), 5);
  ASSERT_EQ(f.getYValue(6), 6);
  ASSERT_EQ(f.getYValue(7), 7);
  ASSERT_EQ(f.getYValue(8), 8);
  ASSERT_EQ(f.getYValue(9), 9);
  ASSERT_EQ(f.getYValue(10), 10);
}
