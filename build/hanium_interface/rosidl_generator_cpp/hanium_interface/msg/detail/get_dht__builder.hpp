// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hanium_interface:msg/GetDht.idl
// generated code does not contain a copyright notice

#ifndef HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__BUILDER_HPP_
#define HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__BUILDER_HPP_

#include "hanium_interface/msg/detail/get_dht__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hanium_interface
{

namespace msg
{

namespace builder
{

class Init_GetDht_temp
{
public:
  explicit Init_GetDht_temp(::hanium_interface::msg::GetDht & msg)
  : msg_(msg)
  {}
  ::hanium_interface::msg::GetDht temp(::hanium_interface::msg::GetDht::_temp_type arg)
  {
    msg_.temp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hanium_interface::msg::GetDht msg_;
};

class Init_GetDht_hum
{
public:
  Init_GetDht_hum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetDht_temp hum(::hanium_interface::msg::GetDht::_hum_type arg)
  {
    msg_.hum = std::move(arg);
    return Init_GetDht_temp(msg_);
  }

private:
  ::hanium_interface::msg::GetDht msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hanium_interface::msg::GetDht>()
{
  return hanium_interface::msg::builder::Init_GetDht_hum();
}

}  // namespace hanium_interface

#endif  // HANIUM_INTERFACE__MSG__DETAIL__GET_DHT__BUILDER_HPP_
