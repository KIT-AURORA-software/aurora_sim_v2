// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gpsx:msg/Gpsx.idl
// generated code does not contain a copyright notice

#ifndef GPSX__MSG__DETAIL__GPSX__STRUCT_H_
#define GPSX__MSG__DETAIL__GPSX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Gpsx in the package gpsx.
typedef struct gpsx__msg__Gpsx
{
  double longitude;
  double latitude;
  double altitude;
  float ground_speed;
  uint8_t satellites;
  uint8_t mode_indicator;
  float separation;
  float true_course;
  float true_course_magnetic;
  float dilution;
  uint32_t utc_time;
} gpsx__msg__Gpsx;

// Struct for a sequence of gpsx__msg__Gpsx.
typedef struct gpsx__msg__Gpsx__Sequence
{
  gpsx__msg__Gpsx * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gpsx__msg__Gpsx__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GPSX__MSG__DETAIL__GPSX__STRUCT_H_
