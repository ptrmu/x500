

#include "rclcpp/rclcpp.hpp"

//=============================================================================
// Main
//=============================================================================

int main(int argc, char ** argv)
{
    setvbuf(stdout, nullptr, _IONBF, BUFSIZ);
    rclcpp::init(argc, argv);
    rclcpp::shutdown();
    return 0;
}