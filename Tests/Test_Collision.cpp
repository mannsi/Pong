#include "../Collision.h"
#include "gtest/gtest.h"

TEST(CollisionTest, CollisionTestAll)
{
    int a_x = 10;
    int a_y = 10;
    int a_width = 10;
    int a_height = 10;

    int b1_x = 10;
    int b1_y = 30;
    int b1_width = 10;
    int b1_height = 10;

    int b2_x = 10;
    int b2_y = 20;
    int b2_width = 10;
    int b2_height = 1;

    int b3_x = 20;
    int b3_y = 10;
    int b3_width = 1;
    int b3_height = 10;

    int b4_x = 30;
    int b4_y = 10;
    int b4_width = 10;
    int b4_height = 10;

    int b5_x = 30;
    int b5_y = 30;
    int b5_width = 10;
    int b5_height = 10;

    int b6_x = 9;
    int b6_y = 10;
    int b6_width = 1;
    int b6_height = 10;

    int b7_x = 10;
    int b7_y = 9;
    int b7_width = 10;
    int b7_height = 1;

    int b8_x = 10;
    int b8_y = 10;
    int b8_width = 10;
    int b8_height = 10;

    int b9_x = 10;
    int b9_y = 15;
    int b9_width = 10;
    int b9_height = 5;

    int b10_x = 13;
    int b10_y = 13;
    int b10_width = 2;
    int b10_height = 2;

    int b11_x = 18;
    int b11_y = 2;
    int b11_width = 10;
    int b11_height = 10;

    int b12_x = 5;
    int b12_y = 15;
    int b12_width = 10;
    int b12_height = 10;

    BoxShape a(a_x, a_y, a_width, a_height);
    BoxShape b1(b1_x, b1_y, b1_width, b1_height);
    BoxShape b2(b2_x, b2_y, b2_width, b2_height);
    BoxShape b3(b3_x, b3_y, b3_width, b3_height);
    BoxShape b4(b4_x, b4_y, b4_width, b4_height);
    BoxShape b5(b5_x, b5_y, b5_width, b5_height);
    BoxShape b6(b6_x, b6_y, b6_width, b6_height);
    BoxShape b7(b7_x, b7_y, b7_width, b7_height);
    BoxShape b8(b8_x, b8_y, b8_width, b8_height);
    BoxShape b9(b9_x, b9_y, b9_width, b9_height);
    BoxShape b10(b10_x, b10_y, b10_width, b10_height);
    BoxShape b11(b11_x, b11_y, b11_width, b11_height);
    BoxShape b12(b12_x, b12_y, b12_width, b12_height);

    ASSERT_FALSE(collision_detection(a, b1)) << "Should not return collision. They are apart";
    ASSERT_FALSE(collision_detection(a, b2)) << "Should not return collision. They are adjacent";
    ASSERT_FALSE(collision_detection(a, b3)) << "Should not return collision. They are adjacent";
    ASSERT_FALSE(collision_detection(a, b4)) << "Should not return collision. They are apart";
    ASSERT_FALSE(collision_detection(a, b5)) << "Should not return collision. They are apart";
    ASSERT_FALSE(collision_detection(a, b6)) << "Should not return collision. They are adjacent";
    ASSERT_FALSE(collision_detection(a, b7)) << "Should not return collision. They are adjacent";
    ASSERT_TRUE(collision_detection(a, b8)) << "Should return collision. They are on top of each other";
    ASSERT_TRUE(collision_detection(a, b9)) << "Should return collision. They intersect";
    ASSERT_TRUE(collision_detection(a, b10)) << "Should return collision. One is inside the other";
    ASSERT_TRUE(collision_detection(a, b11)) << "Should return collision. They intersect";
    ASSERT_TRUE(collision_detection(a, b12)) << "Should return collision. They intersect";
}


