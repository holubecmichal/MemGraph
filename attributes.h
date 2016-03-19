//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_ATTRIBUTES_H
#define BACHELOR_ATTRIBUTES_H


#include <map>
#include <string>
#include <vector>
#include "attribute.h"

typedef std::map< const char *, Attribute* > attributes_map;
typedef attributes_map::iterator attributes_it;
typedef std::pair< const char *, Attribute* > attributes_pair;

typedef std::vector< std::string > string_vector;
typedef string_vector::iterator string_vector_it;

class Attributes {
private:
	attributes_map attrs;

	Attribute *insert(const char *name, Attribute *attr);
	Attribute *setAttr(const char *name);

public:
	Attributes() { attrs.empty(); }
	virtual ~Attributes() {
		for(attributes_it it = attrs.begin(); it != attrs.end(); ++it) {
			delete it->second;
		}
	}

	Attribute *getAttr(const char *name);
	unsigned long size();
	attributes_it begin();
	attributes_it end();

	void clear();
	void erase(const char *name);

	Attribute *setAttr(Attribute *attr);
	Attribute *setAttr(const char *name, Attribute *attr);
	void setAttrs(Attributes *attrs);
	template <typename T>

	// todo poresit jeste ten nepovinny parametr
	Attribute *setAttr(const char *name, T value, bool null_attr = false) {
		Attribute *attr = getAttr(name);

		if(attr != NULL) {
			attr->setValue(value);
		} else if(null_attr) {
			attr = insert(name, new Attribute(name));
		} else {
			attr = insert(name, new Attribute(name, value));
		}

		return attr;
	}


	template <typename T>
	Attribute *setHtmlAttr(const char *name, T value) {
		Attribute *attr = setAttr(name, value);
		attr->setHtml();
		return attr;
	}

	Attribute &operator[] (const char *name)
	{
		Attribute *attr = getAttr(name);

		if(attr == NULL) {
			attr = setAttr(name);
		}

		return *attr;
	}

};


#endif //BACHELOR_ATTRIBUTES_H
