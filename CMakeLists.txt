cmake_minimum_required(VERSION 3.15)
project(x500)

if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif ()

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_executable(
        x500_node
        src/x500_node.cpp
)

target_include_directories(x500_node PRIVATE include)

# Load & run linters listed in package.xml
if (BUILD_TESTING)
    find_package(ament_lint_auto REQUIRED)
    ament_lint_auto_find_test_dependencies()
endif ()

# Install scripts
install(
        PROGRAMS  # PROGRAMS sets execute bits, FILES clears them
        DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
        launch
        DESTINATION share/${PROJECT_NAME}
        )

ament_auto_package()