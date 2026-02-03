// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from gpsx:msg/Gpsx.idl
// generated code does not contain a copyright notice

#ifndef GPSX__MSG__DETAIL__GPSX__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define GPSX__MSG__DETAIL__GPSX__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "gpsx/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "gpsx/msg/detail/gpsx__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace gpsx
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gpsx
cdr_serialize(
  const gpsx::msg::Gpsx & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gpsx
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  gpsx::msg::Gpsx & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gpsx
get_serialized_size(
  const gpsx::msg::Gpsx & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gpsx
max_serialized_size_Gpsx(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace gpsx

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gpsx
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gpsx, msg, Gpsx)();

#ifdef __cplusplus
}
#endif

#endif  // GPSX__MSG__DETAIL__GPSX__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
