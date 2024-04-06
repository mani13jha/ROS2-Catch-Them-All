// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_turtle_interface:msg/TurtleSpawnInfo.idl
// generated code does not contain a copyright notice

#ifndef MY_TURTLE_INTERFACE__MSG__DETAIL__TURTLE_SPAWN_INFO__STRUCT_H_
#define MY_TURTLE_INTERFACE__MSG__DETAIL__TURTLE_SPAWN_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TurtleSpawnInfo in the package my_turtle_interface.
typedef struct my_turtle_interface__msg__TurtleSpawnInfo
{
  float x;
  float y;
  float theta;
  rosidl_runtime_c__String name;
} my_turtle_interface__msg__TurtleSpawnInfo;

// Struct for a sequence of my_turtle_interface__msg__TurtleSpawnInfo.
typedef struct my_turtle_interface__msg__TurtleSpawnInfo__Sequence
{
  my_turtle_interface__msg__TurtleSpawnInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_turtle_interface__msg__TurtleSpawnInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_TURTLE_INTERFACE__MSG__DETAIL__TURTLE_SPAWN_INFO__STRUCT_H_