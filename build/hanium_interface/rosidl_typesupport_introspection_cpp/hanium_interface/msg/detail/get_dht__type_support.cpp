// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from hanium_interface:msg/GetDht.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "hanium_interface/msg/detail/get_dht__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace hanium_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void GetDht_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) hanium_interface::msg::GetDht(_init);
}

void GetDht_fini_function(void * message_memory)
{
  auto typed_message = static_cast<hanium_interface::msg::GetDht *>(message_memory);
  typed_message->~GetDht();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetDht_message_member_array[2] = {
  {
    "hum",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hanium_interface::msg::GetDht, hum),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "temp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hanium_interface::msg::GetDht, temp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetDht_message_members = {
  "hanium_interface::msg",  // message namespace
  "GetDht",  // message name
  2,  // number of fields
  sizeof(hanium_interface::msg::GetDht),
  GetDht_message_member_array,  // message members
  GetDht_init_function,  // function to initialize message memory (memory has to be allocated)
  GetDht_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetDht_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetDht_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace hanium_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<hanium_interface::msg::GetDht>()
{
  return &::hanium_interface::msg::rosidl_typesupport_introspection_cpp::GetDht_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, hanium_interface, msg, GetDht)() {
  return &::hanium_interface::msg::rosidl_typesupport_introspection_cpp::GetDht_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
