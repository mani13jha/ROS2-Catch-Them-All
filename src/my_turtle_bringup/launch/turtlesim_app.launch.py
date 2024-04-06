from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    turtlesim_node = Node(package="turtlesim", executable="turtlesim_node")
    spawn_turtle_node = Node(package="my_turtle_pkg", executable="turtle_spawn_node")
    catch_turtle_node = Node(package="my_turtle_pkg", executable="turtle_catch_node")
    ld.add_action(turtlesim_node)
    ld.add_action(spawn_turtle_node)
    ld.add_action(catch_turtle_node)
    return ld
    