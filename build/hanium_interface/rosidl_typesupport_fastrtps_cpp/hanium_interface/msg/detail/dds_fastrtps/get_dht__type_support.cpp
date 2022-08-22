// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from hanium_interface:msg/GetDht.idl
// generated code does not contain a copyright notice
#include "hanium_interface/msg/detail/get_dht__rosidl_typesupport_fastrtps_cpp.hpp"
#include "hanium_interface/msg/detail/get_dht__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: hum
  cdr << ros_message.hum;
  // Member: temp
  cdr << ros_message.temp;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hanium_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hanium_interface::msg::GetDht & ros_message)
{
  // Member: hum
  cdr >> ros_message.hum;

  // Member: temp
  cdr >> ros_message.temp;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hanium_interface
get_serialized_size(
  const hanium_interface::msg::GetDht & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: hum
  {
    size_t item_size = sizeof(ros_message.hum);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temp
  {
    size_t item_size = sizeof(ros_message.temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hanium_interface
max_serialized_size_GetDht(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: hum
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: temp
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _GetDht__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const hanium_interface::msg::GetDht *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GetDht__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<hanium_interface::msg::GetDht *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GetDht__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const hanium_interface::msg::GetDht *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GetDht__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_GetDht(full_bounded, 0);
}

static message_type_support_callbacks_t _GetDht__callbacks = {
  "hanium_interface::msg",
  "GetDht",
  _GetDht__cdr_serialize,
  _GetDht__cdr_deserialize,
  _GetDht__get_serialized_size,
  _GetDht__max_serialized_size
};

static rosidl_message_type_support_t _GetDht__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GetDht__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace hanium_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_hanium_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<hanium_interface::msg::GetDht>()
{
  return &hanium_interface::msg::typesupport_fastrtps_cpp::_GetDht__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hanium_interface, msg, GetDht)() {
  return &hanium_interface::msg::typesupport_fastrtps_cpp::_GetDht__handle;
}

#ifdef __cplusplus
}
#endif
