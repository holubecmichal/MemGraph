/////////////////////////////////////////////////////////////////////////
//
// Bakalářská práce
// Vizualizace datových struktur pro verifikační nástroje
// Michael Holubec
// GNU LGPLv3
//
//////////////////////////////////////////////////////////////////////////

//
// Created by Michael Holubec on 15.02.16.
//

#include "attributes.h"

namespace memgraph {
	Attribute *Attributes::insert(std::string name, Attribute *attr) {
		if(name.length() == 0) {
			throw "identificator is empty";
		}

		Attribute *attribute = getAttr(name);

		if (attribute != NULL) {
			attrs.erase(name);
		}

		attrs.insert(attributes_pair(name, attr));
		return attr;
	}

	Attribute *Attributes::setAttr(std::string name) {
		if(name.length() == 0) {
			throw "identificator is empty";
		}

		return setAttr(name, false, true);
	}

	Attribute *Attributes::setAttr(std::string name, Attribute *attribute) {
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

	Attribute *Attributes::setAttr(Attribute *attr) {
		return setAttr(attr->getName(), attr);
	}

	Attribute *Attributes::getAttr(std::string name) {
		attributes_it it;

		it = attrs.find(name);
		if (it != attrs.end()) {
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
		for (auto i : attrs) {
			Attribute *attr = i.second;
			delete attr;
		}

		attrs.clear();
	}

	void Attributes::erase(std::string name) {
		Attribute *attr = getAttr(name);

		if (attr != NULL) {
			delete attr;
			attrs.erase(name);
		}
	}

	void Attributes::setAttrs(Attributes *attrs) {
		for (auto i : *attrs) {
			setAttr(i.first, i.second);
		}
	}
}
