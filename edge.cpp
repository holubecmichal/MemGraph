//
// Created by Michael Holubec on 15.02.16.
//

#include "edge.h"


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
	for(attributes_it it = attrs->begin(); it != attrs->end(); ++it) {
		this->attrs.setAttr(it->first, it->second);
	}
}
