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

bool
hanium_interface__msg__GetDht__are_equal(const hanium_interface__msg__GetDht * lhs, const hanium_interface__msg__GetDht * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // hum
  if (lhs->hum != rhs->hum) {
    return false;
  }
  // temp
  if (lhs->temp != rhs->temp) {
    return false;
  }
  return true;
}

bool
hanium_interface__msg__GetDht__copy(
  const hanium_interface__msg__GetDht * input,
  hanium_interface__msg__GetDht * output)
{
  if (!input || !output) {
    return false;
  }
  // hum
  output->hum = input->hum;
  // temp
  output->temp = input->temp;
  return true;
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

bool
hanium_interface__msg__GetDht__Sequence__are_equal(const hanium_interface__msg__GetDht__Sequence * lhs, const hanium_interface__msg__GetDht__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hanium_interface__msg__GetDht__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hanium_interface__msg__GetDht__Sequence__copy(
  const hanium_interface__msg__GetDht__Sequence * input,
  hanium_interface__msg__GetDht__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hanium_interface__msg__GetDht);
    hanium_interface__msg__GetDht * data =
      (hanium_interface__msg__GetDht *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hanium_interface__msg__GetDht__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          hanium_interface__msg__GetDht__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hanium_interface__msg__GetDht__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
