//
// Created by Michael Holubec on 15.02.16.
//

#include "node.h"

void node::setName(std::string value) {
	name = value;
}

std::string node::getName() {
	return name;
}

attribute *node::getAttr(std::string name) {
	return attrs.getAttr(name);
}
