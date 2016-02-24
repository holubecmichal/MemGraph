//
// Created by Michael Holubec on 21.02.16.
//

#ifndef BACHELOR_GRAPHCOMPONENT_H
#define BACHELOR_GRAPHCOMPONENT_H


#include <vector>
#include "node.h"
#include "edge.h"

class subgraph;

// todo osetrit metody pro moznosti prijmuti null jako parametru
// todo subgraphs metody

class graphComponent {
private:
	std::map< const char *, node* > nodes;
	std::vector< edge* > edges;
	std::map< const char *, subgraph* > subgraphs;
	attributes node_attrs;
	attributes edge_attrs;


	void insertEdge(edge *Edge);
	void setDefaultNodeAttrs(node *Node);
	void setDefaultEdgeAttrs(edge *Edge);

public:
	attributes attrs;

	subgraph *addSubgraph(const char * name);
	void addSubgraph(subgraph *graph);

	node *addNode(const char *name);
	int addNode(node *Node);

	edge *addEdge();
	int addEdge(edge *Edge);
	edge *addEdge(const char *from, const char *to);
	edge *addEdge(node *from, node* to);

	//void setNodeAttrs(attributes *attrs);
	//void setEdgeAttrs(attributes *attrs);
	node *getNode(const char *name);

	edge *getEdge(node *from, node *to);
	edge *getEdge(const char *from, const char *to);

	subgraph *getSubgraph(const char *name);

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

	template <typename T>
	// todo udelat tempalte i node_name => zmenit nazev na node a kod prizpusobit
	int setNodeAttr(const char *node_name, const char *attr_name, T value) {
		node *Node = getNode(node_name);

		if(Node == NULL) {
			return -1;
		}

		Node->setAttr(attr_name, value);

		return 0;
	}

	template <typename T, typename U>
	int setEdgeAttr(U *from_node, U *to_node, const char* attr_name, T value) {
		edge *Edge = getEdge(from_node, to_node);

		if(Edge == NULL) {
			return -1;
		}

		Edge->setAttr(attr_name, value);
		return 0;
	}

	void clearDefaultNodeAttrs();
	void clearDefaultEdgeAttrs();
	void eraseDeafultNodeAttr(const char *name);
	void eraseDefaultEdgeAttr(const char *name);

	void setAttr(const char *name, attribute attr) {
		attrs.setAttr(name, attr);
	}
	template <typename T>
	void setAttr(const char *name, T value) {
		attrs.setAttr(name, value);
	}

};

class subgraph : public graphComponent {
private:
	const char *name;
	graphComponent *parent;
public:
	subgraph(graphComponent *parent) { this->parent = parent; };
	subgraph(graphComponent *parent, const char *name) { this->parent = parent; this->name = name; }

	// todo prepsat metodu pro pridavani node, aby se nejdriv podiva rekurzivne pres parenty a sve subgraphy, jestli ten node nahodou uz neexistuje
	const char *getName();
	void setName(const char *value);
};


#endif //BACHELOR_GRAPHCOMPONENT_H
