#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class ChatApp : public rclcpp::Node
{
  public:
    ChatApp()
    : Node("chat_node")
    {
      this->declare_parameter("send_topic", "chat1");
      this->declare_parameter("recv_topic", "chat2");
      
      std::string send_topic_param =
      this->get_parameter("send_topic").get_parameter_value().get<std::string>();
      
      std::string recv_topic_param =
      this->get_parameter("recv_topic").get_parameter_value().get<std::string>();
        
      publisher_ = this->create_publisher<std_msgs::msg::String>(send_topic_param, 10);
      subscription_ = this->create_subscription<std_msgs::msg::String>(
      recv_topic_param, 10, std::bind(&ChatApp::topic_callback, this, _1));
      _spin_thread = std::thread(
   	 [this]()
   	 {
		   while(rclcpp::ok())
		   {
		      auto send_msg = std_msgs::msg::String();
		      std::string input_msg;
		      RCLCPP_INFO(this->get_logger(), "Please enter a message");
		      getline(std::cin,input_msg);     
		      send_msg.data = input_msg;
		      RCLCPP_INFO(this->get_logger(), "Sending msg: '%s'", send_msg.data.c_str());
		      publisher_->publish(send_msg);
		     
		   
		  }
  });
  }
     
  void topic_callback(std_msgs::msg::String msg) 
    {
     	recv_msg = msg.data;
	RCLCPP_INFO(this->get_logger(), "Received msg: '%s'", recv_msg.c_str());
	RCLCPP_INFO(this->get_logger(), "Please enter a message");

    }
       
     
  private:
    std::string recv_msg;   
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    std::thread _spin_thread;
 

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ChatApp>());
  rclcpp::shutdown();
  return 0;
}
