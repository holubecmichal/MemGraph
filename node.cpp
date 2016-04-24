//
// Created by Michael Holubec on 15.02.16.
//

#include "node.h"
#include "graph_component.h"

string_vector Node::available_attrs;

void Node::setName(const char* value) {
	name = value;
}

const char*Node::getName() {
	return name.c_str();
}

Attribute *Node::getAttr(const char *name) {
	return attrs.getAttr(name);
}

Node *Node::setAttrs(Attributes *new_attrs) {
	for( auto i : *new_attrs) {
		checkAttr(i.first);
	}
	attrs.setAttrs(new_attrs);

	return this;
}

bool Node::isAvailableAttr(std::string name) {
	for(auto i : available_attrs) {
		if(i == name) {
			return true;
		}
	}

	return false;
}

void Node::checkAttr(std::string name) {
	if(!isAvailableAttr(name) && GraphComponent::enable_warnings) {
		printWarning(name);
	}
}

void Node::printWarning(std::string name) {
	std::cerr << "Node: Unknown atribute " << name << std::endl;
}
