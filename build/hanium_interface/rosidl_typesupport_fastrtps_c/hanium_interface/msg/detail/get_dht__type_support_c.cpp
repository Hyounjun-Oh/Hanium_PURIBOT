// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from hanium_interface:msg/GetDht.idl
// generated code does not contain a copyright notice
#include "hanium_interface/msg/detail/get_dht__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "hanium_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hanium_interface/msg/detail/get_dht__struct.h"
#include "hanium_interface/msg/detail/get_dht__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _GetDht__ros_msg_type = hanium_interface__msg__GetDht;

static bool _GetDht__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GetDht__ros_msg_type * ros_message = static_cast<const _GetDht__ros_msg_type *>(untyped_ros_message);
  // Field name: hum
  {
    cdr << ros_message->hum;
  }

  // Field name: temp
  {
    cdr << ros_message->temp;
  }

  return true;
}

static bool _GetDht__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GetDht__ros_msg_type * ros_message = static_cast<_GetDht__ros_msg_type *>(untyped_ros_message);
  // Field name: hum
  {
    cdr >> ros_message->hum;
  }

  // Field name: temp
  {
    cdr >> ros_message->temp;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hanium_interface
size_t get_serialized_size_hanium_interface__msg__GetDht(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetDht__ros_msg_type * ros_message = static_cast<const _GetDht__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name hum
  {
    size_t item_size = sizeof(ros_message->hum);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name temp
  {
    size_t item_size = sizeof(ros_message->temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GetDht__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_hanium_interface__msg__GetDht(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hanium_interface
size_t max_serialized_size_hanium_interface__msg__GetDht(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: hum
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: temp
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _GetDht__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_hanium_interface__msg__GetDht(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_GetDht = {
  "hanium_interface::msg",
  "GetDht",
  _GetDht__cdr_serialize,
  _GetDht__cdr_deserialize,
  _GetDht__get_serialized_size,
  _GetDht__max_serialized_size
};

static rosidl_message_type_support_t _GetDht__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GetDht,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hanium_interface, msg, GetDht)() {
  return &_GetDht__type_support;
}

#if defined(__cplusplus)
}
#endif
