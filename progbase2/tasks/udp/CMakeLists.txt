cmake_minimum_required(VERSION 2.8.9)

#
# Common settings
#

# adds ./include to compiler include directories
include_directories(include)
# compiles code files from ./src folder
file(GLOB LIB_SOURCES "src/*.c")

#
# first project (static lib)
#
project (server)
add_executable(${CMAKE_PROJECT_NAME} "server.c")
target_link_libraries(${CMAKE_PROJECT_NAME} progbase)

project (client)
add_executable(${CMAKE_PROJECT_NAME} "client.c")
target_link_libraries(${CMAKE_PROJECT_NAME} progbase)

