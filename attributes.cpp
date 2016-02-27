//
// Created by Michael Holubec on 15.02.16.
//

#include "attributes.h"

// todo osetrit moznost prepsani atributu, tj pokud zapisuju atribut jmena, ktery uz v map je, pak prepisu jeji second hodnotu
void Attributes::insert(const char *name, Attribute *attr) {
	attrs.insert( attributes_pair(name, attr) );
}

void Attributes::setAttr(const char *name, Attribute *attr) {
	insert(name, attr);
}

Attribute *Attributes::getAttr(const char *name) {
	attributes_it it;

	it = attrs.find(name);
	if(it != attrs.end()) {
		return attrs[name];
	} else {
		return NULL;
	}
}

unsigned long Attributes::size() {
	return attrs.size();
}

attributes_it Attributes::begin() {
	return attrs.begin();
}

attributes_it Attributes::end() {
	return attrs.end();
}

void Attributes::clear() {
	attrs.clear();
}

void Attributes::erase(const char *name) {
	attrs.erase(name);
}
