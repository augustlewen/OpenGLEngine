#include "pch.h"
#include "../Maths/Vector3.h"

TEST(Vector3_Constructor, Assigns_All_Components) {
    Vector3 v(3, 4, 5);
    EXPECT_EQ(v.x, 3);
    EXPECT_EQ(v.y, 4);
    EXPECT_EQ(v.z, 5);
}

TEST(Vector3_EqualityComparison, Returns_True_For_Equal_Values) {
    EXPECT_TRUE(Vector3(4, 5, 6) == Vector3(4, 5, 6));
}

TEST(Vector3_EqualityComparison, Returns_False_For_Inequal_Values) {
    EXPECT_FALSE(Vector3(1, 2, 3) == Vector3(3, 2, 1));
}

TEST(Vector3_InequalityComparison, Returns_True_For_Inequal_Values) {
    EXPECT_TRUE(Vector3(1, 2, 3) != Vector3(3, 2, 1));
}

TEST(Vector3_InequalityComparison, Returns_False_For_Equal_Values) {
    EXPECT_FALSE(Vector3(1, 2, 3) != Vector3(1, 2, 3));
}


TEST(Vector3_Negate, Invert_Values) {
    EXPECT_EQ(-Vector3(1, 2, 3), Vector3(-1, -2, -3));
}

TEST(Vector3_Addition, Add_Vector_To_Vector) {
    EXPECT_EQ(Vector3(1, 2, 3) + Vector3(1, 2, 3), Vector3(2, 4, 6));
}

TEST(Vector3_ScalarMultiplication, Scales_All_Values) {
    EXPECT_EQ(Vector3(3, 4, 5) * 2, Vector3(6, 8, 10));
}

TEST(Vector3_ScalarDivision, Inverse_Scale_All_Values) {
    EXPECT_EQ(Vector3(6, 8, 10) / 2, Vector3(3, 4, 5));
}

TEST(Vector3_Subtraction, Subtracts_all_values) {
    EXPECT_EQ(Vector3(9, 5, 7) - Vector3(1, 2, 3), Vector3(8, 3, 4));
}

TEST(Vector3_Magnitude, Returns_Magnitude_For_Vectors) {
    EXPECT_FLOAT_EQ(Vector3(5, -3, 2).Magnitude(), sqrt(38));
}


TEST(Vector3_Normalize, Returns_Normalize_For_Vectors) {
    Vector3 normalized = Vector3(5, -3, 2).Normalize();
    Vector3 expected(5.0 / sqrt(38), -3.0 / sqrt(38), 2.0 / sqrt(38));
    EXPECT_EQ(normalized, expected);
}

TEST(Vector3_SqrtMagnitude, Returns_Sqrt_Magnitude_For_Vectors) {
    EXPECT_FLOAT_EQ(Vector3(5, -3, 2).SquareMagnitude(), sqrt(sqrt(38)));
}

TEST(Vector3_DotProduct, Returns_DotProduct_For_2_Vectors) {
    EXPECT_FLOAT_EQ(Vector3::DotProduct(Vector3(1, 1, 1), Vector3(5, 5, 5)), 15);
}