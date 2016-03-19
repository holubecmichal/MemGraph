//
// Created by Michael Holubec on 22.02.16.
//

#ifndef BACHELOR_GRAPH_H
#define BACHELOR_GRAPH_H


#include "graph_component.h"

enum graph_type {
	std_graph,
	digraph
};

class Graph : public GraphComponent {
private:
	graph_type type;

public:
	Graph() { type = digraph; parent = NULL; }
	Graph(graph_type value) { type = value; parent = NULL; };

	void setType(graph_type value);
	graph_type getType();
};


#endif //BACHELOR_GRAPH_H
