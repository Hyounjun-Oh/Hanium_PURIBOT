// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hanium_interface:msg/Pollu.idl
// generated code does not contain a copyright notice

#ifndef HANIUM_INTERFACE__MSG__DETAIL__POLLU__STRUCT_HPP_
#define HANIUM_INTERFACE__MSG__DETAIL__POLLU__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__hanium_interface__msg__Pollu __attribute__((deprecated))
#else
# define DEPRECATED__hanium_interface__msg__Pollu __declspec(deprecated)
#endif

namespace hanium_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Pollu_
{
  using Type = Pollu_<ContainerAllocator>;

  explicit Pollu_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pm10 = 0;
      this->pm2_5 = 0;
    }
  }

  explicit Pollu_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pm10 = 0;
      this->pm2_5 = 0;
    }
  }

  // field types and members
  using _pm10_type =
    int16_t;
  _pm10_type pm10;
  using _pm2_5_type =
    int16_t;
  _pm2_5_type pm2_5;

  // setters for named parameter idiom
  Type & set__pm10(
    const int16_t & _arg)
  {
    this->pm10 = _arg;
    return *this;
  }
  Type & set__pm2_5(
    const int16_t & _arg)
  {
    this->pm2_5 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hanium_interface::msg::Pollu_<ContainerAllocator> *;
  using ConstRawPtr =
    const hanium_interface::msg::Pollu_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hanium_interface::msg::Pollu_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hanium_interface::msg::Pollu_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hanium_interface::msg::Pollu_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hanium_interface::msg::Pollu_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hanium_interface::msg::Pollu_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hanium_interface::msg::Pollu_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hanium_interface::msg::Pollu_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hanium_interface::msg::Pollu_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hanium_interface__msg__Pollu
    std::shared_ptr<hanium_interface::msg::Pollu_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hanium_interface__msg__Pollu
    std::shared_ptr<hanium_interface::msg::Pollu_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Pollu_ & other) const
  {
    if (this->pm10 != other.pm10) {
      return false;
    }
    if (this->pm2_5 != other.pm2_5) {
      return false;
    }
    return true;
  }
  bool operator!=(const Pollu_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Pollu_

// alias to use template instance with default allocator
using Pollu =
  hanium_interface::msg::Pollu_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace hanium_interface

#endif  // HANIUM_INTERFACE__MSG__DETAIL__POLLU__STRUCT_HPP_
