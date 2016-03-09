cmake_minimum_required(VERSION 3.3)
project(Bachelor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lgvc -lcgraph -lcdt")

set(SOURCE_FILES main.cpp node.cpp node.h edge.cpp edge.h attribute.cpp attribute.h attributes.cpp attributes.h graph_component.cpp graph_component.h graph.cpp graph.h plotter.cpp plotter.h graphviz_plotter.cpp graphviz_plotter.h utility.cpp utility.h Value.cpp Value.h)
add_executable(Bachelor ${SOURCE_FILES})