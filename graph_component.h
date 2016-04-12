//
// Created by Michael Holubec on 21.02.16.
//

#ifndef BACHELOR_GRAPHCOMPONENT_H
#define BACHELOR_GRAPHCOMPONENT_H


#include <vector>
#include "node.h"
#include "Edge.h"

class Subgraph;

typedef std::map< std::string, Subgraph* > subgraphs_map;
typedef subgraphs_map::iterator subgraphs_it;
typedef std::pair< std::string, Subgraph* > subgraphs_pair;
typedef std::vector< Subgraph* > subgraphs_vect;

class GraphComponent {
private:
	nodes_map nodes;
	edges_vect edges;
	subgraphs_map subgraphs;
	Attributes node_attrs;
	Attributes edge_attrs;

	void insertEdge(Edge *edge);
	template <typename T>
	void checkNullObject(T *object) {
		if(object == NULL) {
			throw "Type of " + std::string(typeid(T).name()) + " - object is NULL";
		}
	}

protected:
	GraphComponent *parent;

	Node *getNodeInSubgraphs(const char *name);
	Node *getLocalNode(const char *name);
	GraphComponent *getMainParent();

	static string_vector available_attrs;
	static void printWarning(std::string name);
	static bool isAvailableAttr(std::string name);

public:
	Attributes attrs;
	static bool enable_warnings;

	virtual ~GraphComponent() { }

	// ===== GRAPH_COMPONENT METHODS =====
	void setAttrs(Attributes *attrs);
	GraphComponent *setAttr(const char *name, Attribute *attr) {
		checkAttr(name);
		attrs.setAttr(name, attr);
		return this;
	}
	template <typename T>
	GraphComponent *setAttr(const char *name, T value) {
		checkAttr(name);
		attrs.setAttr(name, value);
		return this;
	}
	template <typename T>
	GraphComponent *setHtmlAttr(const char *name, T value) {
		checkAttr(name);
		attrs.setHtmlAttr(name,value);
		return this;
	}

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
	void setNodeAttr(const char *name, T value) {
		Node::checkAttr(name);
		node_attrs.setAttr(name, value);
	}
	void setNodeAttr(Attribute *attr);
	void setNodeAttrs(Attributes *attrs);

	// ===== EDGE ATTRIBUTES METHODS =====

	template <typename T>
	void setEdgeAttr(const char *name, T value) {
		Edge::checkAttr(name);
		edge_attrs.setAttr(name, value);
	}
	void setEdgeAttr(Attribute *attr);
	void setEdgeAttrs(Attributes *attrs);

	// ===== OTHERS =====
	nodes_map     *getNodes()     { return &nodes; }
	edges_vect    *getEdges()     { return &edges; }
	subgraphs_map *getSubgraphs() { return &subgraphs; }
	Attributes    *getNodeAttrs() { return &node_attrs; }
	Attributes    *getEdgeAttrs() { return &edge_attrs; }
	Attributes    *getAttributes(){ return &attrs; }

	Attribute *getAttr(const char *name) { return attrs.getAttr(name); }

	static void checkAttr(std::string name);
	static void setAvailableAttrs(string_vector attrs) {
		available_attrs = attrs;
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


#endif //BACHELOR_GRAPHCOMPONENT_H
