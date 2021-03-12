#pragma once

#include "dlm/vector2.hpp"
#include "dlm/vector3.hpp"

namespace dlm {
namespace vector {

template <typename vector_type>
vector_type Normalize(const vector_type& v1) {
  const auto length = v1.Length();
  return v1 / length;
}

template <typename vector_type>
typename vector_type::ValueType Length(const vector_type& v1) {
  return std::sqrt(v1 | v1);
}

template <typename vector_type>
typename vector_type::ValueType Dot(const vector_type& v1,
                                    const vector_type& v2) {
  return v1 | v2;
}

template <typename T>
Vector3<T> Cross(const Vector3<T>& v1, const Vector3<T> v2) {
  return v1 ^ v2;
}

template <typename T>
T Distance(const Vector2<T>& v1, const Vector2<T> v2) {
  Vector2<T> diff = v1 - v2;
  return diff.Length();
}

template <typename T>
T DistanceSquared(const Vector2<T>& v1, const Vector2<T> v2) {
  Vector2<T> diff = v1 - v2;
  return diff.LengthSquared();
}

template <typename vector_type>
vector_type Reflect(const vector_type& v, const vector_type& n) {
  const auto normalized = Normalize(n);
  const auto projected = n * (normalized | v);
  return (projected * 2.0f) - v;
}

template <typename vector_type>
vector_type Project(const vector_type& v1, const vector_type& v2) {
  // vii = (v2 / || v2 ||) * (cos (angle) * || v1 ||)
  // vii = (v2 / || v2 ||) * ((cos (angle) * || v1 ||) * (||v2|| / ||v2||)
  // vii = v2 * ((cos(angle) * || v1|| * ||v2||)/ (||v2|| * ||v2||))
  // vii = v2 * (v1 | v2) / || v2 || ^ 2
  const typename vector_type::ValueType v2Length = Length(v2);
  return v2 * ((v1 | v2) / (v2Length * v2Length));
}

}  // namespace vector
}  // namespace dlm
