#include <gtest/gtest.h>

// Funktion zum Testen
int add(int a, int b) {
    return a + b;
}

TEST(AdditionTest, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(AdditionTest, NegativeNumbers) {
    EXPECT_EQ(add(-1, -1), -2);
}

TEST(AdditionTest, MixedSigns) {
    EXPECT_EQ(add(-1, 1), 0);
}