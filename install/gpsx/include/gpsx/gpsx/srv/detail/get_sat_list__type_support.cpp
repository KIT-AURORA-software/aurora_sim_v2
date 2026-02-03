// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from gpsx:srv/GetSatList.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "gpsx/srv/detail/get_sat_list__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace gpsx
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetSatList_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) gpsx::srv::GetSatList_Request(_init);
}

void GetSatList_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<gpsx::srv::GetSatList_Request *>(message_memory);
  typed_message->~GetSatList_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetSatList_Request_message_member_array[1] = {
  {
    "type",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gpsx::srv::GetSatList_Request, type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetSatList_Request_message_members = {
  "gpsx::srv",  // message namespace
  "GetSatList_Request",  // message name
  1,  // number of fields
  sizeof(gpsx::srv::GetSatList_Request),
  GetSatList_Request_message_member_array,  // message members
  GetSatList_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GetSatList_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetSatList_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetSatList_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace gpsx


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<gpsx::srv::GetSatList_Request>()
{
  return &::gpsx::srv::rosidl_typesupport_introspection_cpp::GetSatList_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, gpsx, srv, GetSatList_Request)() {
  return &::gpsx::srv::rosidl_typesupport_introspection_cpp::GetSatList_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "gpsx/srv/detail/get_sat_list__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace gpsx
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetSatList_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) gpsx::srv::GetSatList_Response(_init);
}

void GetSatList_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<gpsx::srv::GetSatList_Response *>(message_memory);
  typed_message->~GetSatList_Response();
}

size_t size_function__GetSatList_Response__gnsstype(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetSatList_Response__gnsstype(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void * get_function__GetSatList_Response__gnsstype(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetSatList_Response__gnsstype(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int16_t *>(
    get_const_function__GetSatList_Response__gnsstype(untyped_member, index));
  auto & value = *reinterpret_cast<int16_t *>(untyped_value);
  value = item;
}

void assign_function__GetSatList_Response__gnsstype(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int16_t *>(
    get_function__GetSatList_Response__gnsstype(untyped_member, index));
  const auto & value = *reinterpret_cast<const int16_t *>(untyped_value);
  item = value;
}

void resize_function__GetSatList_Response__gnsstype(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GetSatList_Response__id(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetSatList_Response__id(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void * get_function__GetSatList_Response__id(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetSatList_Response__id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int16_t *>(
    get_const_function__GetSatList_Response__id(untyped_member, index));
  auto & value = *reinterpret_cast<int16_t *>(untyped_value);
  value = item;
}

void assign_function__GetSatList_Response__id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int16_t *>(
    get_function__GetSatList_Response__id(untyped_member, index));
  const auto & value = *reinterpret_cast<const int16_t *>(untyped_value);
  item = value;
}

void resize_function__GetSatList_Response__id(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GetSatList_Response__elevation(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetSatList_Response__elevation(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void * get_function__GetSatList_Response__elevation(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetSatList_Response__elevation(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int16_t *>(
    get_const_function__GetSatList_Response__elevation(untyped_member, index));
  auto & value = *reinterpret_cast<int16_t *>(untyped_value);
  value = item;
}

void assign_function__GetSatList_Response__elevation(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int16_t *>(
    get_function__GetSatList_Response__elevation(untyped_member, index));
  const auto & value = *reinterpret_cast<const int16_t *>(untyped_value);
  item = value;
}

void resize_function__GetSatList_Response__elevation(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GetSatList_Response__azimuth(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetSatList_Response__azimuth(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void * get_function__GetSatList_Response__azimuth(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetSatList_Response__azimuth(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int16_t *>(
    get_const_function__GetSatList_Response__azimuth(untyped_member, index));
  auto & value = *reinterpret_cast<int16_t *>(untyped_value);
  value = item;
}

void assign_function__GetSatList_Response__azimuth(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int16_t *>(
    get_function__GetSatList_Response__azimuth(untyped_member, index));
  const auto & value = *reinterpret_cast<const int16_t *>(untyped_value);
  item = value;
}

void resize_function__GetSatList_Response__azimuth(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GetSatList_Response__snr(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetSatList_Response__snr(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void * get_function__GetSatList_Response__snr(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetSatList_Response__snr(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int16_t *>(
    get_const_function__GetSatList_Response__snr(untyped_member, index));
  auto & value = *reinterpret_cast<int16_t *>(untyped_value);
  value = item;
}

void assign_function__GetSatList_Response__snr(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int16_t *>(
    get_function__GetSatList_Response__snr(untyped_member, index));
  const auto & value = *reinterpret_cast<const int16_t *>(untyped_value);
  item = value;
}

void resize_function__GetSatList_Response__snr(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetSatList_Response_message_member_array[5] = {
  {
    "gnsstype",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gpsx::srv::GetSatList_Response, gnsstype),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetSatList_Response__gnsstype,  // size() function pointer
    get_const_function__GetSatList_Response__gnsstype,  // get_const(index) function pointer
    get_function__GetSatList_Response__gnsstype,  // get(index) function pointer
    fetch_function__GetSatList_Response__gnsstype,  // fetch(index, &value) function pointer
    assign_function__GetSatList_Response__gnsstype,  // assign(index, value) function pointer
    resize_function__GetSatList_Response__gnsstype  // resize(index) function pointer
  },
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gpsx::srv::GetSatList_Response, id),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetSatList_Response__id,  // size() function pointer
    get_const_function__GetSatList_Response__id,  // get_const(index) function pointer
    get_function__GetSatList_Response__id,  // get(index) function pointer
    fetch_function__GetSatList_Response__id,  // fetch(index, &value) function pointer
    assign_function__GetSatList_Response__id,  // assign(index, value) function pointer
    resize_function__GetSatList_Response__id  // resize(index) function pointer
  },
  {
    "elevation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gpsx::srv::GetSatList_Response, elevation),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetSatList_Response__elevation,  // size() function pointer
    get_const_function__GetSatList_Response__elevation,  // get_const(index) function pointer
    get_function__GetSatList_Response__elevation,  // get(index) function pointer
    fetch_function__GetSatList_Response__elevation,  // fetch(index, &value) function pointer
    assign_function__GetSatList_Response__elevation,  // assign(index, value) function pointer
    resize_function__GetSatList_Response__elevation  // resize(index) function pointer
  },
  {
    "azimuth",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gpsx::srv::GetSatList_Response, azimuth),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetSatList_Response__azimuth,  // size() function pointer
    get_const_function__GetSatList_Response__azimuth,  // get_const(index) function pointer
    get_function__GetSatList_Response__azimuth,  // get(index) function pointer
    fetch_function__GetSatList_Response__azimuth,  // fetch(index, &value) function pointer
    assign_function__GetSatList_Response__azimuth,  // assign(index, value) function pointer
    resize_function__GetSatList_Response__azimuth  // resize(index) function pointer
  },
  {
    "snr",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gpsx::srv::GetSatList_Response, snr),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetSatList_Response__snr,  // size() function pointer
    get_const_function__GetSatList_Response__snr,  // get_const(index) function pointer
    get_function__GetSatList_Response__snr,  // get(index) function pointer
    fetch_function__GetSatList_Response__snr,  // fetch(index, &value) function pointer
    assign_function__GetSatList_Response__snr,  // assign(index, value) function pointer
    resize_function__GetSatList_Response__snr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetSatList_Response_message_members = {
  "gpsx::srv",  // message namespace
  "GetSatList_Response",  // message name
  5,  // number of fields
  sizeof(gpsx::srv::GetSatList_Response),
  GetSatList_Response_message_member_array,  // message members
  GetSatList_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GetSatList_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetSatList_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetSatList_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace gpsx


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<gpsx::srv::GetSatList_Response>()
{
  return &::gpsx::srv::rosidl_typesupport_introspection_cpp::GetSatList_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, gpsx, srv, GetSatList_Response)() {
  return &::gpsx::srv::rosidl_typesupport_introspection_cpp::GetSatList_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "gpsx/srv/detail/get_sat_list__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace gpsx
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers GetSatList_service_members = {
  "gpsx::srv",  // service namespace
  "GetSatList",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<gpsx::srv::GetSatList>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t GetSatList_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetSatList_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace gpsx


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<gpsx::srv::GetSatList>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::gpsx::srv::rosidl_typesupport_introspection_cpp::GetSatList_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::gpsx::srv::GetSatList_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::gpsx::srv::GetSatList_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, gpsx, srv, GetSatList)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<gpsx::srv::GetSatList>();
}

#ifdef __cplusplus
}
#endif
