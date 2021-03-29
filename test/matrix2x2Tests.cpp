// clang-format off
#include "gtest/gtest.h"
// clang-format on

#include "dlm/matrix2x2.hpp"

class Matrix2x2Test : public ::testing::Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(Matrix2x2Test, default_constructor_generate_identity) {
  dlm::matrix::Matrix2x2F new_matrix{};

  ASSERT_EQ(new_matrix[0][0], 1.0f);
  ASSERT_EQ(new_matrix[0][1], 0.0f);
  ASSERT_EQ(new_matrix[1][0], 0.0f);
  ASSERT_EQ(new_matrix[1][1], 1.0f);
}

TEST_F(Matrix2x2Test, movable) {
  dlm::matrix::Matrix2x2F new_matrix{1.0f, 2.0f, 3.0f, 4.0f};

  dlm::matrix::Matrix2x2F moved_matrix = std::move(new_matrix);

  ASSERT_EQ(moved_matrix[0][0], 1.0f);
  ASSERT_EQ(moved_matrix[0][1], 2.0f);
  ASSERT_EQ(moved_matrix[1][0], 3.0f);
  ASSERT_EQ(moved_matrix[1][1], 4.0f);
}

TEST_F(Matrix2x2Test, minus_scalar) {
  const dlm::matrix::Matrix2x2F new_matrix{2.0f, 2.0f, 2.0f, 2.0f};
  const dlm::matrix::Matrix2x2F negated_matrix = new_matrix - 2.0f;

  ASSERT_EQ(negated_matrix[0][0], 0.0f);
  ASSERT_EQ(negated_matrix[0][1], 0.0f);
  ASSERT_EQ(negated_matrix[1][0], 0.0f);
  ASSERT_EQ(negated_matrix[1][1], 0.0f);
}
