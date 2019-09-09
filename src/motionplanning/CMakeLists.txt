cmake_minimum_required(VERSION 2.8.3)
project(motionplanning)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

find_package(SQLite3)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES motionplanning
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
  include/motionplanning
  src/mainwindow.h
  src/mainwindow.ui
  src/Algorithms
  src/Helper
  ${catkin_INCLUDE_DIRS}
  ${SQLite3_INCLUDE_DIRS}
)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME}_node
    ${SOURCES}
    )

target_link_libraries(${PROJECT_NAME}_node
   ${catkin_LIBRARIES}
   ${PCL_LIBRARIES}
   Qt5::Widgets
   ${OUT_TARGET}
   ${SQLite3_LIBRARIES}
)
