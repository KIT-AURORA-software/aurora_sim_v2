// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gpsx:srv/GetSatList.idl
// generated code does not contain a copyright notice

#ifndef GPSX__SRV__DETAIL__GET_SAT_LIST__BUILDER_HPP_
#define GPSX__SRV__DETAIL__GET_SAT_LIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gpsx/srv/detail/get_sat_list__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gpsx
{

namespace srv
{

namespace builder
{

class Init_GetSatList_Request_type
{
public:
  Init_GetSatList_Request_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gpsx::srv::GetSatList_Request type(::gpsx::srv::GetSatList_Request::_type_type arg)
  {
    msg_.type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gpsx::srv::GetSatList_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gpsx::srv::GetSatList_Request>()
{
  return gpsx::srv::builder::Init_GetSatList_Request_type();
}

}  // namespace gpsx


namespace gpsx
{

namespace srv
{

namespace builder
{

class Init_GetSatList_Response_snr
{
public:
  explicit Init_GetSatList_Response_snr(::gpsx::srv::GetSatList_Response & msg)
  : msg_(msg)
  {}
  ::gpsx::srv::GetSatList_Response snr(::gpsx::srv::GetSatList_Response::_snr_type arg)
  {
    msg_.snr = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gpsx::srv::GetSatList_Response msg_;
};

class Init_GetSatList_Response_azimuth
{
public:
  explicit Init_GetSatList_Response_azimuth(::gpsx::srv::GetSatList_Response & msg)
  : msg_(msg)
  {}
  Init_GetSatList_Response_snr azimuth(::gpsx::srv::GetSatList_Response::_azimuth_type arg)
  {
    msg_.azimuth = std::move(arg);
    return Init_GetSatList_Response_snr(msg_);
  }

private:
  ::gpsx::srv::GetSatList_Response msg_;
};

class Init_GetSatList_Response_elevation
{
public:
  explicit Init_GetSatList_Response_elevation(::gpsx::srv::GetSatList_Response & msg)
  : msg_(msg)
  {}
  Init_GetSatList_Response_azimuth elevation(::gpsx::srv::GetSatList_Response::_elevation_type arg)
  {
    msg_.elevation = std::move(arg);
    return Init_GetSatList_Response_azimuth(msg_);
  }

private:
  ::gpsx::srv::GetSatList_Response msg_;
};

class Init_GetSatList_Response_id
{
public:
  explicit Init_GetSatList_Response_id(::gpsx::srv::GetSatList_Response & msg)
  : msg_(msg)
  {}
  Init_GetSatList_Response_elevation id(::gpsx::srv::GetSatList_Response::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_GetSatList_Response_elevation(msg_);
  }

private:
  ::gpsx::srv::GetSatList_Response msg_;
};

class Init_GetSatList_Response_gnsstype
{
public:
  Init_GetSatList_Response_gnsstype()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSatList_Response_id gnsstype(::gpsx::srv::GetSatList_Response::_gnsstype_type arg)
  {
    msg_.gnsstype = std::move(arg);
    return Init_GetSatList_Response_id(msg_);
  }

private:
  ::gpsx::srv::GetSatList_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gpsx::srv::GetSatList_Response>()
{
  return gpsx::srv::builder::Init_GetSatList_Response_gnsstype();
}

}  // namespace gpsx

#endif  // GPSX__SRV__DETAIL__GET_SAT_LIST__BUILDER_HPP_
