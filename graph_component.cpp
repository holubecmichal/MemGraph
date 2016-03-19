//
// Created by Michael Holubec on 21.02.16.
//

#include <sstream>
#include "graph_component.h"

string_vector GraphComponent::available_attrs;
bool GraphComponent::enable_warnings(true);

// ===== GRAPH_COMPONENT CLASS =====

Node *GraphComponent::addNode(const char *name) {
	checkNullObject(name);
	Node *node = getNode(name);

	if(node == NULL) {
		node = new Node(name);
//		setNodeAttrs(node);
		nodes.insert(nodes_pair (name, node));
		return node;
	} else {
		return node;
	}
}

int GraphComponent::addNode(Node *node) {
	checkNullObject(node);

	if(getNode(node->getName()) == NULL) {
//		setNodeAttrs(node);
		nodes.insert(nodes_pair (node->getName(), node));
		return 0;
	} else {
		return 1;
	}
}

//Node *GraphComponent::getNode(const char *name) {
//	nodes_it it;
//
//	it = nodes.find(name);
//	if(it != nodes.end()) {
//		return nodes[name];
//	} else {
//		return NULL;
//	}
//}

Node *GraphComponent::getNode(Node *node) {
	return node;
}

Node *GraphComponent::getNode(const char *name) {
	Node *node = getLocalNode(name);

	if(node != NULL) {
		return node;
	}

	GraphComponent *main_parent = getMainParent();
	node = main_parent->getLocalNode(name);

	if(node != NULL) {
		return node;
	} else {
		return main_parent->getNodeInSubgraphs(name);
	}
}

Node *GraphComponent::getLocalNode(const char *name) {
	nodes_it it;

	it = nodes.find(name);
	if(it != nodes.end()) {
		return nodes[name];
	} else {
		return NULL;
	}
}

GraphComponent *GraphComponent::getMainParent() {
	GraphComponent *graph = this;

	if(graph->parent != NULL) {
		return graph->parent->getMainParent();
	} else {
		return graph;
	}
}

Node *GraphComponent::getNodeInSubgraphs(const char *name) {
	if(subgraphs.empty()) {
		return NULL;
	}

	// prohledavani prostoru
	for(subgraphs_it it = subgraphs.begin(); it != subgraphs.end(); ++it) {
		Subgraph *subgraph = it->second;
		Node *node = subgraph->getLocalNode(name);

		if(node != NULL) {
			return node;
		}
	}

	// rekurze o jeden krok dolu;
	for(subgraphs_it it = subgraphs.begin(); it != subgraphs.end(); ++it) {
		Subgraph *subgraph = it->second;
		Node *node = subgraph->getNodeInSubgraphs(name);

		if(node != NULL) {
			return node;
		}
	}

	return NULL;
}

int GraphComponent::addEdge(Edge *edge) {
	checkNullObject(edge);
	checkNullObject(edge->getFrom());
	checkNullObject(edge->getTo());

	insertEdge(edge);
	return 0;
}

Edge *GraphComponent::addEdge(const char *from, const char *to) {
	checkNullObject(from);
	checkNullObject(to);

	Node *From = NULL;
	Node *To = NULL;

	if(from != NULL) {
		From = getNode(from);

		if(From == NULL) {
			From = addNode(from);
		}
	}

	if(to != NULL) {
		To = getNode(to);

		if(To == NULL) {
			To = addNode(to);
		}
	}

	Edge *edge = new Edge();
//	setEdgeAttrs(edge);
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

	if(from != NULL) {
		From = getNode(from->getName());

		if(From == NULL) {
			addNode(from);
		}
	}

	if(to != NULL) {
		To = getNode(to->getName());

		if(To == NULL) {
			addNode(to);
		}
	}

	Edge *edge = new Edge();
//	setEdgeAttrs(edge);
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

	for(unsigned i = 0; i < edges.size(); i++) {
		Edge *edge = edges.at(i);

		Node *From = edge->getFrom();
		Node *To = edge->getTo();

		if(( From == NULL && from == NULL && To == NULL && to == NULL ) ||
		   ( From != NULL && From == from && To == NULL && to == NULL ) ||
		   ( From == NULL && from == NULL && To != NULL && To == to )   ||
		   ( From != NULL && From == from && To != NULL && To == to ))
		{

			return edge;

		}
	}

	return NULL;
}

Edge *GraphComponent::getEdge(const char *from, const char *to) {
	for(unsigned i = 0; i < edges.size(); i++) {
		Edge *edge = edges.at(i);

		Node *From = edge->getFrom();
		Node *To = edge->getTo();

		if(
			( From == NULL && from == NULL && To == NULL && to == NULL )            ||
			( From != NULL && From->getName() == from && To == NULL && to == NULL ) ||
			( From == NULL && from == NULL && To != NULL && To->getName() == to )   ||
			( From != NULL && From->getName() == from && To != NULL && To->getName() == to ))
		{

			return edge;

		}
	}

	return NULL;
}

Subgraph *GraphComponent::addSubgraph(const char *name) {
	Subgraph *subgraph = getSubgraph(name);

	if(subgraph == NULL) {
		subgraph = new Subgraph(this, name);
		subgraphs.insert(subgraphs_pair (name, subgraph));
	}

	return subgraph;
}

void GraphComponent::addSubgraph(Subgraph *graph) {
	checkNullObject(graph);

	Subgraph *subgraph = getSubgraph(graph->getName());

	if(subgraph != NULL) {
		subgraphs.insert(subgraphs_pair (graph->getName(), subgraph));
	}
}

Subgraph *GraphComponent::getSubgraph(const char *name) {
	subgraphs_it it;

	it = subgraphs.find(name);
	if(it != subgraphs.end()) {
		return subgraphs[name];
	} else {
		return NULL;
	}
}

// ===== SUBGRAPH CLASS =====
const char *Subgraph::getName() {
	return name;
}

void Subgraph::setName(const char *value) {
	name = value;
}

int GraphComponent::addEdge(Edge *edge, Attributes *attrs) {
	checkNullObject(edge);
	checkNullObject(attrs);

	int result = addEdge(edge);
	edge->setAttrs(attrs);

	return result;
}

void GraphComponent::setAttrs(Attributes *attrs) {
	checkNullObject(attrs);
	for( auto i : *attrs) {
		checkAttr(i.first);
	}
	this->attrs.setAttrs(attrs);
}

void GraphComponent::setNodeAttr(Attribute *attr) {
	Node::checkAttr(attr->getName());
	checkNullObject(attr);
	node_attrs.setAttr(attr);
}

void GraphComponent::setNodeAttrs(Attributes *attrs) {
	for( auto i : *attrs) {
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
	for( auto i : *attrs) {
		Edge::checkAttr(i.first);
	}
	checkNullObject(attrs);
	edge_attrs.setAttrs(attrs);
}

bool GraphComponent::isAvailableAttr(const char *name) {
	for(auto i : available_attrs) {
		if(i == name) {
			return true;
		}
	}

	return false;
}

void GraphComponent::checkAttr(const char *name) {
	if(!isAvailableAttr(name) && GraphComponent::enable_warnings) {
		printWarning(name);
	}
}

void GraphComponent::printWarning(const char *name) {
	std::cerr << "Graph: Unknown atribute " << name << std::endl;
}
