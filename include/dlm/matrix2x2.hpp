#pragma once

#include "vector2.hpp"

namespace dlm {
namespace matrix {
template <typename T>
struct Matrix2x2 {
  using ValueType = T;
  using RowType = vector::Vector2<T>;
  using ColumnType = vector::Vector2<T>;

  Matrix2x2()
      : data{RowType{static_cast<T>(1), static_cast<T>(0)},
             RowType{static_cast<T>(0), static_cast<T>(1)}} {};

  Matrix2x2(T m11, T m12, T m21, T m22)
      : data{RowType{m11, m12}, RowType{m21, m22}} {};

  Matrix2x2(const RowType& row1, const RowType& row2) : data{row1, row2} {};

  // Destructors
  ~Matrix2x2(){};

  // Operators
  Matrix2x2<T> operator-(T scalar) const;
  Matrix2x2<T> operator-(const Matrix2x2<T>& other) const;
  Matrix2x2<T>& operator-=(T scalar);
  Matrix2x2<T>& operator-=(const Matrix2x2<T>& other);

  Matrix2x2<T> operator+(T scalar) const;
  Matrix2x2<T> operator+(const Matrix2x2<T>& other) const;
  Matrix2x2<T> AddLoop(const Matrix2x2<T>& other) const;
  Matrix2x2<T>& operator+=(T scalar);
  Matrix2x2<T>& operator+=(const Matrix2x2<T>& other);

  const RowType operator[](int index) const;
  RowType& operator[](int index);

 private:
  RowType data[2];
};

template <typename T>
Matrix2x2<T> Matrix2x2<T>::operator-(T scalar) const {
  return {{data[0] - scalar}, {data[1] - scalar}};
}

template <typename T>
Matrix2x2<T> Matrix2x2<T>::operator-(const Matrix2x2<T>& other) const {
  return {data[0] - other[0], data[1] - other[1]};
}

template <typename T>
Matrix2x2<T>& Matrix2x2<T>::operator-=(T scalar) {
  data[0] -= scalar;
  data[1] -= scalar;
  return *this;
}

template <typename T>
Matrix2x2<T>& Matrix2x2<T>::operator-=(const Matrix2x2<T>& other) {
  data[0] -= other[0];
  data[1] -= other[1];
  return *this;
}

template <typename T>
Matrix2x2<T> Matrix2x2<T>::operator+(T scalar) const {
  return {data[0] + scalar, data[1] + scalar};
}

template <typename T>
Matrix2x2<T> Matrix2x2<T>::operator+(const Matrix2x2<T>& other) const {
  return {data[0] + other[0], data[1] + other[1]};
}

template <typename T>
Matrix2x2<T> Matrix2x2<T>::AddLoop(const Matrix2x2<T>& other) const {
  Matrix2x2<T> return_matrix;
  for (int i = 0; i < 2; i++) {
    return_matrix.data[i] = data[i] + other[i];
  }

  return return_matrix;
}

template <typename T>
Matrix2x2<T>& Matrix2x2<T>::operator+=(T scalar) {
  data[0] += scalar;
  data[1] += scalar;
  return *this;
}

template <typename T>
Matrix2x2<T>& Matrix2x2<T>::operator+=(const Matrix2x2<T>& other) {
  data[0] += other[0];
  data[1] += other[1];
  return *this;
}

template <typename T>
const typename Matrix2x2<T>::RowType Matrix2x2<T>::operator[](int index) const {
  return data[index];
}

template <typename T>
typename Matrix2x2<T>::RowType& Matrix2x2<T>::operator[](int index) {
  return data[index];
}

using Matrix2x2F = Matrix2x2<float>;

static_assert(std::is_move_constructible<Matrix2x2F>::value);
}  // namespace matrix
}  // namespace dlm
