#include <gtest/gtest.h>
#include <core/Vector3.h>

TEST(Vector3, DefaultConstructor)
{
  cpv::Vector3 v;

  ASSERT_EQ(v.getX(), 0.0);
  ASSERT_EQ(v.getY(), 0.0);
  ASSERT_EQ(v.getZ(), 0.0);
}

TEST(Vector3, BasicConstructor)
{
  cpv::Vector3 v(1.0, 2.0, 3.0);

  ASSERT_EQ(v.getX(), 1.0);
  ASSERT_EQ(v.getY(), 2.0);
  ASSERT_EQ(v.getZ(), 3.0);
}

TEST(Vector3, Setters)
{
  cpv::Vector3 v;
  v.setX(1.0);
  v.setY(2.0);
  v.setZ(3.0);

  ASSERT_DOUBLE_EQ(v.getX(), 1.0);
  ASSERT_DOUBLE_EQ(v.getY(), 2.0);
  ASSERT_DOUBLE_EQ(v.getZ(), 3.0);
}

TEST(Vector3, GetMagnitude)
{
  cpv::Vector3 v(3.0, 4.0, 5.0);

  ASSERT_DOUBLE_EQ(v.getMagnitude(), 7.0710678118654755);
}

TEST(Vector3, operatorPlus)
{
  cpv::Vector3 v1(1.0, 2.0, 3.0);
  cpv::Vector3 v2(3.0, 4.0, 5.0);
  cpv::Vector3 v3 = v1 + v2;

  ASSERT_DOUBLE_EQ(v3.getX(), 4.0);
  ASSERT_DOUBLE_EQ(v3.getY(), 6.0);
  ASSERT_DOUBLE_EQ(v3.getZ(), 8.0);
}

TEST(Vector3, operatorMinus)
{
  cpv::Vector3 v1(1.0, 2.0, 3.0);
  cpv::Vector3 v2(3.0, 4.0, 5.0);
  cpv::Vector3 v3 = v1 - v2;

  ASSERT_DOUBLE_EQ(v3.getX(), -2.0);
  ASSERT_DOUBLE_EQ(v3.getY(), -2.0);
  ASSERT_DOUBLE_EQ(v3.getZ(), -2.0);
}

TEST(Vector3, operatorMul)
{
  cpv::Vector3 v1(1.0, 2.0, 3.0);
  cpv::Vector3 v2 = v1 * 2.0;

  ASSERT_DOUBLE_EQ(v2.getX(), 2.0);
  ASSERT_DOUBLE_EQ(v2.getY(), 4.0);
  ASSERT_DOUBLE_EQ(v2.getZ(), 6.0);
}

TEST(Vector3, operatorEqual)
{
  cpv::Vector3 v1(1.0, 2.0, 3.0);
  cpv::Vector3 v2(1.0, 2.0, 3.0);
  cpv::Vector3 v3(3.0, 4.0, 5.0);

  ASSERT_TRUE(v1 == v2);
  ASSERT_FALSE(v1 == v3);
}

TEST(Vector3, operatorNotEqual)
{
  cpv::Vector3 v1(1.0, 2.0, 3.0);
  cpv::Vector3 v2(1.0, 2.0, 3.0);
  cpv::Vector3 v3(3.0, 4.0, 5.0);

  ASSERT_FALSE(v1 != v2);
  ASSERT_TRUE(v1 != v3);
}
