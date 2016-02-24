//
// Created by Michael Holubec on 15.02.16.
//

#include "attributes.h"

// todo osetrit moznost prepsani atributu, tj pokud zapisuju atribut jmena, ktery uz v map je, pak prepisu jeji second hodnotu
void attributes::insert(const char *name, attribute attr) {
	attrs.insert( std::pair<const char *, attribute>(name, attr) );
}

void attributes::setAttr(const char *name, attribute attr) {
	insert(name, attr);
}

attribute *attributes::getAttr(const char *name) {
	attributes_it it;

	it = attrs.find(name);
	if(it != attrs.end()) {
		return &attrs[name];
	} else {
		return NULL;
	}
}

unsigned long attributes::size() {
	return attrs.size();
}

attributes_it attributes::begin() {
	return attrs.begin();
}

attributes_it attributes::end() {
	return attrs.end();
}

void attributes::clear() {
	attrs.clear();
}

void attributes::erase(const char *name) {
	attrs.erase(name);
}
