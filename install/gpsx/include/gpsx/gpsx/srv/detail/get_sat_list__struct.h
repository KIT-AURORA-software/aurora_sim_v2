// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gpsx:srv/GetSatList.idl
// generated code does not contain a copyright notice

#ifndef GPSX__SRV__DETAIL__GET_SAT_LIST__STRUCT_H_
#define GPSX__SRV__DETAIL__GET_SAT_LIST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetSatList in the package gpsx.
typedef struct gpsx__srv__GetSatList_Request
{
  int8_t type;
} gpsx__srv__GetSatList_Request;

// Struct for a sequence of gpsx__srv__GetSatList_Request.
typedef struct gpsx__srv__GetSatList_Request__Sequence
{
  gpsx__srv__GetSatList_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gpsx__srv__GetSatList_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'gnsstype'
// Member 'id'
// Member 'elevation'
// Member 'azimuth'
// Member 'snr'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/GetSatList in the package gpsx.
typedef struct gpsx__srv__GetSatList_Response
{
  rosidl_runtime_c__int16__Sequence gnsstype;
  rosidl_runtime_c__int16__Sequence id;
  rosidl_runtime_c__int16__Sequence elevation;
  rosidl_runtime_c__int16__Sequence azimuth;
  rosidl_runtime_c__int16__Sequence snr;
} gpsx__srv__GetSatList_Response;

// Struct for a sequence of gpsx__srv__GetSatList_Response.
typedef struct gpsx__srv__GetSatList_Response__Sequence
{
  gpsx__srv__GetSatList_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gpsx__srv__GetSatList_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GPSX__SRV__DETAIL__GET_SAT_LIST__STRUCT_H_
