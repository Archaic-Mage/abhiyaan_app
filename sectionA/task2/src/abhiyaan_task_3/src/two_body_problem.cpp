#include "ros/ros.h"
#include "turtlesim/Kill.h"
#include "turtlesim/Spawn.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"

#include <sstream>
#include <bits/stdc++.h>
#include <cmath>


ros::Publisher mov_pub_A;
ros::Subscriber get_position_A;
ros::Publisher mov_pub_B;
ros::Subscriber get_position_B;

double r = 2.0;
double G = 256.0;
double m = 1.0;
double omega = 1.0;
turtlesim::Pose pos_A;
turtlesim::Pose pos_B;



void get_pos_B(const turtlesim::Pose::ConstPtr& msg)
{
    pos_B = *msg;
}

double curr_dist() 
{
    double diff_x = pos_A.x - pos_B.x;
    double diff_y = pos_A.y - pos_B.y;
    double sqr_diff = diff_x*diff_x + diff_y*diff_y;

    return sqrt(sqr_diff);
}

double find_omega(double s)
{
    double part1 = m*omega*omega*r*r;
    part1/=(s*s);

    double part2 = (G*m)/(4*r*s*s);

    double part3 = (G*m)/(4*s*s*s);

    return sqrt(part1+part2-part3);
}

geometry_msgs::Twist get_velocities()
{
    double s = curr_dist()/2;
    double curr_omega = find_omega(s);

    double angle = pos_A.theta;

    geometry_msgs::Twist ret;

    double x, y, z;

    double v = curr_omega*s;

    x = v*cos(angle);
    y = v*sin(angle);
    z = 0;

    ret.linear.x = x;
    ret.linear.y = y;
    ret.linear.z = z;

    x = 0, y = 0, z = curr_omega;

    ret.angular.x = x;
    ret.angular.y = y;
    ret.angular.z = z;

    return ret;
}

void get_pos_A(const turtlesim::Pose::ConstPtr& msg)
{
    pos_A = *msg;
    geometry_msgs::Twist p = get_velocities();

    mov_pub_A.publish(p);
    ros::spinOnce();

    p.linear.x = -p.linear.x;
    p.linear.y = -p.linear.y;
    mov_pub_B.publish(p);
    ros::spinOnce();
}

void initial_movment()
{
    geometry_msgs::Twist p;
    p.linear.x = omega*r;
    p.linear.y = 0;
    p.linear.z = 0;
    p.angular.x = 0;
    p.angular.y = 0;
    p.angular.z = omega;
    mov_pub_A.publish(p);
    p.linear.x = -omega*r;
    mov_pub_B.publish(p);
    ros::spinOnce();
}

int main(int argc, char **argv) 
{

    ros::init(argc, argv, "two_body_problem");

    ros::NodeHandle n;

    ros::ServiceClient kill_client = n.serviceClient<turtlesim::Kill>("/kill");
    ros::ServiceClient spawn_client = n.serviceClient<turtlesim::Spawn>("/spawn"); 


    turtlesim::Kill kill_srv;
    kill_srv.request.name = "turtle1";

    ros::Rate rate(1);
    rate.sleep();

    turtlesim::Spawn spawn_srv;

    double x, y, theta;

    x = 5, y = 2.0, theta = 0;

    spawn_srv.request.x = x;
    spawn_srv.request.y = y;
    spawn_srv.request.theta = theta;
    spawn_srv.request.name = "turtleA";

    if(!spawn_client.call(spawn_srv)) 
    {
        ROS_ERROR("Failed to spawn the turtle");
        return 1;
    }

    x = 5, y = 6, theta = 0;

    spawn_srv.request.x = x;
    spawn_srv.request.y = y;
    spawn_srv.request.theta = theta;
    spawn_srv.request.name = "turtleB";

    if(!spawn_client.call(spawn_srv)) 
    {
        ROS_ERROR("Failed to spawn the turtle");
        return 1;
    }

    if(!kill_client.call(kill_srv)) {
        ROS_ERROR("Failed to kill the turtle");
        return 1;
    }

    mov_pub_A = n.advertise<geometry_msgs::Twist>("/turtleA/cmd_vel", 1000);
    mov_pub_B = n.advertise<geometry_msgs::Twist>("/turtleB/cmd_vel", 1000);
    //initial_movment();
    get_position_B = n.subscribe("/turtleB/pose", 1000, get_pos_B);
    get_position_A = n.subscribe("/turtleA/pose", 1000, get_pos_A);
    
    ros::spin();


    return 0;
}
