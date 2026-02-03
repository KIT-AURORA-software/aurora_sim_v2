// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gpsx:msg/Gpsx.idl
// generated code does not contain a copyright notice

#ifndef GPSX__MSG__DETAIL__GPSX__FUNCTIONS_H_
#define GPSX__MSG__DETAIL__GPSX__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "gpsx/msg/rosidl_generator_c__visibility_control.h"

#include "gpsx/msg/detail/gpsx__struct.h"

/// Initialize msg/Gpsx message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gpsx__msg__Gpsx
 * )) before or use
 * gpsx__msg__Gpsx__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
bool
gpsx__msg__Gpsx__init(gpsx__msg__Gpsx * msg);

/// Finalize msg/Gpsx message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
void
gpsx__msg__Gpsx__fini(gpsx__msg__Gpsx * msg);

/// Create msg/Gpsx message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gpsx__msg__Gpsx__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
gpsx__msg__Gpsx *
gpsx__msg__Gpsx__create();

/// Destroy msg/Gpsx message.
/**
 * It calls
 * gpsx__msg__Gpsx__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
void
gpsx__msg__Gpsx__destroy(gpsx__msg__Gpsx * msg);

/// Check for msg/Gpsx message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
bool
gpsx__msg__Gpsx__are_equal(const gpsx__msg__Gpsx * lhs, const gpsx__msg__Gpsx * rhs);

/// Copy a msg/Gpsx message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
bool
gpsx__msg__Gpsx__copy(
  const gpsx__msg__Gpsx * input,
  gpsx__msg__Gpsx * output);

/// Initialize array of msg/Gpsx messages.
/**
 * It allocates the memory for the number of elements and calls
 * gpsx__msg__Gpsx__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
bool
gpsx__msg__Gpsx__Sequence__init(gpsx__msg__Gpsx__Sequence * array, size_t size);

/// Finalize array of msg/Gpsx messages.
/**
 * It calls
 * gpsx__msg__Gpsx__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
void
gpsx__msg__Gpsx__Sequence__fini(gpsx__msg__Gpsx__Sequence * array);

/// Create array of msg/Gpsx messages.
/**
 * It allocates the memory for the array and calls
 * gpsx__msg__Gpsx__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
gpsx__msg__Gpsx__Sequence *
gpsx__msg__Gpsx__Sequence__create(size_t size);

/// Destroy array of msg/Gpsx messages.
/**
 * It calls
 * gpsx__msg__Gpsx__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
void
gpsx__msg__Gpsx__Sequence__destroy(gpsx__msg__Gpsx__Sequence * array);

/// Check for msg/Gpsx message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
bool
gpsx__msg__Gpsx__Sequence__are_equal(const gpsx__msg__Gpsx__Sequence * lhs, const gpsx__msg__Gpsx__Sequence * rhs);

/// Copy an array of msg/Gpsx messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
bool
gpsx__msg__Gpsx__Sequence__copy(
  const gpsx__msg__Gpsx__Sequence * input,
  gpsx__msg__Gpsx__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GPSX__MSG__DETAIL__GPSX__FUNCTIONS_H_
