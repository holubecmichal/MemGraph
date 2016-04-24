cmake_minimum_required(VERSION 2.8)
project(Bachelor)

add_definitions(-DHAVE_STRING_H)

#only for linux
#include_directories(/usr/include/graphviz)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp node.cpp node.h edge.cpp edge.h attribute.cpp attribute.h attributes.cpp attributes.h graph_component.cpp graph_component.h graph.cpp graph.h plotter.cpp plotter.h graphviz_plotter.cpp graphviz_plotter.h utility.cpp utility.h examples.cpp examples.h graphviz_attrs.cpp graphviz_attrs.h predator.cpp predator.h)

add_executable(Bachelor ${SOURCE_FILES})
target_link_libraries(Bachelor gvc cgraph cdt)