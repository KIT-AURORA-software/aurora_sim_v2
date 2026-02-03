// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gpsx:srv/GetSatList.idl
// generated code does not contain a copyright notice

#ifndef GPSX__SRV__DETAIL__GET_SAT_LIST__STRUCT_HPP_
#define GPSX__SRV__DETAIL__GET_SAT_LIST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__gpsx__srv__GetSatList_Request __attribute__((deprecated))
#else
# define DEPRECATED__gpsx__srv__GetSatList_Request __declspec(deprecated)
#endif

namespace gpsx
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetSatList_Request_
{
  using Type = GetSatList_Request_<ContainerAllocator>;

  explicit GetSatList_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
    }
  }

  explicit GetSatList_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
    }
  }

  // field types and members
  using _type_type =
    int8_t;
  _type_type type;

  // setters for named parameter idiom
  Type & set__type(
    const int8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gpsx::srv::GetSatList_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const gpsx::srv::GetSatList_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gpsx::srv::GetSatList_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gpsx::srv::GetSatList_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gpsx::srv::GetSatList_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gpsx::srv::GetSatList_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gpsx::srv::GetSatList_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gpsx::srv::GetSatList_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gpsx::srv::GetSatList_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gpsx::srv::GetSatList_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gpsx__srv__GetSatList_Request
    std::shared_ptr<gpsx::srv::GetSatList_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gpsx__srv__GetSatList_Request
    std::shared_ptr<gpsx::srv::GetSatList_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetSatList_Request_ & other) const
  {
    if (this->type != other.type) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetSatList_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetSatList_Request_

// alias to use template instance with default allocator
using GetSatList_Request =
  gpsx::srv::GetSatList_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace gpsx


#ifndef _WIN32
# define DEPRECATED__gpsx__srv__GetSatList_Response __attribute__((deprecated))
#else
# define DEPRECATED__gpsx__srv__GetSatList_Response __declspec(deprecated)
#endif

namespace gpsx
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetSatList_Response_
{
  using Type = GetSatList_Response_<ContainerAllocator>;

  explicit GetSatList_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit GetSatList_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _gnsstype_type =
    std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>>;
  _gnsstype_type gnsstype;
  using _id_type =
    std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>>;
  _id_type id;
  using _elevation_type =
    std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>>;
  _elevation_type elevation;
  using _azimuth_type =
    std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>>;
  _azimuth_type azimuth;
  using _snr_type =
    std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>>;
  _snr_type snr;

  // setters for named parameter idiom
  Type & set__gnsstype(
    const std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>> & _arg)
  {
    this->gnsstype = _arg;
    return *this;
  }
  Type & set__id(
    const std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__elevation(
    const std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>> & _arg)
  {
    this->elevation = _arg;
    return *this;
  }
  Type & set__azimuth(
    const std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>> & _arg)
  {
    this->azimuth = _arg;
    return *this;
  }
  Type & set__snr(
    const std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>> & _arg)
  {
    this->snr = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gpsx::srv::GetSatList_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const gpsx::srv::GetSatList_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gpsx::srv::GetSatList_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gpsx::srv::GetSatList_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gpsx::srv::GetSatList_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gpsx::srv::GetSatList_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gpsx::srv::GetSatList_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gpsx::srv::GetSatList_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gpsx::srv::GetSatList_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gpsx::srv::GetSatList_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gpsx__srv__GetSatList_Response
    std::shared_ptr<gpsx::srv::GetSatList_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gpsx__srv__GetSatList_Response
    std::shared_ptr<gpsx::srv::GetSatList_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetSatList_Response_ & other) const
  {
    if (this->gnsstype != other.gnsstype) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->elevation != other.elevation) {
      return false;
    }
    if (this->azimuth != other.azimuth) {
      return false;
    }
    if (this->snr != other.snr) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetSatList_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetSatList_Response_

// alias to use template instance with default allocator
using GetSatList_Response =
  gpsx::srv::GetSatList_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace gpsx

namespace gpsx
{

namespace srv
{

struct GetSatList
{
  using Request = gpsx::srv::GetSatList_Request;
  using Response = gpsx::srv::GetSatList_Response;
};

}  // namespace srv

}  // namespace gpsx

#endif  // GPSX__SRV__DETAIL__GET_SAT_LIST__STRUCT_HPP_
