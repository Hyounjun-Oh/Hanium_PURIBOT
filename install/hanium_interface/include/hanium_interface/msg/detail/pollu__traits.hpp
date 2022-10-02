// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hanium_interface:msg/Pollu.idl
// generated code does not contain a copyright notice

#ifndef HANIUM_INTERFACE__MSG__DETAIL__POLLU__TRAITS_HPP_
#define HANIUM_INTERFACE__MSG__DETAIL__POLLU__TRAITS_HPP_

#include "hanium_interface/msg/detail/pollu__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hanium_interface::msg::Pollu>()
{
  return "hanium_interface::msg::Pollu";
}

template<>
inline const char * name<hanium_interface::msg::Pollu>()
{
  return "hanium_interface/msg/Pollu";
}

template<>
struct has_fixed_size<hanium_interface::msg::Pollu>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hanium_interface::msg::Pollu>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hanium_interface::msg::Pollu>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HANIUM_INTERFACE__MSG__DETAIL__POLLU__TRAITS_HPP_
