// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hanium_interface:msg/GetDht.idl
// generated code does not contain a copyright notice

#ifndef HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__STRUCT_H_
#define HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/GetDht in the package hanium_interface.
typedef struct hanium_interface__msg__GetDht
{
  float hum;
  float temp;
} hanium_interface__msg__GetDht;

// Struct for a sequence of hanium_interface__msg__GetDht.
typedef struct hanium_interface__msg__GetDht__Sequence
{
  hanium_interface__msg__GetDht * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hanium_interface__msg__GetDht__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__STRUCT_H_
