#! /usr/bin/env python
import rospy
from std_msgs.msg import Float32


class CreateSub():

    @classmethod
    def sub(cls):
        cls.msg = rospy.wait_for_message("/pub_topic", Float32)
        cls().pub()

    def pub(self):
        pub_msg = rospy.Publisher(
            "/response_topic", Float32, queue_size=10)

        rate = rospy.Rate(1)
        while not rospy.is_shutdown():
            pub_msg.publish(self.msg.data**2)
            rate.sleep()


if __name__ == "__main__":

    # Connect to ros master and initilaize node
    rospy.init_node('subscriber')
    CreateSub.sub()
