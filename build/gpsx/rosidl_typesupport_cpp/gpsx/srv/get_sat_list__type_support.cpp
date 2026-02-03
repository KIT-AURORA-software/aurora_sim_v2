// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from gpsx:srv/GetSatList.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "gpsx/srv/detail/get_sat_list__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace gpsx
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetSatList_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetSatList_Request_type_support_ids_t;

static const _GetSatList_Request_type_support_ids_t _GetSatList_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetSatList_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetSatList_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetSatList_Request_type_support_symbol_names_t _GetSatList_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gpsx, srv, GetSatList_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, gpsx, srv, GetSatList_Request)),
  }
};

typedef struct _GetSatList_Request_type_support_data_t
{
  void * data[2];
} _GetSatList_Request_type_support_data_t;

static _GetSatList_Request_type_support_data_t _GetSatList_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetSatList_Request_message_typesupport_map = {
  2,
  "gpsx",
  &_GetSatList_Request_message_typesupport_ids.typesupport_identifier[0],
  &_GetSatList_Request_message_typesupport_symbol_names.symbol_name[0],
  &_GetSatList_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetSatList_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetSatList_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace gpsx

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<gpsx::srv::GetSatList_Request>()
{
  return &::gpsx::srv::rosidl_typesupport_cpp::GetSatList_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, gpsx, srv, GetSatList_Request)() {
  return get_message_type_support_handle<gpsx::srv::GetSatList_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "gpsx/srv/detail/get_sat_list__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace gpsx
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetSatList_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetSatList_Response_type_support_ids_t;

static const _GetSatList_Response_type_support_ids_t _GetSatList_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetSatList_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetSatList_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetSatList_Response_type_support_symbol_names_t _GetSatList_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gpsx, srv, GetSatList_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, gpsx, srv, GetSatList_Response)),
  }
};

typedef struct _GetSatList_Response_type_support_data_t
{
  void * data[2];
} _GetSatList_Response_type_support_data_t;

static _GetSatList_Response_type_support_data_t _GetSatList_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetSatList_Response_message_typesupport_map = {
  2,
  "gpsx",
  &_GetSatList_Response_message_typesupport_ids.typesupport_identifier[0],
  &_GetSatList_Response_message_typesupport_symbol_names.symbol_name[0],
  &_GetSatList_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetSatList_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetSatList_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace gpsx

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<gpsx::srv::GetSatList_Response>()
{
  return &::gpsx::srv::rosidl_typesupport_cpp::GetSatList_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, gpsx, srv, GetSatList_Response)() {
  return get_message_type_support_handle<gpsx::srv::GetSatList_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "gpsx/srv/detail/get_sat_list__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace gpsx
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetSatList_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetSatList_type_support_ids_t;

static const _GetSatList_type_support_ids_t _GetSatList_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetSatList_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetSatList_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetSatList_type_support_symbol_names_t _GetSatList_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gpsx, srv, GetSatList)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, gpsx, srv, GetSatList)),
  }
};

typedef struct _GetSatList_type_support_data_t
{
  void * data[2];
} _GetSatList_type_support_data_t;

static _GetSatList_type_support_data_t _GetSatList_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetSatList_service_typesupport_map = {
  2,
  "gpsx",
  &_GetSatList_service_typesupport_ids.typesupport_identifier[0],
  &_GetSatList_service_typesupport_symbol_names.symbol_name[0],
  &_GetSatList_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GetSatList_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetSatList_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace gpsx

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<gpsx::srv::GetSatList>()
{
  return &::gpsx::srv::rosidl_typesupport_cpp::GetSatList_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, gpsx, srv, GetSatList)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<gpsx::srv::GetSatList>();
}

#ifdef __cplusplus
}
#endif
