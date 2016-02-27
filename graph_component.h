//
// Created by Michael Holubec on 21.02.16.
//

#ifndef BACHELOR_GRAPHCOMPONENT_H
#define BACHELOR_GRAPHCOMPONENT_H


#include <vector>
#include "node.h"
#include "Edge.h"

class Subgraph;

// todo osetrit metody pro moznosti prijmuti null jako parametru
// todo subgraphs metody

class GraphComponent {
private:
	nodes_map nodes;
	std::vector< Edge* > edges;
	std::map< const char *, Subgraph* > subgraphs;
	Attributes node_attrs;
	Attributes edge_attrs;

	void insertEdge(Edge *edge);
	void setDefaultNodeAttrs(Node *node);
	void setDefaultEdgeAttrs(Edge *edge);

protected:
	GraphComponent *parent;

	Node *getNodeInGraph(const char *name);
	Node *getNodeInSubgraphs(const char *name);
	GraphComponent *getMainParent();

public:
	Attributes attrs;

	// todo vyzkouset v graphvizu, jestli muzou byt v sobe vnoreny subgraphs se stejnym cluster jmenem
	// todo vyzkouset - pridani duplicitniho node
	// todo vyzkouset - pridani duplicitni edge

	// ===== SUBGRAPHS METHODS ======
	Subgraph *addSubgraph(const char * name);
	void addSubgraph(Subgraph *graph);
	Subgraph *getSubgraph(const char *name);

	// ===== NODES METHODS =====
	// todo pridat node teprve az po vyhledani existence jineho node se stejnym jmenem v prostoru grafu?
	Node *addNode(const char *name);
	int addNode(Node *node);
	Node *getNode(const char *name);
	template <typename T>
	// todo udelat tempalte i node_name => zmenit nazev na Node a kod prizpusobit
	int setNodeAttr(const char *node_name, const char *attr_name, T value) {
		Node *Node = getNode(node_name);

		if(Node == NULL) {
			return -1;
		}

		Node->setAttr(attr_name, value);

		return 0;
	}

	// ===== EDGES METHODS =====
	int addEdge(Edge *edge);
	Edge *addEdge(const char *from, const char *to);
	Edge *addEdge(Node *from, Node * to);
	Edge *getEdge(Node *from, Node *to);
	Edge *getEdge(const char *from, const char *to);


	// ===== ATTRIBUTES METHODS =====
	void setDefaultNodeAttr(const char *name, Attribute *attr);
	template <typename T>
	void setDefaultNodeAttr(const char *name, T value) {
		node_attrs.setAttr(name, value);
	}
	void setDefaultEdgeAttr(const char *name, Attribute *attr);
	template <typename T>
	void setDefaultEdgeAttr(const char *name, T value) {
		edge_attrs.setAttr(name, value);
	}
	template <typename T, typename U>
	int setEdgeAttr(U *from_node, U *to_node, const char* attr_name, T value) {
		Edge *Edge = getEdge(from_node, to_node);

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
	void setAttr(const char *name, Attribute *attr) {
		attrs.setAttr(name, attr);
	}
	template <typename T>
	void setAttr(const char *name, T value) {
		attrs.setAttr(name, value);
	}

};

class Subgraph : public GraphComponent {
private:
	const char *name;

public:
	Subgraph(GraphComponent *parent) { this->parent = parent; };
	Subgraph(GraphComponent *parent, const char *name) { this->parent = parent; this->name = name; }

	const char *getName();
	void setName(const char *value);
};

typedef std::map< const char *, Subgraph* >::iterator subgraphs_it;
typedef std::pair< const char *, Subgraph* > subgraphs_pair;


#endif //BACHELOR_GRAPHCOMPONENT_H
