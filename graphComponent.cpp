//
// Created by Michael Holubec on 21.02.16.
//

#include "graphComponent.h"

node *graphComponent::addNode(const char *name) {
	node *Node = getNode(name);

	if(Node == NULL) {
		Node = new node(name);
		setDefaultNodeAttrs(Node);
		nodes.insert(std::pair<const char*, node*> (name, Node));
		return Node;
	} else {
		return Node;
	}
}

int graphComponent::addNode(node *Node) {
	if(getNode(Node->getName()) == NULL) {
		setDefaultNodeAttrs(Node);
		nodes.insert(std::pair<const char*, node*> (Node->getName(), Node));
		return 0;
	} else {
		return 1;
	}
}

node *graphComponent::getNode(const char *name) {
	std::map<const char*, node*>::iterator it;

	it = nodes.find(name);
	if(it != nodes.end()) {
		return nodes[name];
	} else {
		return NULL;
	}
}

edge *graphComponent::addEdge() {
	edge *Edge = new edge();
	setDefaultEdgeAttrs(Edge);
	insertEdge(Edge);

	return Edge;
}

int graphComponent::addEdge(edge *Edge) {
	if(getEdge(Edge->getFrom(), Edge->getTo()) == NULL) {
		setDefaultEdgeAttrs(Edge);
		insertEdge(Edge);
		return 0;
	} else {
		return 1;
	}
}

edge *graphComponent::addEdge(const char *from, const char *to) {
	node *From = getNode(from);
	node *To = getNode(to);

	if(From == NULL) {
		From = addNode(from);
	}
	if(To == NULL) {
		To = addNode(to);
	}

	edge *Edge = new edge();
	setDefaultEdgeAttrs(Edge);
	insertEdge(Edge);

	Edge->setFrom(From);
	Edge->setTo(To);

	return Edge;
}

edge *graphComponent::getEdge(node *from, node *to) {
	for(unsigned i = 0; i < edges.size(); i++) {
		edge *Edge = edges.at(i);

		if(Edge->getFrom() == from && Edge->getTo() == to) {
			return Edge;
		}
	}

	return NULL;
}

void graphComponent::insertEdge(edge *Edge) {
	edges.insert(edges.end(), Edge);
}

edge *graphComponent::getEdge(const char *from, const char *to) {
	for(unsigned i = 0; i < edges.size(); i++) {
		edge *Edge = edges.at(i);

		if(Edge->getFrom()->getName() == from && Edge->getTo()->getName() == to) {
			return Edge;
		}
	}

	return NULL;
}

void graphComponent::setDefaultNodeAttr(const char *name, attribute attr) {
	node_attrs.setAttr(name, attr);
}

void graphComponent::setDefaultEdgeAttr(const char *name, attribute attr) {
	edge_attrs.setAttr(name, attr);
}

const char *subgraph::getName() {
	return name;
}

void subgraph::setName(const char *value) {
	name = value;
}

void graphComponent::setDefaultNodeAttrs(node *Node) {
	for(map_string_attr_it it = node_attrs.begin(); it != node_attrs.end(); ++it) {
		Node->setAttr(it->first, it->second);
	}
}

void graphComponent::setDefaultEdgeAttrs(edge *Edge) {
	for(map_string_attr_it it = edge_attrs.begin(); it != edge_attrs.end(); ++it) {
		Edge->setAttr(it->first, it->second);
	}
}
