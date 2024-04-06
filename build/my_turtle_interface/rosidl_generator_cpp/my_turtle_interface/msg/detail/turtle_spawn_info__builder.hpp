// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_turtle_interface:msg/TurtleSpawnInfo.idl
// generated code does not contain a copyright notice

#ifndef MY_TURTLE_INTERFACE__MSG__DETAIL__TURTLE_SPAWN_INFO__BUILDER_HPP_
#define MY_TURTLE_INTERFACE__MSG__DETAIL__TURTLE_SPAWN_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_turtle_interface/msg/detail/turtle_spawn_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_turtle_interface
{

namespace msg
{

namespace builder
{

class Init_TurtleSpawnInfo_name
{
public:
  explicit Init_TurtleSpawnInfo_name(::my_turtle_interface::msg::TurtleSpawnInfo & msg)
  : msg_(msg)
  {}
  ::my_turtle_interface::msg::TurtleSpawnInfo name(::my_turtle_interface::msg::TurtleSpawnInfo::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_turtle_interface::msg::TurtleSpawnInfo msg_;
};

class Init_TurtleSpawnInfo_theta
{
public:
  explicit Init_TurtleSpawnInfo_theta(::my_turtle_interface::msg::TurtleSpawnInfo & msg)
  : msg_(msg)
  {}
  Init_TurtleSpawnInfo_name theta(::my_turtle_interface::msg::TurtleSpawnInfo::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_TurtleSpawnInfo_name(msg_);
  }

private:
  ::my_turtle_interface::msg::TurtleSpawnInfo msg_;
};

class Init_TurtleSpawnInfo_y
{
public:
  explicit Init_TurtleSpawnInfo_y(::my_turtle_interface::msg::TurtleSpawnInfo & msg)
  : msg_(msg)
  {}
  Init_TurtleSpawnInfo_theta y(::my_turtle_interface::msg::TurtleSpawnInfo::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_TurtleSpawnInfo_theta(msg_);
  }

private:
  ::my_turtle_interface::msg::TurtleSpawnInfo msg_;
};

class Init_TurtleSpawnInfo_x
{
public:
  Init_TurtleSpawnInfo_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TurtleSpawnInfo_y x(::my_turtle_interface::msg::TurtleSpawnInfo::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TurtleSpawnInfo_y(msg_);
  }

private:
  ::my_turtle_interface::msg::TurtleSpawnInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_turtle_interface::msg::TurtleSpawnInfo>()
{
  return my_turtle_interface::msg::builder::Init_TurtleSpawnInfo_x();
}

}  // namespace my_turtle_interface

#endif  // MY_TURTLE_INTERFACE__MSG__DETAIL__TURTLE_SPAWN_INFO__BUILDER_HPP_
