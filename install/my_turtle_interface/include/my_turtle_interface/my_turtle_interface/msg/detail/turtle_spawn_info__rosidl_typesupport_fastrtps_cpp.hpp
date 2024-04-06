// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from my_turtle_interface:msg/TurtleSpawnInfo.idl
// generated code does not contain a copyright notice

#ifndef MY_TURTLE_INTERFACE__MSG__DETAIL__TURTLE_SPAWN_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define MY_TURTLE_INTERFACE__MSG__DETAIL__TURTLE_SPAWN_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "my_turtle_interface/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "my_turtle_interface/msg/detail/turtle_spawn_info__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace my_turtle_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_turtle_interface
cdr_serialize(
  const my_turtle_interface::msg::TurtleSpawnInfo & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_turtle_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  my_turtle_interface::msg::TurtleSpawnInfo & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_turtle_interface
get_serialized_size(
  const my_turtle_interface::msg::TurtleSpawnInfo & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_turtle_interface
max_serialized_size_TurtleSpawnInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace my_turtle_interface

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_turtle_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, my_turtle_interface, msg, TurtleSpawnInfo)();

#ifdef __cplusplus
}
#endif

#endif  // MY_TURTLE_INTERFACE__MSG__DETAIL__TURTLE_SPAWN_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_