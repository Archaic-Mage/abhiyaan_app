#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <string.h>

class ReverseMsg {
    public : 
        
        ros::NodeHandle n;
        ros::Publisher pub;

        ReverseMsg() {
            pub = n.advertise<std_msgs::String>("maet_naayihba", 1000);
        }

        void nodeCallback(const std_msgs::String::ConstPtr& msg)
        {
            std::string str = msg->data.c_str();
            std::stringstream s(str);

            std::string word;
            std::stringstream reverse;

            while(s >> word) 
            {
                for(int i = 0; i<=(word.length())/2; i++) std::swap(word[i], word[word.length()-1-i]);
                reverse << word << " ";
            }

            std_msgs::String reverse_msg;

            reverse_msg.data = reverse.str();

            pub.publish(reverse_msg);
        }
};

int main(int argc, char **argv) 
{
    ros::init(argc, argv, "reverseNode");

    ReverseMsg Node = ReverseMsg();

    ros::Subscriber sub = Node.n.subscribe("team_abhiyaan", 1000, &ReverseMsg::nodeCallback, &Node);

    ros::spin();

    return 0;

}
