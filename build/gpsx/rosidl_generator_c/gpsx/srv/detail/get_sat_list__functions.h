// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gpsx:srv/GetSatList.idl
// generated code does not contain a copyright notice

#ifndef GPSX__SRV__DETAIL__GET_SAT_LIST__FUNCTIONS_H_
#define GPSX__SRV__DETAIL__GET_SAT_LIST__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "gpsx/msg/rosidl_generator_c__visibility_control.h"

#include "gpsx/srv/detail/get_sat_list__struct.h"

/// Initialize srv/GetSatList message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gpsx__srv__GetSatList_Request
 * )) before or use
 * gpsx__srv__GetSatList_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
bool
gpsx__srv__GetSatList_Request__init(gpsx__srv__GetSatList_Request * msg);

/// Finalize srv/GetSatList message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
void
gpsx__srv__GetSatList_Request__fini(gpsx__srv__GetSatList_Request * msg);

/// Create srv/GetSatList message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gpsx__srv__GetSatList_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
gpsx__srv__GetSatList_Request *
gpsx__srv__GetSatList_Request__create();

/// Destroy srv/GetSatList message.
/**
 * It calls
 * gpsx__srv__GetSatList_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
void
gpsx__srv__GetSatList_Request__destroy(gpsx__srv__GetSatList_Request * msg);

/// Check for srv/GetSatList message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
bool
gpsx__srv__GetSatList_Request__are_equal(const gpsx__srv__GetSatList_Request * lhs, const gpsx__srv__GetSatList_Request * rhs);

/// Copy a srv/GetSatList message.
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
gpsx__srv__GetSatList_Request__copy(
  const gpsx__srv__GetSatList_Request * input,
  gpsx__srv__GetSatList_Request * output);

/// Initialize array of srv/GetSatList messages.
/**
 * It allocates the memory for the number of elements and calls
 * gpsx__srv__GetSatList_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
bool
gpsx__srv__GetSatList_Request__Sequence__init(gpsx__srv__GetSatList_Request__Sequence * array, size_t size);

/// Finalize array of srv/GetSatList messages.
/**
 * It calls
 * gpsx__srv__GetSatList_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
void
gpsx__srv__GetSatList_Request__Sequence__fini(gpsx__srv__GetSatList_Request__Sequence * array);

/// Create array of srv/GetSatList messages.
/**
 * It allocates the memory for the array and calls
 * gpsx__srv__GetSatList_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
gpsx__srv__GetSatList_Request__Sequence *
gpsx__srv__GetSatList_Request__Sequence__create(size_t size);

/// Destroy array of srv/GetSatList messages.
/**
 * It calls
 * gpsx__srv__GetSatList_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
void
gpsx__srv__GetSatList_Request__Sequence__destroy(gpsx__srv__GetSatList_Request__Sequence * array);

/// Check for srv/GetSatList message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
bool
gpsx__srv__GetSatList_Request__Sequence__are_equal(const gpsx__srv__GetSatList_Request__Sequence * lhs, const gpsx__srv__GetSatList_Request__Sequence * rhs);

/// Copy an array of srv/GetSatList messages.
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
gpsx__srv__GetSatList_Request__Sequence__copy(
  const gpsx__srv__GetSatList_Request__Sequence * input,
  gpsx__srv__GetSatList_Request__Sequence * output);

/// Initialize srv/GetSatList message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gpsx__srv__GetSatList_Response
 * )) before or use
 * gpsx__srv__GetSatList_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
bool
gpsx__srv__GetSatList_Response__init(gpsx__srv__GetSatList_Response * msg);

/// Finalize srv/GetSatList message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
void
gpsx__srv__GetSatList_Response__fini(gpsx__srv__GetSatList_Response * msg);

/// Create srv/GetSatList message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gpsx__srv__GetSatList_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
gpsx__srv__GetSatList_Response *
gpsx__srv__GetSatList_Response__create();

/// Destroy srv/GetSatList message.
/**
 * It calls
 * gpsx__srv__GetSatList_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
void
gpsx__srv__GetSatList_Response__destroy(gpsx__srv__GetSatList_Response * msg);

/// Check for srv/GetSatList message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
bool
gpsx__srv__GetSatList_Response__are_equal(const gpsx__srv__GetSatList_Response * lhs, const gpsx__srv__GetSatList_Response * rhs);

/// Copy a srv/GetSatList message.
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
gpsx__srv__GetSatList_Response__copy(
  const gpsx__srv__GetSatList_Response * input,
  gpsx__srv__GetSatList_Response * output);

/// Initialize array of srv/GetSatList messages.
/**
 * It allocates the memory for the number of elements and calls
 * gpsx__srv__GetSatList_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
bool
gpsx__srv__GetSatList_Response__Sequence__init(gpsx__srv__GetSatList_Response__Sequence * array, size_t size);

/// Finalize array of srv/GetSatList messages.
/**
 * It calls
 * gpsx__srv__GetSatList_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
void
gpsx__srv__GetSatList_Response__Sequence__fini(gpsx__srv__GetSatList_Response__Sequence * array);

/// Create array of srv/GetSatList messages.
/**
 * It allocates the memory for the array and calls
 * gpsx__srv__GetSatList_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
gpsx__srv__GetSatList_Response__Sequence *
gpsx__srv__GetSatList_Response__Sequence__create(size_t size);

/// Destroy array of srv/GetSatList messages.
/**
 * It calls
 * gpsx__srv__GetSatList_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
void
gpsx__srv__GetSatList_Response__Sequence__destroy(gpsx__srv__GetSatList_Response__Sequence * array);

/// Check for srv/GetSatList message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gpsx
bool
gpsx__srv__GetSatList_Response__Sequence__are_equal(const gpsx__srv__GetSatList_Response__Sequence * lhs, const gpsx__srv__GetSatList_Response__Sequence * rhs);

/// Copy an array of srv/GetSatList messages.
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
gpsx__srv__GetSatList_Response__Sequence__copy(
  const gpsx__srv__GetSatList_Response__Sequence * input,
  gpsx__srv__GetSatList_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GPSX__SRV__DETAIL__GET_SAT_LIST__FUNCTIONS_H_
