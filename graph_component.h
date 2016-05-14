//
// Created by Michael Holubec on 21.02.16.
//

#ifndef MEMGRAPH_GRAPHCOMPONENT_H
#define MEMGRAPH_GRAPHCOMPONENT_H


#include <vector>
#include "node.h"
#include "edge.h"
#include <typeinfo>

namespace memgraph {
	class Subgraph;

	typedef std::map<std::string, Subgraph *> subgraphs_map;
	typedef subgraphs_map::iterator subgraphs_it;
	typedef std::pair<std::string, Subgraph *> subgraphs_pair;
	typedef std::vector<Subgraph *> subgraphs_vect;

	class GraphComponent {
	private:
		nodes_map nodes;
		edges_vect edges;
		subgraphs_map subgraphs;
		Attributes node_attrs;
		Attributes edge_attrs;

		void insertEdge(Edge *edge);

		template<typename T>
		void checkNullObject(T *object) {
			if (object == NULL) {
				throw "Type of " + std::string(typeid(T).name()) + " - object is NULL";
			}
		}

		static void destructSubgraphs(subgraphs_map *subgraphs);

	protected:
		GraphComponent *parent = NULL;

		Node *getNodeInSubgraphs(std::string name);

		Node *getLocalNode(std::string name);

		GraphComponent *getMainParent();

		static string_vector available_attrs;

		static void printWarning(std::string name);

		static bool isAvailableAttr(std::string name);

	public:
		Attributes attrs;
		static bool enable_warnings;

		~GraphComponent() {
			destructSubgraphs(&subgraphs);

			for (auto i : nodes) {
				Node *node = i.second;
				delete node;
			}

			for (auto edge : edges) {
				delete edge;
			}
		}

		// ===== GRAPH_COMPONENT METHODS =====
		void setAttrs(Attributes *new_attrs);

		GraphComponent *setAttr(std::string name, Attribute *attr) {
			checkAttr(name);
			attrs.setAttr(name, attr);
			return this;
		}

		GraphComponent *setAttr(Attribute *attr) {
			checkAttr(attr->getName());
			attrs.setAttr(attr);
			return this;
		}

		template<typename T>
		GraphComponent *setAttr(std::string name, T value) {
			checkAttr(name);
			attrs.setAttr(name, value);
			return this;
		}

		template<typename T>
		GraphComponent *setHtmlAttr(std::string name, T value) {
			checkAttr(name);
			attrs.setHtmlAttr(name, value);
			return this;
		}

		// ===== SUBGRAPHS METHODS ======
		Subgraph *addSubgraph(std::string name);

		void addSubgraph(Subgraph *graph);

		Subgraph *getSubgraph(std::string name);

		// ===== NODES METHODS =====
		Node *addNode(std::string name);

		Node *addNode(Node *node);

		Node *getNode(std::string name);

		// metoda zatim urcena pouze pro prekladac
		Node *getNode(Node *node);

		// ===== EDGES METHODS =====
		Edge *addEdge(Edge *edge);

		Edge *addEdge(Edge *edge, Attributes *attrs);

		Edge *addEdge(std::string from, std::string to);

		Edge *addEdge(Node *from, Node *to);

		template<typename T>
		Edge *addEdge(T *from, T *to, Attributes *attrs) {
			Edge *edge = addEdge(from, to);
			edge->setAttrs(attrs);

			return edge;
		}

		Edge *getEdge(Node *from, Node *to);

		Edge *getEdge(std::string from, std::string to);

		// ===== NODE ATTRIBUTES METHODS =====

		template<typename T>
		void setNodeAttr(std::string name, T value) {
			Node::checkAttr(name);
			node_attrs.setAttr(name, value);
		}

		void setNodeAttr(Attribute *attr);

		void setNodeAttrs(Attributes *attrs);

		// ===== EDGE ATTRIBUTES METHODS =====

		template<typename T>
		void setEdgeAttr(std::string name, T value) {
			Edge::checkAttr(name);
			edge_attrs.setAttr(name, value);
		}

		void setEdgeAttr(Attribute *attr);

		void setEdgeAttrs(Attributes *attrs);

		// ===== OTHERS =====
		nodes_map *getNodes() { return &nodes; }

		edges_vect *getEdges() { return &edges; }

		subgraphs_map *getSubgraphs() { return &subgraphs; }

		Attributes *getNodeAttrs() { return &node_attrs; }

		Attributes *getEdgeAttrs() { return &edge_attrs; }

		Attributes *getAttrs() { return &attrs; }

		Attribute *getAttr(std::string name) { return attrs.getAttr(name); }

		static void checkAttr(std::string name);

		static void setAvailableAttrs(string_vector attrs) {
			available_attrs = attrs;
		}

	};

	class Subgraph : public GraphComponent {
	private:
		std::string name;

	public:
		Subgraph(GraphComponent *parent) { this->parent = parent; };

		Subgraph(GraphComponent *parent, std::string name) {
			this->parent = parent;
			this->name = name;
		}

		const char *getName();

		void setName(std::string value);
	};
}


#endif //MEMGRAPH_GRAPHCOMPONENT_H
