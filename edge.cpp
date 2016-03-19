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

void Edge::setAttrs(Attributes *attrs) {
	for( auto i : *attrs) {
		checkAttr(i.first);
	}
	attrs->setAttrs(attrs);
}

bool Edge::isAvailableAttr(const char *name) {
	for(auto i : available_attrs) {
		if(i == name) {
			return true;
		}
	}

	return false;
}

void Edge::checkAttr(const char *name) {
	if(!isAvailableAttr(name) && GraphComponent::enable_warnings) {
		printWarning(name);
	}
}

void Edge::printWarning(const char *name) {
	std::cerr << "Edge: Unknown atribute " << name << std::endl;
}
