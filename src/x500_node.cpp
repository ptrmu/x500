

#include "mavros_msgs/msg/state.hpp"
#include "rclcpp/rclcpp.hpp"

//=============================================================================
// Main
//=============================================================================

namespace x500 {

class X500Node : public rclcpp::Node {
  rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_x500_;

 public:
  explicit X500Node() :
      Node("X500_node") {

    rclcpp::QoS best_effort(10);
    best_effort.best_effort();

    rclcpp::QoS reliable(10);
    reliable.reliable();

    state_x500_ = create_subscription<mavros_msgs::msg::State>(
        "/mavros/state", reliable,
        [this](mavros_msgs::msg::State::UniquePtr msg) -> void // NOLINT
        {
          RCLCPP_INFO(get_logger(), "Connected: %d", msg->connected);
        });

    RCLCPP_INFO(get_logger(), "x500_node ready");
  }
};
}

int main(int argc, char **argv) {
  setvbuf(stdout, nullptr, _IONBF, BUFSIZ);
  rclcpp::init(argc, argv);
  auto node = std::make_shared<x500::X500Node>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}