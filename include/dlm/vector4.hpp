#pragma once

#include <cmath>

namespace dlm {
namespace vector {
template <typename T>
struct Vector4 {
  using ValueType = T;
  // Constructors
  Vector4()
      : x{static_cast<T>(0)},
        y{static_cast<T>(0)},
        z{static_cast<T>(0)},
        w{static_cast<T>(0)} {};
  Vector4(T x, T y, T z, T w) : x{x}, y{y}, z{z}, w{w} {};

  // Destructors
  ~Vector4(){};

  // Operators
  Vector4<T> operator-() const;
  Vector4<T> operator-(T scalar) const;
  Vector4<T> operator-(const Vector4<T>& v) const;
  Vector4<T> operator-=(T scalar);
  Vector4<T> operator-=(const Vector4<T>& v);

  Vector4<T> operator+(T scalar) const;
  Vector4<T> operator+(const Vector4<T>& v) const;
  Vector4<T> operator+=(T scalar);
  Vector4<T> operator+=(const Vector4<T>& v);

  Vector4<T> operator*(T scalar) const;
  Vector4<T> operator*(const Vector4<T>& v) const;
  Vector4<T> operator*=(T scalar);
  Vector4<T> operator*=(const Vector4<T>& v);

  Vector4<T> operator/(T scalar) const;
  Vector4<T> operator/(const Vector4<T>& v) const;
  Vector4<T> operator/=(T scalar);
  Vector4<T> operator/=(const Vector4<T>& v);

  T operator[](int index) const;
  T& operator[](int index);

  // dot product
  T operator|(const Vector4<T>& v) const;

  bool operator==(const Vector4<T>& v) const;
  bool operator!=(const Vector4<T>& v) const;
  bool operator<(const Vector4<T>& v) const;
  bool operator<=(const Vector4<T>& v) const;
  bool operator>(const Vector4<T>& v) const;
  bool operator>=(const Vector4<T>& v) const;

  // Helper functions
  void Zero();
  bool IsZero() const;

  T Component(int index) const;
  T& Component(int index);

  bool Equals(const Vector4<T>& v1, T tolerance);

  void Normalize();

  T Length() const;
  T LengthSquared() const;

  Vector4<T> ProjectOnTo(const Vector4<T>& v) const;

