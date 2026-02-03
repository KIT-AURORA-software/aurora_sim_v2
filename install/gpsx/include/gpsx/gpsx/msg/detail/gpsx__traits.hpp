// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gpsx:msg/Gpsx.idl
// generated code does not contain a copyright notice

#ifndef GPSX__MSG__DETAIL__GPSX__TRAITS_HPP_
#define GPSX__MSG__DETAIL__GPSX__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gpsx/msg/detail/gpsx__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace gpsx
{

namespace msg
{

inline void to_flow_style_yaml(
  const Gpsx & msg,
  std::ostream & out)
{
  out << "{";
  // member: longitude
  {
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << ", ";
  }

  // member: latitude
  {
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << ", ";
  }

  // member: altitude
  {
    out << "altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude, out);
    out << ", ";
  }

  // member: ground_speed
  {
    out << "ground_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.ground_speed, out);
    out << ", ";
  }

  // member: satellites
  {
    out << "satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.satellites, out);
    out << ", ";
  }

  // member: mode_indicator
  {
    out << "mode_indicator: ";
    rosidl_generator_traits::value_to_yaml(msg.mode_indicator, out);
    out << ", ";
  }

  // member: separation
  {
    out << "separation: ";
    rosidl_generator_traits::value_to_yaml(msg.separation, out);
    out << ", ";
  }

  // member: true_course
  {
    out << "true_course: ";
    rosidl_generator_traits::value_to_yaml(msg.true_course, out);
    out << ", ";
  }

  // member: true_course_magnetic
  {
    out << "true_course_magnetic: ";
    rosidl_generator_traits::value_to_yaml(msg.true_course_magnetic, out);
    out << ", ";
  }

  // member: dilution
  {
    out << "dilution: ";
    rosidl_generator_traits::value_to_yaml(msg.dilution, out);
    out << ", ";
  }

  // member: utc_time
  {
    out << "utc_time: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Gpsx & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: longitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << "\n";
  }

  // member: latitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << "\n";
  }

  // member: altitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude, out);
    out << "\n";
  }

  // member: ground_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ground_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.ground_speed, out);
    out << "\n";
  }

  // member: satellites
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.satellites, out);
    out << "\n";
  }

  // member: mode_indicator
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode_indicator: ";
    rosidl_generator_traits::value_to_yaml(msg.mode_indicator, out);
    out << "\n";
  }

  // member: separation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "separation: ";
    rosidl_generator_traits::value_to_yaml(msg.separation, out);
    out << "\n";
  }

  // member: true_course
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "true_course: ";
    rosidl_generator_traits::value_to_yaml(msg.true_course, out);
    out << "\n";
  }

  // member: true_course_magnetic
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "true_course_magnetic: ";
    rosidl_generator_traits::value_to_yaml(msg.true_course_magnetic, out);
    out << "\n";
  }

  // member: dilution
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dilution: ";
    rosidl_generator_traits::value_to_yaml(msg.dilution, out);
    out << "\n";
  }

  // member: utc_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utc_time: ";
    rosidl_generator_traits::value_to_yaml(msg.utc_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Gpsx & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace gpsx

namespace rosidl_generator_traits
{

[[deprecated("use gpsx::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gpsx::msg::Gpsx & msg,
  std::ostream & out, size_t indentation = 0)
{
  gpsx::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gpsx::msg::to_yaml() instead")]]
inline std::string to_yaml(const gpsx::msg::Gpsx & msg)
{
  return gpsx::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gpsx::msg::Gpsx>()
{
  return "gpsx::msg::Gpsx";
}

template<>
inline const char * name<gpsx::msg::Gpsx>()
{
  return "gpsx/msg/Gpsx";
}

template<>
struct has_fixed_size<gpsx::msg::Gpsx>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gpsx::msg::Gpsx>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gpsx::msg::Gpsx>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GPSX__MSG__DETAIL__GPSX__TRAITS_HPP_
