// clang-format off
#include "gtest/gtest.h"
// clang-format on

#include "dlm/vector4.hpp"

class Vector4Test : public ::testing::Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(Vector4Test, zero_set_elements_to_zero) {
  dlm::vector::Vector4F new_vector{2.0f, 3.0f, 4.0, 5.0f};

  new_vector.Zero();
  ASSERT_EQ(new_vector.x, -0.0f);
  ASSERT_EQ(new_vector.y, -0.0f);
  ASSERT_EQ(new_vector.z, -0.0f);
  ASSERT_EQ(new_vector.w, -0.0f);
}

TEST_F(Vector4Test, movable) {
  dlm::vector::Vector4F new_vector{2.0f, 3.0f, 4.0f, 5.0f};

  dlm::vector::Vector4F moved_vector(std::move(new_vector));
  ASSERT_EQ(moved_vector.x, 2.0f);
  ASSERT_EQ(moved_vector.y, 3.0f);
  ASSERT_EQ(moved_vector.z, 4.0f);
  ASSERT_EQ(moved_vector.w, 5.0f);
}

TEST_F(Vector4Test, unary_minus) {
  const dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  const dlm::vector::Vector4F negated_vector = -new_vector;

  ASSERT_EQ(negated_vector.x, -2.0f);
  ASSERT_EQ(negated_vector.y, -2.0f);
  ASSERT_EQ(negated_vector.z, -2.0f);
  ASSERT_EQ(negated_vector.w, -2.0f);
}

TEST_F(Vector4Test, minus_scalar) {
  const dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  const dlm::vector::Vector4F negated_vector = new_vector - 2.0f;

  ASSERT_EQ(negated_vector.x, 0.0f);
  ASSERT_EQ(negated_vector.y, 0.0f);
  ASSERT_EQ(negated_vector.z, 0.0f);
  ASSERT_EQ(negated_vector.w, 0.0f);
}

TEST_F(Vector4Test, minus_vector) {
  const dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  const dlm::vector::Vector4F negated_vector = new_vector - new_vector;

  ASSERT_EQ(negated_vector.x, 0.0f);
  ASSERT_EQ(negated_vector.y, 0.0f);
  ASSERT_EQ(negated_vector.z, 0.0f);
  ASSERT_EQ(negated_vector.w, 0.0f);
}

TEST_F(Vector4Test, minus_scalar_assign) {
  dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  new_vector -= 2.0f;

  ASSERT_EQ(new_vector.x, 0.0f);
  ASSERT_EQ(new_vector.y, 0.0f);
  ASSERT_EQ(new_vector.z, 0.0f);
  ASSERT_EQ(new_vector.w, 0.0f);
}

TEST_F(Vector4Test, minus_vector_assign) {
  dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  new_vector -= new_vector;

  ASSERT_EQ(new_vector.x, 0.0f);
  ASSERT_EQ(new_vector.y, 0.0f);
  ASSERT_EQ(new_vector.z, 0.0f);
  ASSERT_EQ(new_vector.w, 0.0f);
}

TEST_F(Vector4Test, add_scalar) {
  dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  new_vector = new_vector + 2.0f;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
  ASSERT_EQ(new_vector.z, 4.0f);
  ASSERT_EQ(new_vector.w, 4.0f);
}

TEST_F(Vector4Test, add_vector) {
  dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  new_vector = new_vector + new_vector;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
  ASSERT_EQ(new_vector.z, 4.0f);
  ASSERT_EQ(new_vector.w, 4.0f);
}

TEST_F(Vector4Test, add_scalar_assign) {
  dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  new_vector += 2.0f;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
  ASSERT_EQ(new_vector.z, 4.0f);
  ASSERT_EQ(new_vector.w, 4.0f);
}

TEST_F(Vector4Test, add_vector_assign) {
  dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  new_vector += new_vector;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
  ASSERT_EQ(new_vector.z, 4.0f);
  ASSERT_EQ(new_vector.w, 4.0f);
}

TEST_F(Vector4Test, mul_scalar) {
  const dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  const dlm::vector::Vector4F negated_vector = new_vector * 2.0f;

  ASSERT_EQ(negated_vector.x, 4.0f);
  ASSERT_EQ(negated_vector.y, 4.0f);
  ASSERT_EQ(negated_vector.z, 4.0f);
  ASSERT_EQ(negated_vector.w, 4.0f);
}

