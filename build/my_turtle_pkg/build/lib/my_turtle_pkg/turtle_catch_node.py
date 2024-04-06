import time
import math
import rclpy
from rclpy.node import Node

from std_srvs.srv import Empty
from turtlesim.msg import Pose
from turtlesim.srv import Kill
from geometry_msgs.msg import Twist
from my_turtle_interface.msg import TurtleSpawnInfo

class TurtleCatchNode(Node):
    def __init__(self):
        super().__init__("turtle_catch_node")
        self.spawn_turtles = {}
        self.pose_ = None
        self.client_ = self.create_client(Kill, "/kill")
        self.client2_ = self.create_client(Empty, "/clear")
        self.publisher_ = self.create_publisher(Twist, "/turtle1/cmd_vel", 10)
        self.subscribe_ = self.create_subscription(Pose, "/turtle1/pose", self.callback_for_turtle1_pose, 10)
        self.subscribe2_ = self.create_subscription(TurtleSpawnInfo, "/turtle_spawn_info", self.callback_for_spawn_turtles, 10)
        self.get_logger().info("Turtle Catch Node Started")

    def call_clear_path(self):
        req = Empty.Request()
        self.future = self.client2_.call_async(req)
        
        while rclpy.ok():
            rclpy.spin_once(self)
            if self.future.done():
                try:
                    res = self.future.result()
                except Exception as e:
                    self.get_logger().error('Service call failed %r' % (e,))
                else:
                    self.get_logger().info(f'Result of Spawn Turtle: {str(res)}')
                break

    def call_kill_turtles(self, name):
        req = Kill.Request()
        req.name = name

        self.future = self.client_.call_async(req)
        
        while rclpy.ok():
            rclpy.spin_once(self)
            if self.future.done():
                try:
                    res = self.future.result()
                except Exception as e:
                    self.get_logger().error('Service call failed %r' % (e,))
                else:
                    self.get_logger().info(f'Result of Spawn Turtle: {str(res)}')
                break


    def callback_for_turtle1_pose(self, data):
        self.pose_ = data

    def callback_for_spawn_turtles(self, data):
        msg = data
        if msg.name in self.spawn_turtles:
            pass
        else:
            self.spawn_turtles[msg.name] = {"x": msg.x, "y": msg.y}
            self.get_logger().info(f"Spawn Turtles List: {str(self.spawn_turtles)}")

    def publish_turtle1_parameters(self, target_x, target_y):
        if self.pose_ == None:
            return
        
        dist_x = target_x - self.pose_.x
        dist_y = target_y - self.pose_.y
        distance = math.sqrt(dist_x**2 + dist_y**2)

        msg = Twist()

        if distance > 0.2:
            msg.linear.x = 2.0*distance

            goal_theta = math.atan2(dist_y, dist_x)
            diff = goal_theta - self.pose_.theta

            if diff > math.pi:
                diff -= 2*math.pi
            elif diff < -math.pi:
                diff += 2*math.pi

            msg.angular.z = 6.0*diff
            self.publisher_.publish(msg)
            return 1
        else:
            msg.linear.x = 0.0
            msg.angular.z = 0.0
            self.publisher_.publish(msg)
            return 0
        


def main(args=None):
    rclpy.init(args=args)
    node = TurtleCatchNode()

    while True:
        turtles = list(node.spawn_turtles.keys())
        if(len(turtles) > 0):
            ret = node.publish_turtle1_parameters(node.spawn_turtles[turtles[0]]["x"], node.spawn_turtles[turtles[0]]["y"])
            if(ret == 0):
                node.call_kill_turtles(turtles[0])
                del node.spawn_turtles[turtles[0]]
                del turtles[0]
                node.call_clear_path()
        rclpy.spin_once(node, timeout_sec=0.1)

    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()