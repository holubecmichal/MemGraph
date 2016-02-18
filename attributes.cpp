//
// Created by Michael Holubec on 15.02.16.
//

#include "attributes.h"

void attributes::insert(std::string name, attribute attr) {
	attrs.insert( std::pair<std::string, attribute>(name, attr) );
}

void attributes::setAttr(std::string name, attribute attr) {
	insert(name, attr);
}

attribute *attributes::getAttr(std::string name) {
	std::map<std::string, attribute>::iterator it;

	it = attrs.find(name);
	if(it != attrs.end()) {
		return &attrs[name];
	} else {
		return NULL;
	}
}
