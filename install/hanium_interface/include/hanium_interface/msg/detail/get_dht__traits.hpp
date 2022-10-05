// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hanium_interface:msg/GetDht.idl
// generated code does not contain a copyright notice

#ifndef HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__TRAITS_HPP_
#define HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__TRAITS_HPP_

#include "hanium_interface/msg/detail/get_dht__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const hanium_interface::msg::GetDht & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: hum
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hum: ";
    value_to_yaml(msg.hum, out);
    out << "\n";
  }

  // member: temp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temp: ";
    value_to_yaml(msg.temp, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const hanium_interface::msg::GetDht & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<hanium_interface::msg::GetDht>()
{
  return "hanium_interface::msg::GetDht";
}

template<>
inline const char * name<hanium_interface::msg::GetDht>()
{
  return "hanium_interface/msg/GetDht";
}

template<>
struct has_fixed_size<hanium_interface::msg::GetDht>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hanium_interface::msg::GetDht>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hanium_interface::msg::GetDht>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__TRAITS_HPP_
