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
