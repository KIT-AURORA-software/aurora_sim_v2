// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from gpsx:srv/GetSatList.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "gpsx/srv/detail/get_sat_list__rosidl_typesupport_introspection_c.h"
#include "gpsx/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "gpsx/srv/detail/get_sat_list__functions.h"
#include "gpsx/srv/detail/get_sat_list__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void gpsx__srv__GetSatList_Request__rosidl_typesupport_introspection_c__GetSatList_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gpsx__srv__GetSatList_Request__init(message_memory);
}

void gpsx__srv__GetSatList_Request__rosidl_typesupport_introspection_c__GetSatList_Request_fini_function(void * message_memory)
{
  gpsx__srv__GetSatList_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember gpsx__srv__GetSatList_Request__rosidl_typesupport_introspection_c__GetSatList_Request_message_member_array[1] = {
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gpsx__srv__GetSatList_Request, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gpsx__srv__GetSatList_Request__rosidl_typesupport_introspection_c__GetSatList_Request_message_members = {
  "gpsx__srv",  // message namespace
  "GetSatList_Request",  // message name
  1,  // number of fields
  sizeof(gpsx__srv__GetSatList_Request),
  gpsx__srv__GetSatList_Request__rosidl_typesupport_introspection_c__GetSatList_Request_message_member_array,  // message members
  gpsx__srv__GetSatList_Request__rosidl_typesupport_introspection_c__GetSatList_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  gpsx__srv__GetSatList_Request__rosidl_typesupport_introspection_c__GetSatList_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gpsx__srv__GetSatList_Request__rosidl_typesupport_introspection_c__GetSatList_Request_message_type_support_handle = {
  0,
  &gpsx__srv__GetSatList_Request__rosidl_typesupport_introspection_c__GetSatList_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gpsx
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gpsx, srv, GetSatList_Request)() {
  if (!gpsx__srv__GetSatList_Request__rosidl_typesupport_introspection_c__GetSatList_Request_message_type_support_handle.typesupport_identifier) {
    gpsx__srv__GetSatList_Request__rosidl_typesupport_introspection_c__GetSatList_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gpsx__srv__GetSatList_Request__rosidl_typesupport_introspection_c__GetSatList_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "gpsx/srv/detail/get_sat_list__rosidl_typesupport_introspection_c.h"
// already included above
// #include "gpsx/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "gpsx/srv/detail/get_sat_list__functions.h"
// already included above
// #include "gpsx/srv/detail/get_sat_list__struct.h"


// Include directives for member types
// Member `gnsstype`
// Member `id`
// Member `elevation`
// Member `azimuth`
// Member `snr`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__GetSatList_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gpsx__srv__GetSatList_Response__init(message_memory);
}

void gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__GetSatList_Response_fini_function(void * message_memory)
{
  gpsx__srv__GetSatList_Response__fini(message_memory);
}

size_t gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__size_function__GetSatList_Response__gnsstype(
  const void * untyped_member)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return member->size;
}

const void * gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__gnsstype(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void * gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__gnsstype(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__fetch_function__GetSatList_Response__gnsstype(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__gnsstype(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__assign_function__GetSatList_Response__gnsstype(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__gnsstype(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

bool gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__resize_function__GetSatList_Response__gnsstype(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  rosidl_runtime_c__int16__Sequence__fini(member);
  return rosidl_runtime_c__int16__Sequence__init(member, size);
}

size_t gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__size_function__GetSatList_Response__id(
  const void * untyped_member)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return member->size;
}

const void * gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__id(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void * gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__id(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__fetch_function__GetSatList_Response__id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__id(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__assign_function__GetSatList_Response__id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__id(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

bool gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__resize_function__GetSatList_Response__id(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  rosidl_runtime_c__int16__Sequence__fini(member);
  return rosidl_runtime_c__int16__Sequence__init(member, size);
}

size_t gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__size_function__GetSatList_Response__elevation(
  const void * untyped_member)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return member->size;
}

const void * gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__elevation(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void * gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__elevation(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__fetch_function__GetSatList_Response__elevation(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__elevation(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__assign_function__GetSatList_Response__elevation(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__elevation(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

bool gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__resize_function__GetSatList_Response__elevation(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  rosidl_runtime_c__int16__Sequence__fini(member);
  return rosidl_runtime_c__int16__Sequence__init(member, size);
}

size_t gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__size_function__GetSatList_Response__azimuth(
  const void * untyped_member)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return member->size;
}

const void * gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__azimuth(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void * gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__azimuth(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__fetch_function__GetSatList_Response__azimuth(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__azimuth(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__assign_function__GetSatList_Response__azimuth(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__azimuth(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

bool gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__resize_function__GetSatList_Response__azimuth(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  rosidl_runtime_c__int16__Sequence__fini(member);
  return rosidl_runtime_c__int16__Sequence__init(member, size);
}

size_t gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__size_function__GetSatList_Response__snr(
  const void * untyped_member)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return member->size;
}

const void * gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__snr(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void * gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__snr(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__fetch_function__GetSatList_Response__snr(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__snr(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__assign_function__GetSatList_Response__snr(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__snr(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

bool gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__resize_function__GetSatList_Response__snr(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  rosidl_runtime_c__int16__Sequence__fini(member);
  return rosidl_runtime_c__int16__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__GetSatList_Response_message_member_array[5] = {
  {
    "gnsstype",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gpsx__srv__GetSatList_Response, gnsstype),  // bytes offset in struct
    NULL,  // default value
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__size_function__GetSatList_Response__gnsstype,  // size() function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__gnsstype,  // get_const(index) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__gnsstype,  // get(index) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__fetch_function__GetSatList_Response__gnsstype,  // fetch(index, &value) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__assign_function__GetSatList_Response__gnsstype,  // assign(index, value) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__resize_function__GetSatList_Response__gnsstype  // resize(index) function pointer
  },
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gpsx__srv__GetSatList_Response, id),  // bytes offset in struct
    NULL,  // default value
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__size_function__GetSatList_Response__id,  // size() function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__id,  // get_const(index) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__id,  // get(index) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__fetch_function__GetSatList_Response__id,  // fetch(index, &value) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__assign_function__GetSatList_Response__id,  // assign(index, value) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__resize_function__GetSatList_Response__id  // resize(index) function pointer
  },
  {
    "elevation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gpsx__srv__GetSatList_Response, elevation),  // bytes offset in struct
    NULL,  // default value
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__size_function__GetSatList_Response__elevation,  // size() function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__elevation,  // get_const(index) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__elevation,  // get(index) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__fetch_function__GetSatList_Response__elevation,  // fetch(index, &value) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__assign_function__GetSatList_Response__elevation,  // assign(index, value) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__resize_function__GetSatList_Response__elevation  // resize(index) function pointer
  },
  {
    "azimuth",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gpsx__srv__GetSatList_Response, azimuth),  // bytes offset in struct
    NULL,  // default value
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__size_function__GetSatList_Response__azimuth,  // size() function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__azimuth,  // get_const(index) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__azimuth,  // get(index) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__fetch_function__GetSatList_Response__azimuth,  // fetch(index, &value) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__assign_function__GetSatList_Response__azimuth,  // assign(index, value) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__resize_function__GetSatList_Response__azimuth  // resize(index) function pointer
  },
  {
    "snr",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gpsx__srv__GetSatList_Response, snr),  // bytes offset in struct
    NULL,  // default value
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__size_function__GetSatList_Response__snr,  // size() function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_const_function__GetSatList_Response__snr,  // get_const(index) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__get_function__GetSatList_Response__snr,  // get(index) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__fetch_function__GetSatList_Response__snr,  // fetch(index, &value) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__assign_function__GetSatList_Response__snr,  // assign(index, value) function pointer
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__resize_function__GetSatList_Response__snr  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__GetSatList_Response_message_members = {
  "gpsx__srv",  // message namespace
  "GetSatList_Response",  // message name
  5,  // number of fields
  sizeof(gpsx__srv__GetSatList_Response),
  gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__GetSatList_Response_message_member_array,  // message members
  gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__GetSatList_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__GetSatList_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__GetSatList_Response_message_type_support_handle = {
  0,
  &gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__GetSatList_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gpsx
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gpsx, srv, GetSatList_Response)() {
  if (!gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__GetSatList_Response_message_type_support_handle.typesupport_identifier) {
    gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__GetSatList_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gpsx__srv__GetSatList_Response__rosidl_typesupport_introspection_c__GetSatList_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "gpsx/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "gpsx/srv/detail/get_sat_list__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers gpsx__srv__detail__get_sat_list__rosidl_typesupport_introspection_c__GetSatList_service_members = {
  "gpsx__srv",  // service namespace
  "GetSatList",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // gpsx__srv__detail__get_sat_list__rosidl_typesupport_introspection_c__GetSatList_Request_message_type_support_handle,
  NULL  // response message
  // gpsx__srv__detail__get_sat_list__rosidl_typesupport_introspection_c__GetSatList_Response_message_type_support_handle
};

static rosidl_service_type_support_t gpsx__srv__detail__get_sat_list__rosidl_typesupport_introspection_c__GetSatList_service_type_support_handle = {
  0,
  &gpsx__srv__detail__get_sat_list__rosidl_typesupport_introspection_c__GetSatList_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gpsx, srv, GetSatList_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gpsx, srv, GetSatList_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gpsx
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gpsx, srv, GetSatList)() {
  if (!gpsx__srv__detail__get_sat_list__rosidl_typesupport_introspection_c__GetSatList_service_type_support_handle.typesupport_identifier) {
    gpsx__srv__detail__get_sat_list__rosidl_typesupport_introspection_c__GetSatList_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)gpsx__srv__detail__get_sat_list__rosidl_typesupport_introspection_c__GetSatList_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gpsx, srv, GetSatList_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gpsx, srv, GetSatList_Response)()->data;
  }

  return &gpsx__srv__detail__get_sat_list__rosidl_typesupport_introspection_c__GetSatList_service_type_support_handle;
}
