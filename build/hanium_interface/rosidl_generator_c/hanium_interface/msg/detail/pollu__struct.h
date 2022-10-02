// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hanium_interface:msg/Pollu.idl
// generated code does not contain a copyright notice

#ifndef HANIUM_INTERFACE__MSG__DETAIL__POLLU__STRUCT_H_
#define HANIUM_INTERFACE__MSG__DETAIL__POLLU__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Pollu in the package hanium_interface.
typedef struct hanium_interface__msg__Pollu
{
  int16_t pm10;
  int16_t pm2_5;
} hanium_interface__msg__Pollu;

// Struct for a sequence of hanium_interface__msg__Pollu.
typedef struct hanium_interface__msg__Pollu__Sequence
{
  hanium_interface__msg__Pollu * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hanium_interface__msg__Pollu__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HANIUM_INTERFACE__MSG__DETAIL__POLLU__STRUCT_H_