TEST_F(Vector4Test, mul_vector) {
  const dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  const dlm::vector::Vector4F negated_vector = new_vector * new_vector;

  ASSERT_EQ(negated_vector.x, 4.0f);
  ASSERT_EQ(negated_vector.y, 4.0f);
  ASSERT_EQ(negated_vector.z, 4.0f);
  ASSERT_EQ(negated_vector.w, 4.0f);
}

TEST_F(Vector4Test, mul_scalar_assign) {
  dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  new_vector *= 2.0f;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
  ASSERT_EQ(new_vector.z, 4.0f);
  ASSERT_EQ(new_vector.w, 4.0f);
}

TEST_F(Vector4Test, mul_vector_assign) {
  dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  new_vector *= new_vector;

  ASSERT_EQ(new_vector.x, 4.0f);
  ASSERT_EQ(new_vector.y, 4.0f);
  ASSERT_EQ(new_vector.z, 4.0f);
  ASSERT_EQ(new_vector.w, 4.0f);
}

TEST_F(Vector4Test, div_scalar) {
  const dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  const dlm::vector::Vector4F negated_vector = new_vector / 2.0f;

  ASSERT_EQ(negated_vector.x, 1.0f);
  ASSERT_EQ(negated_vector.y, 1.0f);
  ASSERT_EQ(negated_vector.z, 1.0f);
  ASSERT_EQ(negated_vector.w, 1.0f);
}

TEST_F(Vector4Test, div_vector) {
  const dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  const dlm::vector::Vector4F negated_vector = new_vector / new_vector;

  ASSERT_EQ(negated_vector.x, 1.0f);
  ASSERT_EQ(negated_vector.y, 1.0f);
  ASSERT_EQ(negated_vector.z, 1.0f);
  ASSERT_EQ(negated_vector.w, 1.0f);
}

TEST_F(Vector4Test, div_scalar_assign) {
  dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  new_vector /= 2.0f;

  ASSERT_EQ(new_vector.x, 1.0f);
  ASSERT_EQ(new_vector.y, 1.0f);
  ASSERT_EQ(new_vector.z, 1.0f);
  ASSERT_EQ(new_vector.w, 1.0f);
}

TEST_F(Vector4Test, div_vector_assign) {
  dlm::vector::Vector4F new_vector{2.0f, 2.0f, 2.0f, 2.0f};
  new_vector /= new_vector;

  ASSERT_EQ(new_vector.x, 1.0f);
  ASSERT_EQ(new_vector.y, 1.0f);
  ASSERT_EQ(new_vector.z, 1.0f);
  ASSERT_EQ(new_vector.w, 1.0f);
}

TEST_F(Vector4Test, dot_positive) {
  dlm::vector::Vector4F new_vector{2.0f, 3.0f, 4.0f, 5.0f};
  auto result = new_vector | new_vector;

  ASSERT_EQ(result, 54.0f);
}

TEST_F(Vector4Test, dot_negative) {
  dlm::vector::Vector4F new_vector{-2.0f, -3.0f, -4.0f, -5.0f};
  auto result = new_vector | new_vector;

  ASSERT_EQ(result, 54.0f);
}

TEST_F(Vector4Test, subscript_operator_const_returns_expected_element) {
  const dlm::vector::Vector4F new_vector{2.0f, 3.0f, 4.0f, 5.0f};

  ASSERT_EQ(new_vector[0], 2.0f);
  ASSERT_EQ(new_vector[1], 3.0f);
  ASSERT_EQ(new_vector[2], 4.0f);
  ASSERT_EQ(new_vector[3], 5.0f);
}

TEST_F(Vector4Test, subscript_operator_returns_expected_element) {
  dlm::vector::Vector4F new_vector{2.0f, 3.0f, 4.0f, 5.0f};

  ASSERT_EQ(new_vector[0], 2.0f);
  ASSERT_EQ(new_vector[1], 3.0f);
  ASSERT_EQ(new_vector[2], 4.0f);
  ASSERT_EQ(new_vector[3], 5.0f);
}
