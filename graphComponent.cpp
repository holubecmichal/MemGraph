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
	if(from == NULL && to == NULL) {
		throw "What does it means?";
	}

	node *From = NULL;
	node *To = NULL;

	if(from != NULL) {
		From = getNodeInGraph(from);

		if(From == NULL) {
			From = addNode(from);
		}
	}

	if(to != NULL) {
		To = getNodeInGraph(to);

		if(To == NULL) {
			To = addNode(to);
		}
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

		node *From = Edge->getFrom();
		node *To = Edge->getTo();

		if(
				( From == NULL && from == NULL && To == NULL && to == NULL ) ||
				( From != NULL && From == from && To == NULL && to == NULL ) ||
				( From == NULL && from == NULL && To != NULL && To == to )   ||
				( From != NULL && From == from && To != NULL && To == to ))
		{

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

		node *From = Edge->getFrom();
		node *To = Edge->getTo();

		if(
			( From == NULL && from == NULL && To == NULL && to == NULL )            ||
			( From != NULL && From->getName() == from && To == NULL && to == NULL ) ||
			( From == NULL && from == NULL && To != NULL && To->getName() == to )   ||
			( From != NULL && From->getName() == from && To != NULL && To->getName() == to ))
		{

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
	for(attributes_it it = node_attrs.begin(); it != node_attrs.end(); ++it) {
		Node->setAttr(it->first, it->second);
	}
}

void graphComponent::setDefaultEdgeAttrs(edge *Edge) {
	for(attributes_it it = edge_attrs.begin(); it != edge_attrs.end(); ++it) {
		Edge->setAttr(it->first, it->second);
	}
}

edge *graphComponent::addEdge(node *from, node *to) {
	if(from == NULL && to == NULL) {
		throw "What does it means?";
	}
	// pokud budu z nejakeho uzlu tvorit hranu, pak musi byt soucasti grafu

	node *From = NULL;
	node *To = NULL;

	if(from != NULL) {
		From = getNodeInGraph(from->getName());

		if(From == NULL) {
			addNode(from);
		}
	}

	if(to != NULL) {
		To = getNodeInGraph(to->getName());

		if(To == NULL) {
			addNode(to);
		}
	}

	edge *Edge = new edge();
	setDefaultEdgeAttrs(Edge);
	insertEdge(Edge);

	Edge->setFrom(From);
	Edge->setTo(To);

	return Edge;
}

void graphComponent::clearDefaultNodeAttrs() {
	node_attrs.clear();
}

void graphComponent::clearDefaultEdgeAttrs() {
	edge_attrs.clear();
}

void graphComponent::eraseDeafultNodeAttr(const char *name) {
	if(node_attrs.getAttr(name) != NULL) {
		node_attrs.erase(name);
	}
}

void graphComponent::eraseDefaultEdgeAttr(const char *name) {
	if(edge_attrs.getAttr(name) != NULL) {
		edge_attrs.erase(name);
	}
}

subgraph *graphComponent::addSubgraph(const char *name) {
	subgraph *Subgraph = getSubgraph(name);

	if(Subgraph == NULL) {
		Subgraph = new subgraph(this, name);
		subgraphs.insert(std::pair< const char *, subgraph * > (name, Subgraph));
	}

	return Subgraph;
}

subgraph *graphComponent::getSubgraph(const char *name) {
	std::map<const char*, subgraph*>::iterator it;

	it = subgraphs.find(name);
	if(it != subgraphs.end()) {
		return subgraphs[name];
	} else {
		return NULL;
	}
}

void graphComponent::addSubgraph(subgraph *graph) {
	subgraph *Subgraph = getSubgraph(graph->getName());

	if(Subgraph != NULL) {
		subgraphs.insert(std::pair< const char *, subgraph * > (graph->getName(), Subgraph));
	}
}

node *graphComponent::getNodeInSubgraphs(const char *name) {
	if(subgraphs.empty()) {
		return NULL;
	}

	// prohledavani prostoru
	for(subgraph_it it = subgraphs.begin(); it != subgraphs.end(); ++it) {
		subgraph *Subgraph = it->second;
		node *Node = Subgraph->getNode(name);

		if(Node != NULL) {
			return Node;
		}
	}

	// rekurze o jeden krok dolu;
	for(subgraph_it it = subgraphs.begin(); it != subgraphs.end(); ++it) {
		subgraph *Subgraph = it->second;
		node *Node = Subgraph->getNodeInSubgraphs(name);

		if(Node != NULL) {
			return Node;
		}
	}

	return NULL;
}

node *graphComponent::getNodeInGraph(const char *name) {
	node *Node;
	Node = getNode(name);

	if(Node != NULL) {
		return Node;
	}

	graphComponent *main_parent = getMainParent();
	Node = main_parent->getNode(name);

	if(Node != NULL) {
		return Node;
	} else {
		return main_parent->getNodeInSubgraphs(name);
	}
}

graphComponent *graphComponent::getMainParent() {
	graphComponent *graph = this;

	if(graph->parent != NULL) {
		return graph->parent->getMainParent();
	} else {
		return graph;
	}
}