  T x;
  T y;
  T z;
  T w;
};

template <typename T>
Vector4<T> Vector4<T>::operator-() const {
  return {-x, -y, -z, -w};
}

template <typename T>
Vector4<T> Vector4<T>::operator-(T scalar) const {
  return {x - scalar, y - scalar, z - scalar, w - scalar};
}

template <typename T>
Vector4<T> Vector4<T>::operator-(const Vector4<T>& v) const {
  return {x - v.x, y - v.y, z - v.z, w - v.w};
}

template <typename T>
Vector4<T> Vector4<T>::operator-=(T scalar) {
  x -= scalar;
  y -= scalar;
  z -= scalar;
  w -= scalar;
  return *this;
}

template <typename T>
Vector4<T> Vector4<T>::operator-=(const Vector4<T>& v) {
  x -= v.x;
  y -= v.y;
  z -= v.z;
  w -= v.w;
  return *this;
}

template <typename T>
Vector4<T> Vector4<T>::operator+(T scalar) const {
  return {x + scalar, y + scalar, z + scalar, w + scalar};
}

template <typename T>
Vector4<T> Vector4<T>::operator+(const Vector4<T>& v) const {
  return {x + v.x, y + v.y, z + v.z, w + v.w};
}

template <typename T>
Vector4<T> Vector4<T>::operator+=(T scalar) {
  x += scalar;
  y += scalar;
  z += scalar;
  w += scalar;
  return *this;
}

template <typename T>
Vector4<T> Vector4<T>::operator+=(const Vector4<T>& v) {
  x += v.x;
  y += v.y;
  z += v.z;
  w += v.w;
  return *this;
}

template <typename T>
Vector4<T> Vector4<T>::operator*(T scalar) const {
  return {x * scalar, y * scalar, z * scalar, w * scalar};
}

template <typename T>
Vector4<T> Vector4<T>::operator*(const Vector4<T>& v) const {
  return {x * v.x, y * v.y, z * v.z, w * v.w};
}

template <typename T>
Vector4<T> Vector4<T>::operator*=(T scalar) {
  x *= scalar;
  y *= scalar;
  z *= scalar;
  w *= scalar;
  return *this;
}

template <typename T>
Vector4<T> Vector4<T>::operator*=(const Vector4<T>& v) {
  x *= v.x;
  y *= v.y;
  z *= v.z;
  w *= v.w;
  return *this;
}

template <typename T>
Vector4<T> Vector4<T>::operator/(T scalar) const {
  // TODO add assert on 0
  return {x / scalar, y / scalar, z / scalar, w / scalar};
}

template <typename T>
Vector4<T> Vector4<T>::operator/(const Vector4<T>& v) const {
  // TODO add assert on 0
  return {x / v.x, y / v.y, z / v.z, w / v.w};
}

template <typename T>
Vector4<T> Vector4<T>::operator/=(T scalar) {
  x /= scalar;
  y /= scalar;
  z /= scalar;
  w /= scalar;
  return *this;
}

template <typename T>
Vector4<T> Vector4<T>::operator/=(const Vector4<T>& v) {
  x /= v.x;
  y /= v.y;
  z /= v.z;
  w /= v.w;
  return *this;
}

template <typename T>
T Vector4<T>::operator|(const Vector4<T>& v) const {
  return x * v.x + y * v.y + z * v.z + w * v.w;
}

template <typename T>
T& Vector4<T>::operator[](int index) {
  return Component(index);
}

template <typename T>
T Vector4<T>::operator[](int index) const {
  return Component(index);
}

template <typename T>
bool Vector4<T>::operator==(const Vector4<T>& v) const {
  return (x == v.x && y == v.y && z == v.z && w == v.w);
}

template <typename T>
bool Vector4<T>::operator!=(const Vector4<T>& v) const {
  return x != v.x || y != v.y || z != v.z || w != v.w;
}

template <typename T>
bool Vector4<T>::operator<(const Vector4<T>& v) const {
  return x < v.x && y < v.y && z < v.z && w < v.w;
}

template <typename T>
bool Vector4<T>::operator<=(const Vector4<T>& v) const {
  return x <= v.x && y <= v.y && z <= v.z && w <= v.w;
}

template <typename T>
bool Vector4<T>::operator>(const Vector4<T>& v) const {
  return x > v.x && y > v.y && z > v.z && w > v.w;
}

template <typename T>
bool Vector4<T>::operator>=(const Vector4<T>& v) const {
  return x >= v.x && y >= v.y && z >= v.z && w >= v.w;
}

template <typename T>
void Vector4<T>::Zero() {
  x = static_cast<T>(0);
  y = static_cast<T>(0);
  z = static_cast<T>(0);
  w = static_cast<T>(0);
}

template <typename T>
bool Vector4<T>::IsZero() const {
  return x == static_cast<T>(0) && y == static_cast<T>(0) &&
         z == static_cast<T>(0) && w == static_cast<T>(0);
}

template <typename T>
T Vector4<T>::Component(int index) const {
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
    case 3:
      return w;
      break;
  }
}

template <typename T>
T& Vector4<T>::Component(int index) {
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
    case 3:
      return w;
      break;
  }
}

template <typename T>
bool Vector4<T>::Equals(const Vector4<T>& v1, T tolerance) {
  return (x - v1.x) < tolerance && (y - v1.y) < tolerance &&
         (z - v1.z) < tolerance && (w - v1.w) < tolerance;
}

template <typename T>
void Vector4<T>::Normalize() {
  const T length = Length();
  x /= length;
  y /= length;
  z /= length;
  w /= length;
}

template <typename T>
T Vector4<T>::Length() const {
  return std::sqrt(x * x + y * y + z * z + w * w);
}

template <typename T>
T Vector4<T>::LengthSquared() const {
  return x * x + y * y + z * z + w * w;
}

using Vector4F = Vector4<float>;

static_assert(std::is_move_constructible<Vector4F>::value);

}  // namespace vector

}  // namespace dlm
