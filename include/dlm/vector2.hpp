#pragma once

#include <cmath>
#include <iostream>
#include <type_traits>

namespace dlm {
namespace vector {
template <typename T>
struct Vector2 {
  using ValueType = T;
  // Constructors
  Vector2() : x{static_cast<T>(0)}, y{static_cast<T>(0)} {};

  Vector2(T x, T y) : x{x}, y{y} {};

  // Destructors
  ~Vector2(){};

  // Operators
  Vector2<T> operator-() const;
  Vector2<T> operator-(T scalar) const;
  Vector2<T> operator-(const Vector2<T>& v) const;
  Vector2<T>& operator-=(T scalar);
  Vector2<T>& operator-=(const Vector2<T>& v);

  Vector2<T> operator+(T scalar) const;
  Vector2<T> operator+(const Vector2<T>& v) const;
  Vector2<T>& operator+=(T scalar);
  Vector2<T>& operator+=(const Vector2<T>& v);

  Vector2<T> operator*(T scalar) const;
  Vector2<T> operator*(const Vector2<T>& v) const;
  Vector2<T>& operator*=(T scalar);
  Vector2<T>& operator*=(const Vector2<T>& v);

  Vector2<T> operator/(T scalar) const;
  Vector2<T> operator/(const Vector2<T>& v) const;
  Vector2<T>& operator/=(T scalar);
  Vector2<T>& operator/=(const Vector2<T>& v);

  T operator[](int index) const;
  T& operator[](int index);

  // dot product
  T operator|(const Vector2<T>& v) const;

  bool operator==(const Vector2<T>& v) const;
  bool operator!=(const Vector2<T>& v) const;
  bool operator<(const Vector2<T>& v) const;
  bool operator<=(const Vector2<T>& v) const;
  bool operator>(const Vector2<T>& v) const;
  bool operator>=(const Vector2<T>& v) const;

  // Helper functions
  void Zero();
  bool IsZero() const;

  T Component(int index) const;
  T& Component(int index);

  bool Equals(const Vector2<T>& v1, T tolerance);

  void Normalize();

  T Length() const;
  T LengthSquared() const;

  Vector2<T> ProjectOnTo(const Vector2<T>& v) const;

  T x;
  T y;
};

template <typename T>
Vector2<T> Vector2<T>::operator-() const {
  return {-x, -y};
}

template <typename T>
Vector2<T> Vector2<T>::operator-(T scalar) const {
  return {x - scalar, y - scalar};
}

template <typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& v) const {
  return {x - v.x, y - v.y};
}

template <typename T>
Vector2<T>& Vector2<T>::operator-=(T scalar) {
  x -= scalar;
  y -= scalar;
  return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& v) {
  x -= v.x;
  y -= v.y;
  return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator+(T scalar) const {
  return {x + scalar, y + scalar};
}

template <typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T>& v) const {
  return {x + v.x, y + v.y};
}

template <typename T>
Vector2<T>& Vector2<T>::operator+=(T scalar) {
  x += scalar;
  y += scalar;
  return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& v) {
  x += v.x;
  y += v.y;
  return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator*(T scalar) const {
  return {x * scalar, y * scalar};
}

template <typename T>
Vector2<T> Vector2<T>::operator*(const Vector2<T>& v) const {
  return {x * v.x, y * v.y};
}

template <typename T>
Vector2<T>& Vector2<T>::operator*=(T scalar) {
  x *= scalar;
  y *= scalar;
  return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator*=(const Vector2<T>& v) {
  x *= v.x;
  y *= v.y;
  return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator/(T scalar) const {
  // TODO add assert on 0
  return {x / scalar, y / scalar};
}

template <typename T>
Vector2<T> Vector2<T>::operator/(const Vector2<T>& v) const {
  // TODO add assert on 0
  return {x / v.x, y / v.y};
}

template <typename T>
Vector2<T>& Vector2<T>::operator/=(T scalar) {
  x /= scalar;
  y /= scalar;
  return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator/=(const Vector2<T>& v) {
  x /= v.x;
  y /= v.y;
  return *this;
}

template <typename T>
T Vector2<T>::operator|(const Vector2<T>& v) const {
  return x * v.x + y * v.y;
}

template <typename T>
T& Vector2<T>::operator[](int index) {
  return Component(index);
}

template <typename T>
T Vector2<T>::operator[](int index) const {
  return Component(index);
}

template <typename T>
bool Vector2<T>::operator==(const Vector2<T>& v) const {
  return (x == v.x && y == v.y);
}

template <typename T>
bool Vector2<T>::operator!=(const Vector2<T>& v) const {
  return x != v.x || y != v.y;
}

template <typename T>
bool Vector2<T>::operator<(const Vector2<T>& v) const {
  return x < v.x && y < v.y;
}

template <typename T>
bool Vector2<T>::operator<=(const Vector2<T>& v) const {
  return x <= v.x && y <= v.y;
}

template <typename T>
bool Vector2<T>::operator>(const Vector2<T>& v) const {
  return x > v.x && y > v.y;
}

template <typename T>
bool Vector2<T>::operator>=(const Vector2<T>& v) const {
  return x >= v.x && y >= v.y;
}

template <typename T>
void Vector2<T>::Zero() {
  x = static_cast<T>(0);
  y = static_cast<T>(0);
}

template <typename T>
bool Vector2<T>::IsZero() const {
  return x == static_cast<T>(0) && y == static_cast<T>(0);
}

template <typename T>
T Vector2<T>::Component(int index) const {
  switch (index) {
    default:
    case 0:
      return x;
      break;
    case 1:
      return y;
      break;
  }
}

template <typename T>
T& Vector2<T>::Component(int index) {
  switch (index) {
    default:
    case 0:
      return x;
      break;
    case 1:
      return y;
      break;
  }
}

template <typename T>
bool Vector2<T>::Equals(const Vector2<T>& v1, T tolerance) {
  return (x - v1.x) < tolerance && (y - v1.y) < tolerance;
}

template <typename T>
void Vector2<T>::Normalize() {
  const T length = Length();
  x /= length;
  y /= length;
}

template <typename T>
T Vector2<T>::Length() const {
  return std::sqrt(x * x + y * y);
}

template <typename T>
T Vector2<T>::LengthSquared() const {
  return x * x + y * y;
}

using Vector2F = Vector2<float>;

static_assert(std::is_move_constructible<Vector2F>::value);

}  // namespace vector

}  // namespace dlm
