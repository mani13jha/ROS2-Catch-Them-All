#!/usr/bin/env python3
import random
import time

import rclpy
from rclpy.node import Node

from turtlesim.srv import Spawn
from my_turtle_interface.msg import TurtleSpawnInfo

class TurtleSpawnNode(Node):
    def __init__(self):
        super().__init__("turtles_spawn_node")
        self.counter_ = 2
        self.get_logger().info("Turtle Spawning Node Started")
        self.client_ = self.create_client(Spawn, "/spawn")
        self.publisher_ = self.create_publisher(TurtleSpawnInfo, "/turtle_spawn_info", 10)

    def call_spawn_turtle_service(self):
        x,y,theta,name = random.uniform(1,10), random.uniform(1,10), random.uniform(-3,3), f"turtle{self.counter_}"
        
        request = Spawn.Request()
        request.x = x
        request.y = y
        request.theta = theta
        request.name = name
        self.counter_ += 1

        self.future = self.client_.call_async(request)
        
        while rclpy.ok():
            rclpy.spin_once(self)
            if self.future.done():
                try:
                    res = self.future.result()
                except Exception as e:
                    self.get_logger().error('Service call failed %r' % (e,))
                else:
                    self.get_logger().info(f'Result of Spawn Turtle: {res.name}')
                    msg = TurtleSpawnInfo()
                    msg.x = x
                    msg.y = y
                    msg.theta = theta
                    msg.name = name
                    self.publisher_.publish(msg)
                break





def main(args=None):
    rclpy.init(args=args)
    node = TurtleSpawnNode()

    while not node.client_.wait_for_service(1.0):
            node.get_logger().warn("Waiting for Server Spawn Turtles")
            
    while True:
        time.sleep(3)
        node.call_spawn_turtle_service()

    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()