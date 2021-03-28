#pragma once

#include <cmath>

namespace dlm {
namespace vector {
template <typename T>
struct Vector3 {
  using ValueType = T;
  // Constructors
  Vector3()
      : x{static_cast<T>(0)}, y{static_cast<T>(0)}, z{static_cast<T>(0)} {};
  Vector3(T x, T y, T z) : x{x}, y{y}, z{z} {};

  // Destructors
  ~Vector3(){};

  // Operators
  Vector3<T> operator-() const;
  Vector3<T> operator-(T scalar) const;
  Vector3<T> operator-(const Vector3<T>& v) const;
  Vector3<T> operator-=(T scalar);
  Vector3<T> operator-=(const Vector3<T>& v);

  Vector3<T> operator+(T scalar) const;
  Vector3<T> operator+(const Vector3<T>& v) const;
  Vector3<T> operator+=(T scalar);
  Vector3<T> operator+=(const Vector3<T>& v);

  Vector3<T> operator*(T scalar) const;
  Vector3<T> operator*(const Vector3<T>& v) const;
  Vector3<T> operator*=(T scalar);
  Vector3<T> operator*=(const Vector3<T>& v);

  Vector3<T> operator/(T scalar) const;
  Vector3<T> operator/(const Vector3<T>& v) const;
  Vector3<T> operator/=(T scalar);
  Vector3<T> operator/=(const Vector3<T>& v);

  T operator[](int index) const;
  T& operator[](int index);

  // dot product
  T operator|(const Vector3<T>& v) const;

  // cross product
  Vector3<T> operator^(const Vector3<T>& v) const;

  bool operator==(const Vector3<T>& v) const;
  bool operator!=(const Vector3<T>& v) const;
  bool operator<(const Vector3<T>& v) const;
  bool operator<=(const Vector3<T>& v) const;
  bool operator>(const Vector3<T>& v) const;
  bool operator>=(const Vector3<T>& v) const;

  // Helper functions
  void Zero();
  bool IsZero() const;

  T Component(int index) const;
  T& Component(int index);

  bool Equals(const Vector3<T>& v1, T tolerance);

  void Normalize();

  T Length() const;
  T LengthSquared() const;

  Vector3<T> ProjectOnTo(const Vector3<T>& v) const;

  T x;
  T y;
  T z;
};

template <typename T>
Vector3<T> Vector3<T>::operator-() const {
  return {-x, -y, -z};
}

template <typename T>
Vector3<T> Vector3<T>::operator-(T scalar) const {
  return {x - scalar, y - scalar, z - scalar};
}

template <typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T>& v) const {
  return {x - v.x, y - v.y, z - v.z};
}

template <typename T>
Vector3<T> Vector3<T>::operator-=(T scalar) {
  x -= scalar;
  y -= scalar;
  z -= scalar;
  return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator-=(const Vector3<T>& v) {
  x -= v.x;
  y -= v.y;
  z -= v.z;
  return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator+(T scalar) const {
  return {x + scalar, y + scalar, z + scalar};
}

template <typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T>& v) const {
  return {x + v.x, y + v.y, z + v.z};
}

template <typename T>
Vector3<T> Vector3<T>::operator+=(T scalar) {
  x += scalar;
  y += scalar;
  z += scalar;
  return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator+=(const Vector3<T>& v) {
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator*(T scalar) const {
  return {x * scalar, y * scalar, z * scalar};
}

template <typename T>
Vector3<T> Vector3<T>::operator*(const Vector3<T>& v) const {
  return {x * v.x, y * v.y, z * v.z};
}

template <typename T>
Vector3<T> Vector3<T>::operator*=(T scalar) {
  x *= scalar;
  y *= scalar;
  z *= scalar;
  return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator*=(const Vector3<T>& v) {
  x *= v.x;
  y *= v.y;
  z *= v.z;
  return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator/(T scalar) const {
  // TODO add assert on 0
  return {x / scalar, y / scalar, z / scalar};
}

template <typename T>
Vector3<T> Vector3<T>::operator/(const Vector3<T>& v) const {
  // TODO add assert on 0
  return {x / v.x, y / v.y, z / v.z};
}

template <typename T>
Vector3<T> Vector3<T>::operator/=(T scalar) {
  x /= scalar;
  y /= scalar;
  z /= scalar;
  return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator/=(const Vector3<T>& v) {
  x /= v.x;
  y /= v.y;
  z /= v.z;
  return *this;
}

template <typename T>
T Vector3<T>::operator|(const Vector3<T>& v) const {
  return x * v.x + y * v.y + z * v.z;
}

template <typename T>
Vector3<T> Vector3<T>::operator^(const Vector3<T>& v) const {
  return {y * v.z - v.y * z, z * v.x - v.z * x, x * v.y - v.x * y};
}

template <typename T>
T& Vector3<T>::operator[](int index) {
  return Component(index);
}

template <typename T>
T Vector3<T>::operator[](int index) const {
  return Component(index);
}

template <typename T>
bool Vector3<T>::operator==(const Vector3<T>& v) const {
  return (x == v.x && y == v.y && z == v.z);
}

template <typename T>
bool Vector3<T>::operator!=(const Vector3<T>& v) const {
  return x != v.x || y != v.y || z != v.z;
}

template <typename T>
bool Vector3<T>::operator<(const Vector3<T>& v) const {
  return x < v.x && y < v.y && z < v.z;
}

template <typename T>
bool Vector3<T>::operator<=(const Vector3<T>& v) const {
  return x <= v.x && y <= v.y && z <= v.z;
}

template <typename T>
bool Vector3<T>::operator>(const Vector3<T>& v) const {
  return x > v.x && y > v.y && z > v.z;
}

template <typename T>
bool Vector3<T>::operator>=(const Vector3<T>& v) const {
  return x >= v.x && y >= v.y && z >= v.z;
}

template <typename T>
void Vector3<T>::Zero() {
  x = static_cast<T>(0);
  y = static_cast<T>(0);
  z = static_cast<T>(0);
}

template <typename T>
bool Vector3<T>::IsZero() const {
  return x == static_cast<T>(0) && y == static_cast<T>(0) &&
         z == static_cast<T>(0);
}

template <typename T>
T Vector3<T>::Component(int index) const {
  switch (index) {
    default:
    case 0:
      return x;
      break;
    case 1:
      return y;
      break;
    case 2:
      return z;
      break;
  }
}

template <typename T>
T& Vector3<T>::Component(int index) {
  switch (index) {
    default:
    case 0:
      return x;
      break;
    case 1:
      return y;
      break;
    case 2:
      return z;
      break;
  }
}

template <typename T>
bool Vector3<T>::Equals(const Vector3<T>& v1, T tolerance) {
  return (x - v1.x) < tolerance && (y - v1.y) < tolerance &&
         (z - v1.z) < tolerance;
}

template <typename T>
void Vector3<T>::Normalize() {
  const T length = Length();
  x /= length;
  y /= length;
  z /= length;
}

template <typename T>
T Vector3<T>::Length() const {
  return std::sqrt(x * x + y * y + z * z);
}

template <typename T>
T Vector3<T>::LengthSquared() const {
  return x * x + y * y + z * z;
}

using Vector3F = Vector3<float>;

static_assert(std::is_move_constructible<Vector3F>::value);

}  // namespace vector

}  // namespace dlm
