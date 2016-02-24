//
// Created by Michael Holubec on 15.02.16.
//

#include "edge.h"


void edge::setFrom(node *from_node) {
	from = from_node;
}

node *edge::getFrom() {
	return from;
}

void edge::setTo(node *to_node) {
	to = to_node;
}

node *edge::getTo() {
	return to;
}

attribute *edge::getAttr(const char *name) {
	return attrs.getAttr(name);
}

void edge::setAttrs(attributes *attrs) {
	for(attributes_it it = attrs->begin(); it != attrs->end(); ++it) {
		this->attrs.setAttr(it->first, it->second);
	}
}
