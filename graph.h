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

	Graph *setAttr(const char *name, Attribute *attr) {
		attrs.setAttr(name, attr);
		return this;
	}
	template <typename T>
	Graph *setAttr(const char *name, T value) {
		attrs.setAttr(name, value);
		return this;
	}
	template <typename T>
	Graph *setHtmlAttr(const char *name, T value) {
		attrs.setHtmlAttr(name, value);
		return this;
	}

	void setType(graph_type value);
	graph_type getType();
};


#endif //BACHELOR_GRAPH_H
