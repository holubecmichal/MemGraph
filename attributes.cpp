//
// Created by Michael Holubec on 15.02.16.
//

#include "attributes.h"

Attribute *Attributes::insert(const char *name, Attribute *attr) {
	Attribute *attribute = getAttr(name);

	if(attribute != NULL) {
		attrs.erase(name);
		delete attribute;
	}

	attrs.insert( attributes_pair(name, attr) );
	return attr;
}

void Attributes::setAttr(const char *name, Attribute *attribute) {
	switch(attribute->getType()) {
		case Attribute::type_int:
			setAttr(name, attribute->getIValue());
			break;
		case Attribute::type_double:
			setAttr(name, attribute->getDValue());
			break;
		case Attribute::type_bool:
			setAttr(name, attribute->getBValue());
			break;
		case Attribute::type_string:
			setAttr(name, attribute->getSValue());
			break;
		default:
			throw "Unknown or uninitialized attribute";
	}
}

void Attributes::setAttr(Attribute *attr) {
	setAttr(attr->getName(), attr);
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
	for(attributes_it it = attrs.begin(); it != attrs.end(); ++it) {
		delete(it->second);
	}

	attrs.clear();
}

void Attributes::erase(const char *name) {
	Attribute *attr = getAttr(name);

	if(attr != NULL) {
		delete(attr);
		attrs.erase(name);
	}
}

void Attributes::setAttrs(Attributes *attrs) {
	for(attributes_it it = attrs->begin(); it != attrs->end(); ++it) {
		setAttr(it->first, it->second);
	}
}
