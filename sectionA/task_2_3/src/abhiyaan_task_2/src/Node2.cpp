#include "ros/ros.h"
#include "std_msgs/String.h"


void team_abhiyaanCallback(const std_msgs::String::ConstPtr& msg) 
{
    ROS_INFO("%s", msg->data.c_str());
}

int main(int argc, char **argv) 
{
    ros::init(argc, argv, "Node2");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("team_abhiyaan", 1000, team_abhiyaanCallback);

    ros::spin();

    return 0;


}
