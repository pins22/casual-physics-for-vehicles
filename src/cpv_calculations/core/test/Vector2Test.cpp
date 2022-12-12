#include <gtest/gtest.h>
#include <core/Vector2.h>

TEST(Vector2, DefaultConstructor)
{
  cpv::Vector2 v;

  ASSERT_EQ(v.getX(), 0.0);
  ASSERT_EQ(v.getY(), 0.0);
}

TEST(Vector2, BasicConstructor)
{
  cpv::Vector2 v(1.0, 2.0);

  ASSERT_EQ(v.getX(), 1.0);
  ASSERT_EQ(v.getY(), 2.0);
}

TEST(Vector2, Setters)
{
  cpv::Vector2 v;
  v.setX(1.0);
  v.setY(2.0);

  ASSERT_DOUBLE_EQ(v.getX(), 1.0);
  ASSERT_DOUBLE_EQ(v.getY(), 2.0);
}

TEST(Vector2, GetMagnitude)
{
  cpv::Vector2 v(3.0, 4.0);

  ASSERT_DOUBLE_EQ(v.getMagnitude(), 5.0);
}

TEST(Vector2, operatorPlus)
{
  cpv::Vector2 v1(1.0, 2.0);
  cpv::Vector2 v2(3.0, 4.0);
  cpv::Vector2 v3 = v1 + v2;

  ASSERT_DOUBLE_EQ(v3.getX(), 4.0);
  ASSERT_DOUBLE_EQ(v3.getY(), 6.0);
}

TEST(Vector2, operatorMinus)
{
  cpv::Vector2 v1(1.0, 2.0);
  cpv::Vector2 v2(3.0, 4.0);
  cpv::Vector2 v3 = v1 - v2;

  ASSERT_DOUBLE_EQ(v3.getX(), -2.0);
  ASSERT_DOUBLE_EQ(v3.getY(), -2.0);
}

TEST(Vector2, operatorMul)
{
  cpv::Vector2 v1(1.0, 2.0);
  cpv::Vector2 v2 = v1 * 2.0;

  ASSERT_DOUBLE_EQ(v2.getX(), 2.0);
  ASSERT_DOUBLE_EQ(v2.getY(), 4.0);
}

TEST(Vector2, operatorEqual)
{
  cpv::Vector2 v1(1.0, 2.0);
  cpv::Vector2 v2(1.0, 2.0);
  cpv::Vector2 v3(3.0, 4.0);

  ASSERT_TRUE(v1 == v2);
  ASSERT_FALSE(v1 == v3);
}

TEST(Vector2, operatorNotEqual)
{
  cpv::Vector2 v1(1.0, 2.0);
  cpv::Vector2 v2(1.0, 2.0);
  cpv::Vector2 v3(3.0, 4.0);

  ASSERT_FALSE(v1 != v2);
  ASSERT_TRUE(v1 != v3);
}

TEST(Vector2, operatorLessThan)
{
  cpv::Vector2 v1(1.0, 2.0);
  cpv::Vector2 v2(1.0, 2.0);
  cpv::Vector2 v3(3.0, 4.0);

  ASSERT_FALSE(v1 < v2);
  ASSERT_TRUE(v1 < v3);
}

TEST(Vector2, operatorGreaterThan)
{
  cpv::Vector2 v1(1.0, 2.0);
  cpv::Vector2 v2(1.0, 2.0);
  cpv::Vector2 v3(3.0, 4.0);

  ASSERT_FALSE(v1 > v2);
  ASSERT_FALSE(v1 > v3);
}

TEST(Vector2, operatorLessThanOrEqual)
{
  cpv::Vector2 v1(1.0, 2.0);
  cpv::Vector2 v2(1.0, 2.0);
  cpv::Vector2 v3(3.0, 4.0);

  ASSERT_TRUE(v1 <= v2);
  ASSERT_TRUE(v1 <= v3);
}

TEST(Vector2, operatorGreaterThanOrEqual)
{
  cpv::Vector2 v1(1.0, 2.0);
  cpv::Vector2 v2(1.0, 2.0);
  cpv::Vector2 v3(3.0, 4.0);

  ASSERT_TRUE(v1 >= v2);
  ASSERT_FALSE(v1 >= v3);
}
