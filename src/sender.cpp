#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include <stdlib.h>

float i;
void response(const std_msgs::Float32 msg)
{
    ROS_INFO("Response received.");
    ROS_INFO("The square of %f is: %f", i, msg.data);
    ROS_INFO("Wait 10 seconds and shut down ROS...");
    ros::Rate r(0.1);
    r.sleep();
    ros::shutdown();
}

int main(int argc, char *argv[])
{
    i = std::atof(argv[1]);
    ros::init(argc, argv, "Sender");
    ros::NodeHandle node;
    ros::Publisher pub = node.advertise<std_msgs::Float32>("/pub_topic", 10);
    ros::Subscriber sub = node.subscribe("/response_topic", 10, response);

    std_msgs::Float32 num;
    num.data = std::atof(argv[1]);
    ros::Rate loop_rate(10);
    while (ros::ok())
    {
        pub.publish(num);
        ros::spinOnce();
        loop_rate.sleep();
    }
}