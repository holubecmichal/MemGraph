//
// Created by Michael Holubec on 21.02.16.
//

#ifndef BACHELOR_GRAPHCOMPONENT_H
#define BACHELOR_GRAPHCOMPONENT_H


#include <vector>
#include "node.h"
#include "edge.h"

class subgraph;

class graphComponent {
private:
	std::map< const char *, node* > nodes;
	std::vector< edge* > edges;
	std::map<std::string, subgraph*> subgraphs;
	attributes node_attrs;
	attributes edge_attrs;


	void insertEdge(edge *Edge);
	void setDefaultNodeAttrs(node *Node);
	void setDefaultEdgeAttrs(edge *Edge);

public:
	attributes attrs;

	//subgraph *addSubgraph(const char * name);
	//void addSubgraph(subgraph *graph);

	node *addNode(const char *name);
	int addNode(node *Node);

	edge *addEdge();
	int addEdge(edge *Edge);
	edge *addEdge(const char *from, const char *to);

	//void setNodeAttrs(attributes *attrs);
	//void setEdgeAttrs(attributes *attrs);
	node *getNode(const char *name);
	edge *getEdge(node *from, node *to);
	edge *getEdge(const char *from, const char *to);
	//subgraph *getSubgraph(const char *name);

	void setDefaultNodeAttr(const char *name, attribute attr);
	template <typename T>
	void setDefaultNodeAttr(const char *name, T value) {
		node_attrs.setAttr(name, value);
	}

	void setDefaultEdgeAttr(const char *name, attribute attr);
	template <typename T>
	void setDefaultEdgeAttr(const char *name, T value) {
		edge_attrs.setAttr(name, value);
	}


};

class subgraph : public graphComponent {
private:
	const char *name;
	graphComponent *parent;
public:
	const char *getName();
	void setName(const char *value);
};


#endif //BACHELOR_GRAPHCOMPONENT_H
