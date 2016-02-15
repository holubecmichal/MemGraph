cmake_minimum_required(VERSION 3.3)
project(Bachelor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp node.cpp node.h edge.cpp edge.h attribute.cpp attribute.h attributes.cpp attributes.h)
add_executable(Bachelor ${SOURCE_FILES})