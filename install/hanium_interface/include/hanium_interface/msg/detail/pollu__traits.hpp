// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hanium_interface:msg/Pollu.idl
// generated code does not contain a copyright notice

#ifndef HANIUM_INTERFACE__MSG__DETAIL__POLLU__TRAITS_HPP_
#define HANIUM_INTERFACE__MSG__DETAIL__POLLU__TRAITS_HPP_

#include "hanium_interface/msg/detail/pollu__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const hanium_interface::msg::Pollu & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pm10
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pm10: ";
    value_to_yaml(msg.pm10, out);
    out << "\n";
  }

  // member: pm2_5
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pm2_5: ";
    value_to_yaml(msg.pm2_5, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const hanium_interface::msg::Pollu & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

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
