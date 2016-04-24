//
// Created by Michael Holubec on 15.02.16.
//

#include "edge.h"
#include "graph_component.h"

string_vector Edge::available_attrs;

void Edge::setFrom(Node *node) {
	from = node;
}

Node *Edge::getFrom() {
	return from;
}

void Edge::setTo(Node *node) {
	to = node;
}

Node *Edge::getTo() {
	return to;
}

Attribute *Edge::getAttr(const char *name) {
	return attrs.getAttr(name);
}

void Edge::setAttrs(Attributes *new_attrs) {
	for( auto i : *new_attrs) {
		checkAttr(i.first);
	}
	attrs.setAttrs(new_attrs);
}

bool Edge::isAvailableAttr(std::string name) {
	for(auto i : available_attrs) {
		if(i == name) {
			return true;
		}
	}

	return false;
}

void Edge::checkAttr(std::string name) {
	if(!isAvailableAttr(name) && GraphComponent::enable_warnings) {
		printWarning(name);
	}
}

void Edge::printWarning(std::string name) {
	std::cerr << "Edge: Unknown atribute " << name << std::endl;
}
