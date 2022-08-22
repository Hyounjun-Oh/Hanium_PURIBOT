// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hanium_interface:msg/Pollu.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hanium_interface/msg/detail/pollu__rosidl_typesupport_introspection_c.h"
#include "hanium_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hanium_interface/msg/detail/pollu__functions.h"
#include "hanium_interface/msg/detail/pollu__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Pollu__rosidl_typesupport_introspection_c__Pollu_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hanium_interface__msg__Pollu__init(message_memory);
}

void Pollu__rosidl_typesupport_introspection_c__Pollu_fini_function(void * message_memory)
{
  hanium_interface__msg__Pollu__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Pollu__rosidl_typesupport_introspection_c__Pollu_message_member_array[2] = {
  {
    "pm10",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hanium_interface__msg__Pollu, pm10),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pm2_5",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hanium_interface__msg__Pollu, pm2_5),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Pollu__rosidl_typesupport_introspection_c__Pollu_message_members = {
  "hanium_interface__msg",  // message namespace
  "Pollu",  // message name
  2,  // number of fields
  sizeof(hanium_interface__msg__Pollu),
  Pollu__rosidl_typesupport_introspection_c__Pollu_message_member_array,  // message members
  Pollu__rosidl_typesupport_introspection_c__Pollu_init_function,  // function to initialize message memory (memory has to be allocated)
  Pollu__rosidl_typesupport_introspection_c__Pollu_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Pollu__rosidl_typesupport_introspection_c__Pollu_message_type_support_handle = {
  0,
  &Pollu__rosidl_typesupport_introspection_c__Pollu_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hanium_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hanium_interface, msg, Pollu)() {
  if (!Pollu__rosidl_typesupport_introspection_c__Pollu_message_type_support_handle.typesupport_identifier) {
    Pollu__rosidl_typesupport_introspection_c__Pollu_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Pollu__rosidl_typesupport_introspection_c__Pollu_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
