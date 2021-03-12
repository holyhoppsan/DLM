// clang-format off
#include "gtest/gtest.h"
// clang-format on

#include "dlm/vector2.hpp"

class Vector2Test : public ::testing::Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(Vector2Test, zero_set_elements_to_zero) {
  dlm::vector::Vector2F new_vector{2.0f, 3.0f};

  new_vector.Zero();
  ASSERT_EQ(new_vector.x, -0.0f);
  ASSERT_EQ(new_vector.y, -0.0f);
}

TEST_F(Vector2Test, unary_minus) {
  const dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  const dlm::vector::Vector2F negated_vector = -new_vector;

  ASSERT_EQ(negated_vector.x, -2.0f);
  ASSERT_EQ(negated_vector.y, -2.0f);
}

TEST_F(Vector2Test, minus_scalar) {
  const dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  const dlm::vector::Vector2F negated_vector = new_vector - 2.0f;

  ASSERT_EQ(negated_vector.x, 0.0f);
  ASSERT_EQ(negated_vector.y, 0.0f);
}

TEST_F(Vector2Test, minus_vector) {
  const dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  const dlm::vector::Vector2F negated_vector = new_vector - new_vector;

  ASSERT_EQ(negated_vector.x, 0.0f);
  ASSERT_EQ(negated_vector.y, 0.0f);
}

TEST_F(Vector2Test, minus_scalar_assign) {
  dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  new_vector -= 2.0f;

  ASSERT_EQ(new_vector.x, 0.0f);
  ASSERT_EQ(new_vector.y, 0.0f);
}

TEST_F(Vector2Test, minus_vector_assign) {
  dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  new_vector -= new_vector;

  ASSERT_EQ(new_vector.x, 0.0f);
  ASSERT_EQ(new_vector.x, 0.0f);
}

TEST_F(Vector2Test, add_scalar) {
  dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  new_vector = new_vector + 2.0f;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
}

TEST_F(Vector2Test, add_vector) {
  dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  new_vector = new_vector + new_vector;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
}

TEST_F(Vector2Test, add_scalar_assign) {
  dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  new_vector += 2.0f;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
}

TEST_F(Vector2Test, add_vector_assign) {
  dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  new_vector += new_vector;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
}

TEST_F(Vector2Test, mul_scalar) {
  const dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  const dlm::vector::Vector2F negated_vector = new_vector * 2.0f;

  ASSERT_EQ(negated_vector.x, 4.0f);
  ASSERT_EQ(negated_vector.y, 4.0f);
}

TEST_F(Vector2Test, mul_vector) {
  const dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  const dlm::vector::Vector2F negated_vector = new_vector * new_vector;

  ASSERT_EQ(negated_vector.x, 4.0f);
  ASSERT_EQ(negated_vector.y, 4.0f);
}

TEST_F(Vector2Test, mul_scalar_assign) {
  dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  new_vector *= 2.0f;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
}

TEST_F(Vector2Test, mul_vector_assign) {
  dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  new_vector *= new_vector;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
}

TEST_F(Vector2Test, div_scalar) {
  const dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  const dlm::vector::Vector2F negated_vector = new_vector / 2.0f;

  ASSERT_EQ(negated_vector.x, 1.0f);
  ASSERT_EQ(negated_vector.y, 1.0f);
}

TEST_F(Vector2Test, div_vector) {
  const dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  const dlm::vector::Vector2F negated_vector = new_vector / new_vector;

  ASSERT_EQ(negated_vector.x, 1.0f);
  ASSERT_EQ(negated_vector.y, 1.0f);
}

TEST_F(Vector2Test, div_scalar_assign) {
  dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  new_vector /= 2.0f;

  ASSERT_EQ(new_vector.x, 1.0f);
  ASSERT_EQ(new_vector.y, 1.0f);
}

TEST_F(Vector2Test, div_vector_assign) {
  dlm::vector::Vector2F new_vector{2.0f, 2.0f};
  new_vector /= new_vector;

  ASSERT_EQ(new_vector.x, 1.0f);
  ASSERT_EQ(new_vector.x, 1.0f);
}

TEST_F(Vector2Test, dot_positive) {
  dlm::vector::Vector2F new_vector{3.0f, 4.0f};
  auto result = new_vector | new_vector;

  ASSERT_EQ(result, 25.0f);
}

TEST_F(Vector2Test, dot_negative) {
  dlm::vector::Vector2F new_vector{-3.0f, -4.0f};
  auto result = new_vector | new_vector;

  ASSERT_EQ(result, 25.0f);
}

TEST_F(Vector2Test, dot_normalized_equals_cosine) {
  dlm::vector::Vector2F right{4.0f, 0.0f};
  right.Normalize();
  dlm::vector::Vector2F left{-4.0f, 0.0f};
  left.Normalize();
  dlm::vector::Vector2F up{0.0f, 4.0f};
  up.Normalize();
  auto result = right | up;

  ASSERT_EQ(result, 0.0f);

  result = right | left;

  ASSERT_EQ(result, -1.0f);
}

TEST_F(Vector2Test, subscript_operator_const_returns_expected_element) {
  const dlm::vector::Vector2F new_vector{3.0f, 4.0f};

  ASSERT_EQ(new_vector[0], 3.0f);
  ASSERT_EQ(new_vector[1], 4.0f);
}

TEST_F(Vector2Test, subscript_operator_returns_expected_element) {
  dlm::vector::Vector2F new_vector{3.0f, 4.0f};

  ASSERT_EQ(new_vector[0], 3.0f);
  ASSERT_EQ(new_vector[1], 4.0f);
}
