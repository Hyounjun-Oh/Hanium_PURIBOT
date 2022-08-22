// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from hanium_interface:msg/Pollu.idl
// generated code does not contain a copyright notice

#ifndef HANIUM_INTERFACE__MSG__DETAIL__POLLU__FUNCTIONS_H_
#define HANIUM_INTERFACE__MSG__DETAIL__POLLU__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "hanium_interface/msg/rosidl_generator_c__visibility_control.h"

#include "hanium_interface/msg/detail/pollu__struct.h"

/// Initialize msg/Pollu message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * hanium_interface__msg__Pollu
 * )) before or use
 * hanium_interface__msg__Pollu__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_hanium_interface
bool
hanium_interface__msg__Pollu__init(hanium_interface__msg__Pollu * msg);

/// Finalize msg/Pollu message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hanium_interface
void
hanium_interface__msg__Pollu__fini(hanium_interface__msg__Pollu * msg);

/// Create msg/Pollu message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * hanium_interface__msg__Pollu__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hanium_interface
hanium_interface__msg__Pollu *
hanium_interface__msg__Pollu__create();

/// Destroy msg/Pollu message.
/**
 * It calls
 * hanium_interface__msg__Pollu__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hanium_interface
void
hanium_interface__msg__Pollu__destroy(hanium_interface__msg__Pollu * msg);


/// Initialize array of msg/Pollu messages.
/**
 * It allocates the memory for the number of elements and calls
 * hanium_interface__msg__Pollu__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_hanium_interface
bool
hanium_interface__msg__Pollu__Sequence__init(hanium_interface__msg__Pollu__Sequence * array, size_t size);

/// Finalize array of msg/Pollu messages.
/**
 * It calls
 * hanium_interface__msg__Pollu__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hanium_interface
void
hanium_interface__msg__Pollu__Sequence__fini(hanium_interface__msg__Pollu__Sequence * array);

/// Create array of msg/Pollu messages.
/**
 * It allocates the memory for the array and calls
 * hanium_interface__msg__Pollu__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_hanium_interface
hanium_interface__msg__Pollu__Sequence *
hanium_interface__msg__Pollu__Sequence__create(size_t size);

/// Destroy array of msg/Pollu messages.
/**
 * It calls
 * hanium_interface__msg__Pollu__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_hanium_interface
void
hanium_interface__msg__Pollu__Sequence__destroy(hanium_interface__msg__Pollu__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // HANIUM_INTERFACE__MSG__DETAIL__POLLU__FUNCTIONS_H_
