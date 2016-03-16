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

Attribute *Attributes::setAttr(const char *name, Attribute *attribute) {
	switch(attribute->getType()) {
		case Attribute::type_int:
			return setAttr(name, attribute->getIValue());
		case Attribute::type_double:
			return setAttr(name, attribute->getDValue());
		case Attribute::type_bool:
			return setAttr(name, attribute->getBValue());
		case Attribute::type_string:
			return setAttr(name, attribute->getSValue());
		default:
			throw "Unknown Attribute type or uninitialize value";
	}
}

Attribute *Attributes::setAttr(const char *name) {
	return setAttr(name, false, true);
}

Attribute *Attributes::setAttr(Attribute *attr) {
	return setAttr(attr->getName(), attr);
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
