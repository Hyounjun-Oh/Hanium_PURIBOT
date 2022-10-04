// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hanium_interface:msg/Pollu.idl
// generated code does not contain a copyright notice
#include "hanium_interface/msg/detail/pollu__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
hanium_interface__msg__Pollu__init(hanium_interface__msg__Pollu * msg)
{
  if (!msg) {
    return false;
  }
  // pm10
  // pm2_5
  return true;
}

void
hanium_interface__msg__Pollu__fini(hanium_interface__msg__Pollu * msg)
{
  if (!msg) {
    return;
  }
  // pm10
  // pm2_5
}

bool
hanium_interface__msg__Pollu__are_equal(const hanium_interface__msg__Pollu * lhs, const hanium_interface__msg__Pollu * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pm10
  if (lhs->pm10 != rhs->pm10) {
    return false;
  }
  // pm2_5
  if (lhs->pm2_5 != rhs->pm2_5) {
    return false;
  }
  return true;
}

bool
hanium_interface__msg__Pollu__copy(
  const hanium_interface__msg__Pollu * input,
  hanium_interface__msg__Pollu * output)
{
  if (!input || !output) {
    return false;
  }
  // pm10
  output->pm10 = input->pm10;
  // pm2_5
  output->pm2_5 = input->pm2_5;
  return true;
}

hanium_interface__msg__Pollu *
hanium_interface__msg__Pollu__create()
{
  hanium_interface__msg__Pollu * msg = (hanium_interface__msg__Pollu *)malloc(sizeof(hanium_interface__msg__Pollu));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hanium_interface__msg__Pollu));
  bool success = hanium_interface__msg__Pollu__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
hanium_interface__msg__Pollu__destroy(hanium_interface__msg__Pollu * msg)
{
  if (msg) {
    hanium_interface__msg__Pollu__fini(msg);
  }
  free(msg);
}


bool
hanium_interface__msg__Pollu__Sequence__init(hanium_interface__msg__Pollu__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  hanium_interface__msg__Pollu * data = NULL;
  if (size) {
    data = (hanium_interface__msg__Pollu *)calloc(size, sizeof(hanium_interface__msg__Pollu));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hanium_interface__msg__Pollu__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hanium_interface__msg__Pollu__fini(&data[i - 1]);
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
hanium_interface__msg__Pollu__Sequence__fini(hanium_interface__msg__Pollu__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hanium_interface__msg__Pollu__fini(&array->data[i]);
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

hanium_interface__msg__Pollu__Sequence *
hanium_interface__msg__Pollu__Sequence__create(size_t size)
{
  hanium_interface__msg__Pollu__Sequence * array = (hanium_interface__msg__Pollu__Sequence *)malloc(sizeof(hanium_interface__msg__Pollu__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = hanium_interface__msg__Pollu__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
hanium_interface__msg__Pollu__Sequence__destroy(hanium_interface__msg__Pollu__Sequence * array)
{
  if (array) {
    hanium_interface__msg__Pollu__Sequence__fini(array);
  }
  free(array);
}

bool
hanium_interface__msg__Pollu__Sequence__are_equal(const hanium_interface__msg__Pollu__Sequence * lhs, const hanium_interface__msg__Pollu__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hanium_interface__msg__Pollu__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hanium_interface__msg__Pollu__Sequence__copy(
  const hanium_interface__msg__Pollu__Sequence * input,
  hanium_interface__msg__Pollu__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hanium_interface__msg__Pollu);
    hanium_interface__msg__Pollu * data =
      (hanium_interface__msg__Pollu *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hanium_interface__msg__Pollu__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          hanium_interface__msg__Pollu__fini(&data[i]);
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
    if (!hanium_interface__msg__Pollu__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
