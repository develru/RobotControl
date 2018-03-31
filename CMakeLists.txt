project(RobotControl)
cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

add_definitions(
    -c
    -Wall
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)

if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS "-std=c++0x")

# Lets LOAD app our headers!
file(GLOB_RECURSE HDRS ${PROJECT_SOURCE_DIR}/src/*.h)

# Lets LOAD app our sources!
file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Lets LOAD app our resources!
file(GLOB_RECURSE RSRCS ${PROJECT_SOURCE_DIR}/src/*.qrc)

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST} ${HDRS} ${SRCS} ${RSRCS})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Quick)
