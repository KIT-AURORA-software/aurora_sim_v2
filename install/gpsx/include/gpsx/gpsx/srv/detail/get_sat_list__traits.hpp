// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gpsx:srv/GetSatList.idl
// generated code does not contain a copyright notice

#ifndef GPSX__SRV__DETAIL__GET_SAT_LIST__TRAITS_HPP_
#define GPSX__SRV__DETAIL__GET_SAT_LIST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gpsx/srv/detail/get_sat_list__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace gpsx
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSatList_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSatList_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSatList_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace gpsx

namespace rosidl_generator_traits
{

[[deprecated("use gpsx::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gpsx::srv::GetSatList_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  gpsx::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gpsx::srv::to_yaml() instead")]]
inline std::string to_yaml(const gpsx::srv::GetSatList_Request & msg)
{
  return gpsx::srv::to_yaml(msg);
}

template<>
inline const char * data_type<gpsx::srv::GetSatList_Request>()
{
  return "gpsx::srv::GetSatList_Request";
}

template<>
inline const char * name<gpsx::srv::GetSatList_Request>()
{
  return "gpsx/srv/GetSatList_Request";
}

template<>
struct has_fixed_size<gpsx::srv::GetSatList_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gpsx::srv::GetSatList_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gpsx::srv::GetSatList_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace gpsx
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSatList_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: gnsstype
  {
    if (msg.gnsstype.size() == 0) {
      out << "gnsstype: []";
    } else {
      out << "gnsstype: [";
      size_t pending_items = msg.gnsstype.size();
      for (auto item : msg.gnsstype) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: id
  {
    if (msg.id.size() == 0) {
      out << "id: []";
    } else {
      out << "id: [";
      size_t pending_items = msg.id.size();
      for (auto item : msg.id) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: elevation
  {
    if (msg.elevation.size() == 0) {
      out << "elevation: []";
    } else {
      out << "elevation: [";
      size_t pending_items = msg.elevation.size();
      for (auto item : msg.elevation) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: azimuth
  {
    if (msg.azimuth.size() == 0) {
      out << "azimuth: []";
    } else {
      out << "azimuth: [";
      size_t pending_items = msg.azimuth.size();
      for (auto item : msg.azimuth) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: snr
  {
    if (msg.snr.size() == 0) {
      out << "snr: []";
    } else {
      out << "snr: [";
      size_t pending_items = msg.snr.size();
      for (auto item : msg.snr) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSatList_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: gnsstype
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.gnsstype.size() == 0) {
      out << "gnsstype: []\n";
    } else {
      out << "gnsstype:\n";
      for (auto item : msg.gnsstype) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.id.size() == 0) {
      out << "id: []\n";
    } else {
      out << "id:\n";
      for (auto item : msg.id) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: elevation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.elevation.size() == 0) {
      out << "elevation: []\n";
    } else {
      out << "elevation:\n";
      for (auto item : msg.elevation) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: azimuth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.azimuth.size() == 0) {
      out << "azimuth: []\n";
    } else {
      out << "azimuth:\n";
      for (auto item : msg.azimuth) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: snr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.snr.size() == 0) {
      out << "snr: []\n";
    } else {
      out << "snr:\n";
      for (auto item : msg.snr) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSatList_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace gpsx

namespace rosidl_generator_traits
{

[[deprecated("use gpsx::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gpsx::srv::GetSatList_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  gpsx::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gpsx::srv::to_yaml() instead")]]
inline std::string to_yaml(const gpsx::srv::GetSatList_Response & msg)
{
  return gpsx::srv::to_yaml(msg);
}

template<>
inline const char * data_type<gpsx::srv::GetSatList_Response>()
{
  return "gpsx::srv::GetSatList_Response";
}

template<>
inline const char * name<gpsx::srv::GetSatList_Response>()
{
  return "gpsx/srv/GetSatList_Response";
}

template<>
struct has_fixed_size<gpsx::srv::GetSatList_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<gpsx::srv::GetSatList_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<gpsx::srv::GetSatList_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<gpsx::srv::GetSatList>()
{
  return "gpsx::srv::GetSatList";
}

template<>
inline const char * name<gpsx::srv::GetSatList>()
{
  return "gpsx/srv/GetSatList";
}

template<>
struct has_fixed_size<gpsx::srv::GetSatList>
  : std::integral_constant<
    bool,
    has_fixed_size<gpsx::srv::GetSatList_Request>::value &&
    has_fixed_size<gpsx::srv::GetSatList_Response>::value
  >
{
};

template<>
struct has_bounded_size<gpsx::srv::GetSatList>
  : std::integral_constant<
    bool,
    has_bounded_size<gpsx::srv::GetSatList_Request>::value &&
    has_bounded_size<gpsx::srv::GetSatList_Response>::value
  >
{
};

template<>
struct is_service<gpsx::srv::GetSatList>
  : std::true_type
{
};

template<>
struct is_service_request<gpsx::srv::GetSatList_Request>
  : std::true_type
{
};

template<>
struct is_service_response<gpsx::srv::GetSatList_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // GPSX__SRV__DETAIL__GET_SAT_LIST__TRAITS_HPP_
