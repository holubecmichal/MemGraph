//
// Created by Michael Holubec on 21.02.16.
//

#include <sstream>
#include "graph_component.h"

namespace memgraph {
	string_vector GraphComponent::available_attrs;
	bool GraphComponent::enable_warnings(true);

// ===== GRAPH_COMPONENT CLASS =====

	Node *GraphComponent::addNode(std::string name) {
		if(name.length() == 0) {
			throw "Node: node name is empty";
		}
		Node *node = getNode(name);

		if (node == NULL) {
			node = new Node(name);
			nodes.insert(nodes_pair(name, node));
		}

		return node;
	}

	Node *GraphComponent::addNode(Node *node) {
		checkNullObject(node);

		if (getNode(node->getName()) == NULL) {
			nodes.insert(nodes_pair(node->getName(), node));
		}

		return node;
	}

	Node *GraphComponent::getNode(Node *node) {
		return node;
	}

	Node *GraphComponent::getNode(std::string name) {
		Node *node = getLocalNode(name);

		if (node != NULL) {
			return node;
		}

		GraphComponent *main_parent = getMainParent();
		node = main_parent->getLocalNode(name);

		if (node != NULL) {
			return node;
		} else {
			return main_parent->getNodeInSubgraphs(name);
		}
	}

	Node *GraphComponent::getLocalNode(std::string name) {
		nodes_it it;

		it = nodes.find(name);
		if (it != nodes.end()) {
			return nodes[name];
		} else {
			return NULL;
		}
	}

	GraphComponent *GraphComponent::getMainParent() {
		GraphComponent *graph = this;

		if (graph->parent != NULL) {
			return graph->parent->getMainParent();
		} else {
			return graph;
		}
	}

	Node *GraphComponent::getNodeInSubgraphs(std::string name) {
		if (subgraphs.empty()) {
			return NULL;
		}

		// prohledavani prostoru
		// nejdrvie prohledani vlastnich podgrafu
		for (auto i : subgraphs) {
			Subgraph *subgraph = i.second;
			Node *node = subgraph->getLocalNode(name);

			if (node != NULL) {
				return node;
			}
		}

		// nasledne vnoreni do podgrafu a prohledavani v jeho prostoru
		// rekurze - zanoreni o jeden krok;
		for (auto i : subgraphs) {
			Subgraph *subgraph = i.second;
			Node *node = subgraph->getNodeInSubgraphs(name);

			if (node != NULL) {
				return node;
			}
		}

		return NULL;
	}

	Edge *GraphComponent::addEdge(Edge *edge) {
		checkNullObject(edge);
		checkNullObject(edge->getFrom());
		checkNullObject(edge->getTo());

		insertEdge(edge);
		return 0;
	}

	Edge *GraphComponent::addEdge(std::string from, std::string to) {
		if(from.length() == 0 || to.length() == 0) {
			throw "Edge: some of node is empty";
		}

		Node *From = getNode(from);
		if (From == NULL) {
			From = addNode(from);
		}

		Node *To = getNode(to);
		if (To == NULL) {
			To = addNode(to);
		}


		Edge *edge = new Edge();
		insertEdge(edge);

		edge->setFrom(From);
		edge->setTo(To);

		return edge;
	}

	Edge *GraphComponent::addEdge(Node *from, Node *to) {
		checkNullObject(from);
		checkNullObject(to);

		Node *From = NULL;
		Node *To = NULL;

		if (from != NULL) {
			From = getNode(from->getName());

			if (From == NULL) {
				addNode(from);
			}
		}

		if (to != NULL) {
			To = getNode(to->getName());

			if (To == NULL) {
				addNode(to);
			}
		}

		Edge *edge = new Edge();
		insertEdge(edge);

		edge->setFrom(From);
		edge->setTo(To);

		return edge;
	}

	void GraphComponent::insertEdge(Edge *edge) {
		checkNullObject(edge);

		edges.insert(edges.end(), edge);
	}

	Edge *GraphComponent::getEdge(Node *from, Node *to) {
		checkNullObject(from);
		checkNullObject(to);

		for (auto edge : edges) {
			Node *From = edge->getFrom();
			Node *To = edge->getTo();

			if (From != NULL && To != NULL) {
				if(From == from && To == to) {
					return edge;
				}
			}
		}

		return NULL;
	}

	Edge *GraphComponent::getEdge(std::string from, std::string to) {
		for (auto edge : edges) {
			Node *From = edge->getFrom();
			Node *To = edge->getTo();

			if (From != NULL && To != NULL) {
				if(From->getName() == from && To->getName() == to) {
					return edge;
				}
			}
		}

		return NULL;
	}

	Subgraph *GraphComponent::addSubgraph(std::string name) {
		Subgraph *subgraph = getSubgraph(name);

		if (subgraph == NULL) {
			subgraph = new Subgraph(this, name);
			subgraphs.insert(subgraphs_pair(name, subgraph));
		}

		return subgraph;
	}

	Subgraph *GraphComponent::getSubgraph(std::string name) {
		subgraphs_it it;

		it = subgraphs.find(name);
		if (it != subgraphs.end()) {
			return subgraphs[name];
		} else {
			return NULL;
		}
	}

// ===== SUBGRAPH CLASS =====
	const char *Subgraph::getName() {
		return name.c_str();
	}

	void Subgraph::setName(std::string value) {
		name = value;
	}

	void GraphComponent::setAttrs(Attributes *new_attrs) {
		checkNullObject(new_attrs);
		for (auto i : *new_attrs) {
			checkAttr(i.first);
		}

		attrs.setAttrs(new_attrs);
	}

	void GraphComponent::setNodeAttr(Attribute *attr) {
		Node::checkAttr(attr->getName());
		checkNullObject(attr);
		node_attrs.setAttr(attr);
	}

	void GraphComponent::setNodeAttrs(Attributes *attrs) {
		for (auto i : *attrs) {
			Node::checkAttr(i.first);
		}
		checkNullObject(attrs);
		node_attrs.setAttrs(attrs);
	}

	void GraphComponent::setEdgeAttr(Attribute *attr) {
		Edge::checkAttr(attr->getName());
		checkNullObject(attr);
		edge_attrs.setAttr(attr);
	}

	void GraphComponent::setEdgeAttrs(Attributes *attrs) {
		for (auto i : *attrs) {
			Edge::checkAttr(i.first);
		}
		checkNullObject(attrs);
		edge_attrs.setAttrs(attrs);
	}

	bool GraphComponent::isAvailableAttr(std::string name) {
		if (available_attrs.size() == 0) {
			return true;
		}

		for (auto i : available_attrs) {
			if (i == name) {
				return true;
			}
		}

		return false;
	}

	void GraphComponent::checkAttr(std::string name) {
		if (!isAvailableAttr(name) && GraphComponent::enable_warnings) {
			printWarning(name);
		}
	}

	void GraphComponent::printWarning(std::string name) {
		std::cerr << "Graph: Unknown atribute " << name << std::endl;
	}

	void GraphComponent::destructSubgraphs(subgraphs_map *subgraphs) {
		for (auto i : *subgraphs) {
			Subgraph *subgraph = i.second;
			delete subgraph;
		}
	}
}
