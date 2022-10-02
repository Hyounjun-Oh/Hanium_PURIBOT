// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hanium_interface:msg/GetDht.idl
// generated code does not contain a copyright notice

#ifndef HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__STRUCT_HPP_
#define HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__hanium_interface__msg__GetDht __attribute__((deprecated))
#else
# define DEPRECATED__hanium_interface__msg__GetDht __declspec(deprecated)
#endif

namespace hanium_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GetDht_
{
  using Type = GetDht_<ContainerAllocator>;

  explicit GetDht_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->hum = 0.0f;
      this->temp = 0.0f;
    }
  }

  explicit GetDht_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->hum = 0.0f;
      this->temp = 0.0f;
    }
  }

  // field types and members
  using _hum_type =
    float;
  _hum_type hum;
  using _temp_type =
    float;
  _temp_type temp;

  // setters for named parameter idiom
  Type & set__hum(
    const float & _arg)
  {
    this->hum = _arg;
    return *this;
  }
  Type & set__temp(
    const float & _arg)
  {
    this->temp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hanium_interface::msg::GetDht_<ContainerAllocator> *;
  using ConstRawPtr =
    const hanium_interface::msg::GetDht_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hanium_interface::msg::GetDht_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hanium_interface::msg::GetDht_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hanium_interface::msg::GetDht_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hanium_interface::msg::GetDht_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hanium_interface::msg::GetDht_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hanium_interface::msg::GetDht_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hanium_interface::msg::GetDht_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hanium_interface::msg::GetDht_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hanium_interface__msg__GetDht
    std::shared_ptr<hanium_interface::msg::GetDht_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hanium_interface__msg__GetDht
    std::shared_ptr<hanium_interface::msg::GetDht_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetDht_ & other) const
  {
    if (this->hum != other.hum) {
      return false;
    }
    if (this->temp != other.temp) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetDht_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetDht_

// alias to use template instance with default allocator
using GetDht =
  hanium_interface::msg::GetDht_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hanium_interface

#endif  // HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__STRUCT_HPP_
