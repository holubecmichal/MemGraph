//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_ATTRIBUTES_H
#define BACHELOR_ATTRIBUTES_H


#include <map>
#include <string>
#include "attribute.h"

typedef std::map< const char *, Attribute* > attributes_map;
typedef attributes_map::iterator attributes_it;
typedef std::pair< const char *, Attribute* > attributes_pair;

class Attributes {
private:
	attributes_map attrs;

	void insert(const char *name, Attribute *attr);

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
	void setAttr(const char *name, Attribute *attr);
	template <typename T>
	void setAttr(const char *name, T value) {
		Attribute *attr = getAttr(name);

		if(attr != NULL) {
			attr->setValue(value);
		} else {
			insert(name, new Attribute(name, value));
		}
	}

};


#endif //BACHELOR_ATTRIBUTES_H
