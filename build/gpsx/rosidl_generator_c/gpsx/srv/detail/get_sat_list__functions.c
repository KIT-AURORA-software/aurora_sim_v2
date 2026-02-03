// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gpsx:srv/GetSatList.idl
// generated code does not contain a copyright notice
#include "gpsx/srv/detail/get_sat_list__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
gpsx__srv__GetSatList_Request__init(gpsx__srv__GetSatList_Request * msg)
{
  if (!msg) {
    return false;
  }
  // type
  return true;
}

void
gpsx__srv__GetSatList_Request__fini(gpsx__srv__GetSatList_Request * msg)
{
  if (!msg) {
    return;
  }
  // type
}

bool
gpsx__srv__GetSatList_Request__are_equal(const gpsx__srv__GetSatList_Request * lhs, const gpsx__srv__GetSatList_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (lhs->type != rhs->type) {
    return false;
  }
  return true;
}

bool
gpsx__srv__GetSatList_Request__copy(
  const gpsx__srv__GetSatList_Request * input,
  gpsx__srv__GetSatList_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  output->type = input->type;
  return true;
}

gpsx__srv__GetSatList_Request *
gpsx__srv__GetSatList_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gpsx__srv__GetSatList_Request * msg = (gpsx__srv__GetSatList_Request *)allocator.allocate(sizeof(gpsx__srv__GetSatList_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gpsx__srv__GetSatList_Request));
  bool success = gpsx__srv__GetSatList_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gpsx__srv__GetSatList_Request__destroy(gpsx__srv__GetSatList_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gpsx__srv__GetSatList_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gpsx__srv__GetSatList_Request__Sequence__init(gpsx__srv__GetSatList_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gpsx__srv__GetSatList_Request * data = NULL;

  if (size) {
    data = (gpsx__srv__GetSatList_Request *)allocator.zero_allocate(size, sizeof(gpsx__srv__GetSatList_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gpsx__srv__GetSatList_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gpsx__srv__GetSatList_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
gpsx__srv__GetSatList_Request__Sequence__fini(gpsx__srv__GetSatList_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      gpsx__srv__GetSatList_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

gpsx__srv__GetSatList_Request__Sequence *
gpsx__srv__GetSatList_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gpsx__srv__GetSatList_Request__Sequence * array = (gpsx__srv__GetSatList_Request__Sequence *)allocator.allocate(sizeof(gpsx__srv__GetSatList_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gpsx__srv__GetSatList_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gpsx__srv__GetSatList_Request__Sequence__destroy(gpsx__srv__GetSatList_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gpsx__srv__GetSatList_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gpsx__srv__GetSatList_Request__Sequence__are_equal(const gpsx__srv__GetSatList_Request__Sequence * lhs, const gpsx__srv__GetSatList_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gpsx__srv__GetSatList_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gpsx__srv__GetSatList_Request__Sequence__copy(
  const gpsx__srv__GetSatList_Request__Sequence * input,
  gpsx__srv__GetSatList_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gpsx__srv__GetSatList_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gpsx__srv__GetSatList_Request * data =
      (gpsx__srv__GetSatList_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gpsx__srv__GetSatList_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gpsx__srv__GetSatList_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gpsx__srv__GetSatList_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `gnsstype`
// Member `id`
// Member `elevation`
// Member `azimuth`
// Member `snr`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
gpsx__srv__GetSatList_Response__init(gpsx__srv__GetSatList_Response * msg)
{
  if (!msg) {
    return false;
  }
  // gnsstype
  if (!rosidl_runtime_c__int16__Sequence__init(&msg->gnsstype, 0)) {
    gpsx__srv__GetSatList_Response__fini(msg);
    return false;
  }
  // id
  if (!rosidl_runtime_c__int16__Sequence__init(&msg->id, 0)) {
    gpsx__srv__GetSatList_Response__fini(msg);
    return false;
  }
  // elevation
  if (!rosidl_runtime_c__int16__Sequence__init(&msg->elevation, 0)) {
    gpsx__srv__GetSatList_Response__fini(msg);
    return false;
  }
  // azimuth
  if (!rosidl_runtime_c__int16__Sequence__init(&msg->azimuth, 0)) {
    gpsx__srv__GetSatList_Response__fini(msg);
    return false;
  }
  // snr
  if (!rosidl_runtime_c__int16__Sequence__init(&msg->snr, 0)) {
    gpsx__srv__GetSatList_Response__fini(msg);
    return false;
  }
  return true;
}

void
gpsx__srv__GetSatList_Response__fini(gpsx__srv__GetSatList_Response * msg)
{
  if (!msg) {
    return;
  }
  // gnsstype
  rosidl_runtime_c__int16__Sequence__fini(&msg->gnsstype);
  // id
  rosidl_runtime_c__int16__Sequence__fini(&msg->id);
  // elevation
  rosidl_runtime_c__int16__Sequence__fini(&msg->elevation);
  // azimuth
  rosidl_runtime_c__int16__Sequence__fini(&msg->azimuth);
  // snr
  rosidl_runtime_c__int16__Sequence__fini(&msg->snr);
}

bool
gpsx__srv__GetSatList_Response__are_equal(const gpsx__srv__GetSatList_Response * lhs, const gpsx__srv__GetSatList_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // gnsstype
  if (!rosidl_runtime_c__int16__Sequence__are_equal(
      &(lhs->gnsstype), &(rhs->gnsstype)))
  {
    return false;
  }
  // id
  if (!rosidl_runtime_c__int16__Sequence__are_equal(
      &(lhs->id), &(rhs->id)))
  {
    return false;
  }
  // elevation
  if (!rosidl_runtime_c__int16__Sequence__are_equal(
      &(lhs->elevation), &(rhs->elevation)))
  {
    return false;
  }
  // azimuth
  if (!rosidl_runtime_c__int16__Sequence__are_equal(
      &(lhs->azimuth), &(rhs->azimuth)))
  {
    return false;
  }
  // snr
  if (!rosidl_runtime_c__int16__Sequence__are_equal(
      &(lhs->snr), &(rhs->snr)))
  {
    return false;
  }
  return true;
}

bool
gpsx__srv__GetSatList_Response__copy(
  const gpsx__srv__GetSatList_Response * input,
  gpsx__srv__GetSatList_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // gnsstype
  if (!rosidl_runtime_c__int16__Sequence__copy(
      &(input->gnsstype), &(output->gnsstype)))
  {
    return false;
  }
  // id
  if (!rosidl_runtime_c__int16__Sequence__copy(
      &(input->id), &(output->id)))
  {
    return false;
  }
  // elevation
  if (!rosidl_runtime_c__int16__Sequence__copy(
      &(input->elevation), &(output->elevation)))
  {
    return false;
  }
  // azimuth
  if (!rosidl_runtime_c__int16__Sequence__copy(
      &(input->azimuth), &(output->azimuth)))
  {
    return false;
  }
  // snr
  if (!rosidl_runtime_c__int16__Sequence__copy(
      &(input->snr), &(output->snr)))
  {
    return false;
  }
  return true;
}

gpsx__srv__GetSatList_Response *
gpsx__srv__GetSatList_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gpsx__srv__GetSatList_Response * msg = (gpsx__srv__GetSatList_Response *)allocator.allocate(sizeof(gpsx__srv__GetSatList_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gpsx__srv__GetSatList_Response));
  bool success = gpsx__srv__GetSatList_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gpsx__srv__GetSatList_Response__destroy(gpsx__srv__GetSatList_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gpsx__srv__GetSatList_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gpsx__srv__GetSatList_Response__Sequence__init(gpsx__srv__GetSatList_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gpsx__srv__GetSatList_Response * data = NULL;

  if (size) {
    data = (gpsx__srv__GetSatList_Response *)allocator.zero_allocate(size, sizeof(gpsx__srv__GetSatList_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gpsx__srv__GetSatList_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gpsx__srv__GetSatList_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
gpsx__srv__GetSatList_Response__Sequence__fini(gpsx__srv__GetSatList_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      gpsx__srv__GetSatList_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

gpsx__srv__GetSatList_Response__Sequence *
gpsx__srv__GetSatList_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gpsx__srv__GetSatList_Response__Sequence * array = (gpsx__srv__GetSatList_Response__Sequence *)allocator.allocate(sizeof(gpsx__srv__GetSatList_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gpsx__srv__GetSatList_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gpsx__srv__GetSatList_Response__Sequence__destroy(gpsx__srv__GetSatList_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gpsx__srv__GetSatList_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gpsx__srv__GetSatList_Response__Sequence__are_equal(const gpsx__srv__GetSatList_Response__Sequence * lhs, const gpsx__srv__GetSatList_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gpsx__srv__GetSatList_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gpsx__srv__GetSatList_Response__Sequence__copy(
  const gpsx__srv__GetSatList_Response__Sequence * input,
  gpsx__srv__GetSatList_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gpsx__srv__GetSatList_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gpsx__srv__GetSatList_Response * data =
      (gpsx__srv__GetSatList_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gpsx__srv__GetSatList_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gpsx__srv__GetSatList_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gpsx__srv__GetSatList_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
