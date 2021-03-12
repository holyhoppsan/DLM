// clang-format off
#include "gtest/gtest.h"
// clang-format on

#include "dlm/vector3.hpp"

class Vector3Test : public ::testing::Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(Vector3Test, zero_set_elements_to_zero) {
  dlm::vector::Vector3F new_vector{2.0f, 3.0f, 4.0};

  new_vector.Zero();
  ASSERT_EQ(new_vector.x, -0.0f);
  ASSERT_EQ(new_vector.y, -0.0f);
  ASSERT_EQ(new_vector.z, -0.0f);
}

TEST_F(Vector3Test, unary_minus) {
  const dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  const dlm::vector::Vector3F negated_vector = -new_vector;

  ASSERT_EQ(negated_vector.x, -2.0f);
  ASSERT_EQ(negated_vector.y, -2.0f);
  ASSERT_EQ(negated_vector.z, -2.0f);
}

TEST_F(Vector3Test, minus_scalar) {
  const dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  const dlm::vector::Vector3F negated_vector = new_vector - 2.0f;

  ASSERT_EQ(negated_vector.x, 0.0f);
  ASSERT_EQ(negated_vector.y, 0.0f);
  ASSERT_EQ(negated_vector.z, 0.0f);
}

TEST_F(Vector3Test, minus_vector) {
  const dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  const dlm::vector::Vector3F negated_vector = new_vector - new_vector;

  ASSERT_EQ(negated_vector.x, 0.0f);
  ASSERT_EQ(negated_vector.y, 0.0f);
  ASSERT_EQ(negated_vector.z, 0.0f);
}

TEST_F(Vector3Test, minus_scalar_assign) {
  dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  new_vector -= 2.0f;

  ASSERT_EQ(new_vector.x, 0.0f);
  ASSERT_EQ(new_vector.y, 0.0f);
  ASSERT_EQ(new_vector.z, 0.0f);
}

TEST_F(Vector3Test, minus_vector_assign) {
  dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  new_vector -= new_vector;

  ASSERT_EQ(new_vector.x, 0.0f);
  ASSERT_EQ(new_vector.y, 0.0f);
  ASSERT_EQ(new_vector.z, 0.0f);
}

TEST_F(Vector3Test, add_scalar) {
  dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  new_vector = new_vector + 2.0f;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
  ASSERT_EQ(new_vector.z, 4.0f);
}

TEST_F(Vector3Test, add_vector) {
  dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  new_vector = new_vector + new_vector;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
  ASSERT_EQ(new_vector.z, 4.0f);
}

TEST_F(Vector3Test, add_scalar_assign) {
  dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  new_vector += 2.0f;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
  ASSERT_EQ(new_vector.z, 4.0f);
}

TEST_F(Vector3Test, add_vector_assign) {
  dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  new_vector += new_vector;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
  ASSERT_EQ(new_vector.z, 4.0f);
}

TEST_F(Vector3Test, mul_scalar) {
  const dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  const dlm::vector::Vector3F negated_vector = new_vector * 2.0f;

  ASSERT_EQ(negated_vector.x, 4.0f);
  ASSERT_EQ(negated_vector.y, 4.0f);
  ASSERT_EQ(negated_vector.z, 4.0f);
}

TEST_F(Vector3Test, mul_vector) {
  const dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  const dlm::vector::Vector3F negated_vector = new_vector * new_vector;

  ASSERT_EQ(negated_vector.x, 4.0f);
  ASSERT_EQ(negated_vector.y, 4.0f);
  ASSERT_EQ(negated_vector.z, 4.0f);
}

TEST_F(Vector3Test, mul_scalar_assign) {
  dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  new_vector *= 2.0f;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
  ASSERT_EQ(new_vector.z, 4.0f);
}

TEST_F(Vector3Test, mul_vector_assign) {
  dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  new_vector *= new_vector;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
  ASSERT_EQ(new_vector.z, 4.0f);
}

TEST_F(Vector3Test, div_scalar) {
  const dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  const dlm::vector::Vector3F negated_vector = new_vector / 2.0f;

  ASSERT_EQ(negated_vector.x, 1.0f);
  ASSERT_EQ(negated_vector.y, 1.0f);
  ASSERT_EQ(negated_vector.z, 1.0f);
}

TEST_F(Vector3Test, div_vector) {
  const dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  const dlm::vector::Vector3F negated_vector = new_vector / new_vector;

  ASSERT_EQ(negated_vector.x, 1.0f);
  ASSERT_EQ(negated_vector.y, 1.0f);
  ASSERT_EQ(negated_vector.z, 1.0f);
}

TEST_F(Vector3Test, div_scalar_assign) {
  dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  new_vector /= 2.0f;

  ASSERT_EQ(new_vector.x, 1.0f);
  ASSERT_EQ(new_vector.y, 1.0f);
  ASSERT_EQ(new_vector.z, 1.0f);
}

TEST_F(Vector3Test, div_vector_assign) {
  dlm::vector::Vector3F new_vector{2.0f, 2.0f, 2.0f};
  new_vector /= new_vector;

  ASSERT_EQ(new_vector.x, 1.0f);
  ASSERT_EQ(new_vector.y, 1.0f);
  ASSERT_EQ(new_vector.z, 1.0f);
}

TEST_F(Vector3Test, dot_positive) {
  dlm::vector::Vector3F new_vector{3.0f, 4.0f, 5.0f};
  auto result = new_vector | new_vector;

  ASSERT_EQ(result, 50.0f);
}

TEST_F(Vector3Test, dot_negative) {
  dlm::vector::Vector3F new_vector{-3.0f, -4.0f, -5.0f};
  auto result = new_vector | new_vector;

  ASSERT_EQ(result, 50.0f);
}

TEST_F(Vector3Test, dot_normalized_equals_cosine) {
  dlm::vector::Vector3F right{4.0f, 0.0f, 0.0f};
  right.Normalize();
  dlm::vector::Vector3F left{-4.0f, 0.0f, 0.0f};
  left.Normalize();
  dlm::vector::Vector3F up{0.0f, 4.0f, 0.0f};
  up.Normalize();
  auto result = right | up;

  ASSERT_EQ(result, 0.0f);

  result = right | left;

  ASSERT_EQ(result, -1.0f);
}

TEST_F(Vector3Test, subscript_operator_const_returns_expected_element) {
  const dlm::vector::Vector3F new_vector{3.0f, 4.0f, 5.0f};

  ASSERT_EQ(new_vector[0], 3.0f);
  ASSERT_EQ(new_vector[1], 4.0f);
  ASSERT_EQ(new_vector[2], 5.0f);
}

TEST_F(Vector3Test, subscript_operator_returns_expected_element) {
  dlm::vector::Vector3F new_vector{3.0f, 4.0f, 5.0f};

  ASSERT_EQ(new_vector[0], 3.0f);
  ASSERT_EQ(new_vector[1], 4.0f);
  ASSERT_EQ(new_vector[2], 5.0f);
}
