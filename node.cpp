//
// Created by Michael Holubec on 15.02.16.
//

#include "node.h"

void Node::setName(const char* value) {
	name = value;
}

const char*Node::getName() {
	return name;
}

Attribute *Node::getAttr(const char *name) {
	return attrs.getAttr(name);
}

void Node::setAttrs(Attributes *attrs) {
	attrs->setAttrs(attrs);
}
