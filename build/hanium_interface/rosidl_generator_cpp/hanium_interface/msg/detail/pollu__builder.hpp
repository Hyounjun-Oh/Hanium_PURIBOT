// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hanium_interface:msg/Pollu.idl
// generated code does not contain a copyright notice

#ifndef HANIUM_INTERFACE__MSG__DETAIL__POLLU__BUILDER_HPP_
#define HANIUM_INTERFACE__MSG__DETAIL__POLLU__BUILDER_HPP_

#include "hanium_interface/msg/detail/pollu__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hanium_interface
{

namespace msg
{

namespace builder
{

class Init_Pollu_pm2_5
{
public:
  explicit Init_Pollu_pm2_5(::hanium_interface::msg::Pollu & msg)
  : msg_(msg)
  {}
  ::hanium_interface::msg::Pollu pm2_5(::hanium_interface::msg::Pollu::_pm2_5_type arg)
  {
    msg_.pm2_5 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hanium_interface::msg::Pollu msg_;
};

class Init_Pollu_pm10
{
public:
  Init_Pollu_pm10()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pollu_pm2_5 pm10(::hanium_interface::msg::Pollu::_pm10_type arg)
  {
    msg_.pm10 = std::move(arg);
    return Init_Pollu_pm2_5(msg_);
  }

private:
  ::hanium_interface::msg::Pollu msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hanium_interface::msg::Pollu>()
{
  return hanium_interface::msg::builder::Init_Pollu_pm10();
}

}  // namespace hanium_interface

#endif  // HANIUM_INTERFACE__MSG__DETAIL__POLLU__BUILDER_HPP_
