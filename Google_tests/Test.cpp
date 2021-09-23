//
// Created by PC on 23.09.2021.
//
#include "gtest/gtest.h"
#include "../Limacon.h"
TEST(constructor, defaultConstructor)
{
    Prog2::Limacon a1;
    ASSERT_EQ(1, a1.getA());
    ASSERT_EQ(1, a1.getB());
}
TEST(constructor, initConstructors)
{
    Prog2::Limacon a(3, 4);
    ASSERT_EQ(3, a.getA());
    ASSERT_EQ(4, a.getB());
    Prog2::Limacon a1(-5, 6);
    ASSERT_EQ(-5, a1.getA());
    ASSERT_EQ(6, a1.getB());
}
TEST(methods, setters)
{
    Prog2::Limacon a;
    a.setAB(3.0, 4.0);
    ASSERT_EQ(3.0, a.getA());
    ASSERT_EQ(4.0, a.getB());
}
TEST(methods, distance)
{
    Prog2::Limacon a1;
    ASSERT_EQ(2, a1.distance(0));
    ASSERT_NEAR(1.5403, a1.distance(1), 0.0001);
    Prog2::Limacon a2(5, 4);
    ASSERT_EQ(9, a2.distance(0));
    ASSERT_NEAR(6.70151, a2.distance(1), 0.0001);
}
TEST(methods, shape)
{
    Prog2::Limacon a1;
    ASSERT_STREQ("Cardioid", a1.shape());
    Prog2::Limacon a2(5, 4);
    ASSERT_STREQ("Limacon has an inner loop", a2.shape());
    a2.setAB(6,7);
    ASSERT_STRNE("Limacon is convex", a2.shape());
}
TEST(methods, formula)
{
    Prog2::Limacon a1;
    ASSERT_STREQ("(x^2 + y^2 - 1.00x)^2 = 1.00^2(x^2 + y^2)\n", a1.formula());
    Prog2::Limacon a2(5, 4);
    ASSERT_STREQ("(x^2 + y^2 - 5.00x)^2 = 4.00^2(x^2 + y^2)\n", a2.formula());
    a2.setAB(6,7);
    ASSERT_STRNE("(x^2 + y^2 - 8.00x)^2 = 9.00^2(x^2 + y^2)\n", a2.formula());
}
TEST(methods, area)
{
    Prog2::Limacon a1;
    ASSERT_NEAR(1.5707, a1.area(), 0.0001);
    Prog2::Limacon a2(5, 4);
    ASSERT_NEAR(10.6557, a2.area(), 0.0001);
    Prog2::Limacon a3(4, 4);
    ASSERT_NEAR(25.1327, a3.area(), 0.0001);
}
TEST(methods, curvatureRadius)
{
    Prog2::Limacon a1;
    ASSERT_NEAR(1.2879, (a1.curvatureRadius())[0], 0.0001);
    ASSERT_NEAR(0.3450, (a1.curvatureRadius())[1], 0.0001);
    Prog2::Limacon a2(5, 4);
    ASSERT_NEAR(5.5433, (a2.curvatureRadius())[0], 0.0001);
    ASSERT_NEAR(1.2630, (a2.curvatureRadius())[1], 0.0001);
    Prog2::Limacon a3(4, 6);
    ASSERT_NEAR(7.002, (a3.curvatureRadius())[0], 0.0001);
    ASSERT_NEAR(8.8199, (a3.curvatureRadius())[1], 0.0001);
    ASSERT_NEAR(6.6286, (a3.curvatureRadius())[2], 0.0001);
    ASSERT_NEAR(4.4723, (a3.curvatureRadius())[3], 0.0001);
}