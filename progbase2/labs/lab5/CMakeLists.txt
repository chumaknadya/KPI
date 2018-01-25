
cmake_minimum_required(VERSION 2.8.9)

include_directories(include)
include_directories(/usr/include/libxml2)

file(GLOB LIB_SOURCES "src/*.c")

project (ModuleForLab5)

add_library(${CMAKE_PROJECT_NAME} STATIC ${LIB_SOURCES})

include_directories(include include/)

target_link_libraries(ModuleForLab5 libxml2.so)
target_link_libraries(ModuleForLab5 libjansson.so)
target_link_libraries(ModuleForLab5 libprogbase.so)

install(
	DIRECTORY includes/ DESTINATION /usr/local/include
	FILES_MATCHING PATTERN "*.h"
)
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION /usr/local/lib)

project(a.out)

add_executable(${CMAKE_PROJECT_NAME} "main.c" ${LIB_SOURCES})

include_directories(include include/)

target_link_libraries(a.out libxml2.so)
target_link_libraries(a.out libjansson.so)
target_link_libraries(a.out libprogbase.so)