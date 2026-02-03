// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from gpsx:msg/Gpsx.idl
// generated code does not contain a copyright notice
#include "gpsx/msg/detail/gpsx__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "gpsx/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gpsx/msg/detail/gpsx__struct.h"
#include "gpsx/msg/detail/gpsx__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Gpsx__ros_msg_type = gpsx__msg__Gpsx;

static bool _Gpsx__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Gpsx__ros_msg_type * ros_message = static_cast<const _Gpsx__ros_msg_type *>(untyped_ros_message);
  // Field name: longitude
  {
    cdr << ros_message->longitude;
  }

  // Field name: latitude
  {
    cdr << ros_message->latitude;
  }

  // Field name: altitude
  {
    cdr << ros_message->altitude;
  }

  // Field name: ground_speed
  {
    cdr << ros_message->ground_speed;
  }

  // Field name: satellites
  {
    cdr << ros_message->satellites;
  }

  // Field name: mode_indicator
  {
    cdr << ros_message->mode_indicator;
  }

  // Field name: separation
  {
    cdr << ros_message->separation;
  }

  // Field name: true_course
  {
    cdr << ros_message->true_course;
  }

  // Field name: true_course_magnetic
  {
    cdr << ros_message->true_course_magnetic;
  }

  // Field name: dilution
  {
    cdr << ros_message->dilution;
  }

  // Field name: utc_time
  {
    cdr << ros_message->utc_time;
  }

  return true;
}

static bool _Gpsx__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Gpsx__ros_msg_type * ros_message = static_cast<_Gpsx__ros_msg_type *>(untyped_ros_message);
  // Field name: longitude
  {
    cdr >> ros_message->longitude;
  }

  // Field name: latitude
  {
    cdr >> ros_message->latitude;
  }

  // Field name: altitude
  {
    cdr >> ros_message->altitude;
  }

  // Field name: ground_speed
  {
    cdr >> ros_message->ground_speed;
  }

  // Field name: satellites
  {
    cdr >> ros_message->satellites;
  }

  // Field name: mode_indicator
  {
    cdr >> ros_message->mode_indicator;
  }

  // Field name: separation
  {
    cdr >> ros_message->separation;
  }

  // Field name: true_course
  {
    cdr >> ros_message->true_course;
  }

  // Field name: true_course_magnetic
  {
    cdr >> ros_message->true_course_magnetic;
  }

  // Field name: dilution
  {
    cdr >> ros_message->dilution;
  }

  // Field name: utc_time
  {
    cdr >> ros_message->utc_time;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gpsx
size_t get_serialized_size_gpsx__msg__Gpsx(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Gpsx__ros_msg_type * ros_message = static_cast<const _Gpsx__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name longitude
  {
    size_t item_size = sizeof(ros_message->longitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name latitude
  {
    size_t item_size = sizeof(ros_message->latitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name altitude
  {
    size_t item_size = sizeof(ros_message->altitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ground_speed
  {
    size_t item_size = sizeof(ros_message->ground_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name satellites
  {
    size_t item_size = sizeof(ros_message->satellites);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mode_indicator
  {
    size_t item_size = sizeof(ros_message->mode_indicator);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name separation
  {
    size_t item_size = sizeof(ros_message->separation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name true_course
  {
    size_t item_size = sizeof(ros_message->true_course);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name true_course_magnetic
  {
    size_t item_size = sizeof(ros_message->true_course_magnetic);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dilution
  {
    size_t item_size = sizeof(ros_message->dilution);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name utc_time
  {
    size_t item_size = sizeof(ros_message->utc_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Gpsx__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_gpsx__msg__Gpsx(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gpsx
size_t max_serialized_size_gpsx__msg__Gpsx(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: longitude
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: latitude
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: altitude
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: ground_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: satellites
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: mode_indicator
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: separation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: true_course
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: true_course_magnetic
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: dilution
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: utc_time
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = gpsx__msg__Gpsx;
    is_plain =
      (
      offsetof(DataType, utc_time) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Gpsx__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_gpsx__msg__Gpsx(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Gpsx = {
  "gpsx::msg",
  "Gpsx",
  _Gpsx__cdr_serialize,
  _Gpsx__cdr_deserialize,
  _Gpsx__get_serialized_size,
  _Gpsx__max_serialized_size
};

static rosidl_message_type_support_t _Gpsx__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Gpsx,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gpsx, msg, Gpsx)() {
  return &_Gpsx__type_support;
}

#if defined(__cplusplus)
}
#endif
