// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hanium_interface:msg/GetDht.idl
// generated code does not contain a copyright notice
#include "hanium_interface/msg/detail/get_dht__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
hanium_interface__msg__GetDht__init(hanium_interface__msg__GetDht * msg)
{
  if (!msg) {
    return false;
  }
  // hum
  // temp
  return true;
}

void
hanium_interface__msg__GetDht__fini(hanium_interface__msg__GetDht * msg)
{
  if (!msg) {
    return;
  }
  // hum
  // temp
}

hanium_interface__msg__GetDht *
hanium_interface__msg__GetDht__create()
{
  hanium_interface__msg__GetDht * msg = (hanium_interface__msg__GetDht *)malloc(sizeof(hanium_interface__msg__GetDht));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hanium_interface__msg__GetDht));
  bool success = hanium_interface__msg__GetDht__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
hanium_interface__msg__GetDht__destroy(hanium_interface__msg__GetDht * msg)
{
  if (msg) {
    hanium_interface__msg__GetDht__fini(msg);
  }
  free(msg);
}


bool
hanium_interface__msg__GetDht__Sequence__init(hanium_interface__msg__GetDht__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  hanium_interface__msg__GetDht * data = NULL;
  if (size) {
    data = (hanium_interface__msg__GetDht *)calloc(size, sizeof(hanium_interface__msg__GetDht));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hanium_interface__msg__GetDht__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hanium_interface__msg__GetDht__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
hanium_interface__msg__GetDht__Sequence__fini(hanium_interface__msg__GetDht__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hanium_interface__msg__GetDht__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

hanium_interface__msg__GetDht__Sequence *
hanium_interface__msg__GetDht__Sequence__create(size_t size)
{
  hanium_interface__msg__GetDht__Sequence * array = (hanium_interface__msg__GetDht__Sequence *)malloc(sizeof(hanium_interface__msg__GetDht__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = hanium_interface__msg__GetDht__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
hanium_interface__msg__GetDht__Sequence__destroy(hanium_interface__msg__GetDht__Sequence * array)
{
  if (array) {
    hanium_interface__msg__GetDht__Sequence__fini(array);
  }
  free(array);
}
