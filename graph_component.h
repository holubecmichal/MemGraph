//
// Created by Michael Holubec on 21.02.16.
//

#ifndef BACHELOR_GRAPHCOMPONENT_H
#define BACHELOR_GRAPHCOMPONENT_H


#include <vector>
#include "node.h"
#include "Edge.h"

class Subgraph;

typedef std::map< const char *, Subgraph* > subgraphs_map;
typedef subgraphs_map::iterator subgraphs_it;
typedef std::pair< const char *, Subgraph* > subgraphs_pair;

// todo osetrit metody pro moznosti prijmuti null jako parametru

class GraphComponent {
private:
	nodes_map nodes;
	edges_vect edges;
	subgraphs_map subgraphs;
	Attributes node_attrs;
	Attributes edge_attrs;

	void insertEdge(Edge *edge);
	//todo predelat pro vlozeni vlastni instance atributu
	void setDefaultNodeAttrs(Node *node);
	//todo predelat pro vlozeni vlastni instance atributu
	void setDefaultEdgeAttrs(Edge *edge);

protected:
	GraphComponent *parent;

	Node *getNodeInSubgraphs(const char *name);
	Node *getLocalNode(const char *name);
	GraphComponent *getMainParent();

public:
	Attributes attrs;

	virtual ~GraphComponent() { }

	// ===== GRAPH_COMPONENT METHODS =====
	void setGraphAttrs(Attributes *attrs);

	// ===== SUBGRAPHS METHODS ======
	Subgraph *addSubgraph(const char * name);
	void addSubgraph(Subgraph *graph);
	Subgraph *getSubgraph(const char *name);

	// ===== NODES METHODS =====
	Node *addNode(const char *name);
	int addNode(Node *node);
	Node *getNode(const char *name);
	// metoda zatim urcena pouze pro prekladac
	Node *getNode(Node *node);

	// ===== EDGES METHODS =====
	int addEdge(Edge *edge);
	int addEdge(Edge *edge, Attributes *attrs);
	Edge *addEdge(const char *from, const char *to);
	Edge *addEdge(Node *from, Node * to);
	template <typename T>
	Edge *addEdge(T *from, T *to, Attributes *attrs) {
		Edge *edge = addEdge(from, to);
		edge->setAttrs(attrs);

		return edge;
	};
	Edge *getEdge(Node *from, Node *to);
	Edge *getEdge(const char *from, const char *to);

	// ===== NODE ATTRIBUTES METHODS =====

	template <typename T>
	void setDefaultNodeAttr(const char *name, T value) {
		node_attrs.setAttr(name, value);
	}
	void setDefaultNodeAttr(Attribute *attr);
	void setDefaultNodeAttrs(Attributes *attrs);

	template <typename T, typename U>
	int setNodeAttr(U *arg_node, const char *attr_name, T value) {
		Node *node = getNode(arg_node);

		if(node == NULL) {
			return -1;
		}

		node->setAttr(attr_name, value);
		return 0;
	}

	// ===== EDGE ATTRIBUTES METHODS =====

	template <typename T>
	void setDeufalttEdgeAttr(const char *name, T value) {
		edge_attrs.setAttr(name, value);
	}
	void setDefaultEdgeAttr(Attribute *attr);
	void setDefaultEdgeAttrs(Attributes *attrs);

	template <typename T, typename U>
	int setEdgeAttr(U *from_node, U *to_node, const char* attr_name, T value) {
		Edge *edge = getEdge(from_node, to_node);

		if(edge == NULL) {
			return -1;
		}

		edge->setAttr(attr_name, value);
		return 0;
	}

	// ===== OTHERS =====
	nodes_map     *getNodes()     { return &nodes; }
	edges_vect    *getEdges()     { return &edges; }
	subgraphs_map *getSubgraphs() { return &subgraphs; }

	void clearDefaultNodeAttrs();
	void clearDefaultEdgeAttrs();
	void eraseDeafultNodeAttr(const char *name);
	void eraseDefaultEdgeAttr(const char *name);

};

class Subgraph : public GraphComponent {
private:
	const char *name;

public:
	Subgraph(GraphComponent *parent) { this->parent = parent; };
	Subgraph(GraphComponent *parent, const char *name) { this->parent = parent; this->name = name; }

	const char *getName();
	void setName(const char *value);

	Subgraph *setAttr(const char *name, Attribute *attr) {
		attrs.setAttr(name, attr);
		return this;
	}
	template <typename T>
	Subgraph *setAttr(const char *name, T value) {
		attrs.setAttr(name, value);
		return this;
	}
	template <typename T>
	Subgraph *setHtmlAttr(const char *name, T value) {
		attrs.setHtmlAttr(name,value);
		return this;
	}
};


#endif //BACHELOR_GRAPHCOMPONENT_H
