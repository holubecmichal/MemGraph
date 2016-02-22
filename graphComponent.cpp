//
// Created by Michael Holubec on 21.02.16.
//

#include "graphComponent.h"

node *graphComponent::addNode(const char *name) {
	node *Node = getNode(name);

	if(Node == NULL) {
		Node = new node(name);
		nodes.insert(std::pair<const char*, node*> (name, Node));
		return Node;
	} else {
		return Node;
	}
}

int graphComponent::addNode(node *Node) {
	if(getNode(Node->getName()) == NULL) {
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
	insertEdge(Edge);

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

int graphComponent::addEdge(edge *Edge) {
	if(getEdge(Edge->getFrom(), Edge->getTo()) == NULL) {
		insertEdge(Edge);
		return 0;
	} else {
		return 1;
	}
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

void graphComponent::setNodeAttr(const char *name, attribute attr) {
	node_attrs.setAttr(name, attr);
}

void graphComponent::setEdgeAttr(const char *name, attribute attr) {
	edge_attrs.setAttr(name, attr);
}
