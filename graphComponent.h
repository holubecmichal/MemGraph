//
// Created by Michael Holubec on 21.02.16.
//

#ifndef BACHELOR_GRAPHCOMPONENT_H
#define BACHELOR_GRAPHCOMPONENT_H


#include <vector>
#include "node.h"
#include "edge.h"

class graphComponent {
private:
	std::map<const char *, node*> nodes;
	std::vector<edge*> edges;
	//std::map<std::string, subgraph> subgraphs;
	attributes node_attrs;
	attributes edge_attrs;

	void insertEdge(edge *Edge);

public:
	attributes attrs;

	//subgraph *addSubgraph(const char * name);
	//void addSubgraph(subgraph *graph);
	node *addNode(const char *name);
	int addNode(node *Node);
	edge *addEdge();
	int addEdge(edge *Edge);
	void setNodeAttrs(attributes *attrs);
	void setEdgeAttrs(attributes *attrs);
	node *getNode(const char *name);
	edge *getEdge(node *from, node *to);
	edge *getEdge(const char *from, const char *to);
	//subgraph *getSubgraph(const char *name);
	void setNodeAttr(const char *name, attribute attr);
	template <typename T>
	void setNodeAttr(const char *name, T value) {
		node_attrs.setAttr(name, value);
	}
	void setEdgeAttr(const char *name, attribute attr);
	template <typename T>
	void setEdgeAttr(const char *name, T value) {
		edge_attrs.setAttr(name, value);
	}


};


#endif //BACHELOR_GRAPHCOMPONENT_H
