cmake_minimum_required(VERSION 2.8)
project(Memgraph)

add_definitions(-DHAVE_STRING_H)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_definitions(-DHAVE_STRING_H)
include_directories(/usr/include/graphviz)

add_library(memgraph STATIC
	node.cpp 
	node.h 
	edge.cpp 
	edge.h 
	attribute.cpp 
	attribute.h 
	attributes.cpp 
	attributes.h 
	graph_component.cpp 
	graph_component.h 
	graph.cpp 
	graph.h 
	plotter.cpp 
	plotter.h 
	graphviz_plotter.cpp 
	graphviz_plotter.h 
	utility.cpp 
	utility.h 
	graphviz_attrs.cpp 
	graphviz_attrs.h 
	predator_wrapper.cpp 
	predator_wrapper.h
)

target_link_libraries(memgraph gvc cgraph cdt)
