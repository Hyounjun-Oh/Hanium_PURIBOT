// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from hanium_interface:msg/GetDht.idl
// generated code does not contain a copyright notice

#ifndef HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "hanium_interface/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "hanium_interface/msg/detail/get_dht__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace hanium_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hanium_interface
cdr_serialize(
  const hanium_interface::msg::GetDht & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hanium_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hanium_interface::msg::GetDht & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hanium_interface
get_serialized_size(
  const hanium_interface::msg::GetDht & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hanium_interface
max_serialized_size_GetDht(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace hanium_interface

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hanium_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hanium_interface, msg, GetDht)();

#ifdef __cplusplus
}
#endif

#endif  // HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
