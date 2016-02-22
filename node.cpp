//
// Created by Michael Holubec on 15.02.16.
//

#include "node.h"

void node::setName(const char* value) {
	name = value;
}

const char* node::getName() {
	return name;
}

attribute *node::getAttr(std::string name) {
	return attrs.getAttr(name);
}
