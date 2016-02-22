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

attribute *edge::getAttr(std::string name) {
	return attrs.getAttr(name);
}
