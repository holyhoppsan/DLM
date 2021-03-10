// clang-format off
#include "gtest/gtest.h"
// clang-format on

#include "dlm/geometricfunctions.hpp"
#include "dlm/vector2.hpp"

class GeometricFunctionsTest : public ::testing::Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(GeometricFunctionsTest, normalize_return_vector2_with_length_one) {
  dlm::vector::Vector2F new_vector{2.0f, 3.0f};

  const auto normalized = dlm::vector::Normalize(new_vector);
  ASSERT_EQ(dlm::vector::Length(normalized), 1.0f);
}

TEST_F(GeometricFunctionsTest, dot_positive) {
  dlm::vector::Vector2F new_vector{3.0f, 4.0f};
  auto result = dlm::vector::Dot(new_vector, new_vector);

  ASSERT_EQ(result, 25.0f);
}

TEST_F(GeometricFunctionsTest, dot_negative) {
  dlm::vector::Vector2F new_vector{-3.0f, -4.0f};
  auto result = dlm::vector::Dot(new_vector, new_vector);

  ASSERT_EQ(result, 25.0f);
}

TEST_F(GeometricFunctionsTest, dot_normalized_equals_cosine) {
  dlm::vector::Vector2F right{4.0f, 0.0f};
  right.Normalize();
  dlm::vector::Vector2F left{-4.0f, 0.0f};
  left.Normalize();
  dlm::vector::Vector2F up{0.0f, 4.0f};
  up.Normalize();
  auto result = dlm::vector::Dot(right, up);

  ASSERT_EQ(result, 0.0f);

  result = dlm::vector::Dot(right, left);

  ASSERT_EQ(result, -1.0f);
}

TEST_F(GeometricFunctionsTest, distance) {
  dlm::vector::Vector2F right{3.0f, 0.0f};
  dlm::vector::Vector2F up{0.0f, 4.0f};

  ASSERT_EQ(dlm::vector::Distance(right, up), 5.0f);
}

TEST_F(GeometricFunctionsTest, distance_squared) {
  dlm::vector::Vector2F right{3.0f, 0.0f};
  dlm::vector::Vector2F up{0.0f, 4.0f};

  ASSERT_EQ(dlm::vector::DistanceSquared(right, up), 25.0f);
}

TEST_F(GeometricFunctionsTest, reflect) {
  dlm::vector::Vector2F inbound{3.0f, 3.0f};
  dlm::vector::Vector2F up{0.0f, 1.0f};

  dlm::vector::Vector2F reflected = dlm::vector::Reflect(inbound, up);

  ASSERT_EQ(reflected.x, -3.0f);
  ASSERT_EQ(reflected.y, 3.0f);
}

TEST_F(GeometricFunctionsTest, projection) {
  dlm::vector::Vector2F v1{3.0f, 3.0f};
  dlm::vector::Vector2F v2{4.0f, 0.0f};

  dlm::vector::Vector2F reflected = dlm::vector::Project(v1, v2);

  ASSERT_EQ(reflected.x, 3.0f);
  ASSERT_EQ(reflected.y, 0.0f);
}
