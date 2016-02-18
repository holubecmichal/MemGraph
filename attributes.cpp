//
// Created by Michael Holubec on 15.02.16.
//

#include "attributes.h"

void attributes::insert(std::string name, base_attribute attr) {
	attrs.insert( std::pair<std::string, base_attribute>(name, attr) );
}

void attributes::setAttr(std::string name, base_attribute attr) {
	insert(name, attr);
}

void attributes::setAttr(std::string name, int value) {
	attribute<int> attr(value);
	insert(name, attr);
}

void attributes::setAttr(std::string name, double value) {
	attribute<double> attr(value);
	insert(name, attr);
}

void attributes::setAttr(std::string name, std::string value) {
	attribute<std::string> attr(value);
	insert(name, attr);
}

void attributes::setAttr(std::string name, bool value) {
	attribute<bool> attr(value);
	insert(name, attr);
}

std::map<std::string, base_attribute> attributes::getAttrs() {
	return attrs;
}

//base_attribute attributes::getAttr(std::string name) {
//	std::map<std::string,base_attribute>::iterator it;
//
//	it = attrs.find(name);
//	//if(it != attrs.end()) {
//		return attrs[name];
//	//}
//}

