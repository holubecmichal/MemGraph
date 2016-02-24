//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_ATTRIBUTES_H
#define BACHELOR_ATTRIBUTES_H


#include <map>
#include <string>
#include "attribute.h"

typedef std::map<const char *, attribute>::iterator attributes_it;

class attributes {
private:
	void insert(const char *name, attribute attr);
	std::map<const char *, attribute> attrs;

public:
	attributes() { attrs.empty(); }

	void setAttr(const char *name, attribute attr);
	template <typename T>
	void setAttr(const char *name, T value) {
		attribute *attr = getAttr(name);

		if(attr != NULL) {
			attr->setValue(value);
		} else {
			insert(name, attribute(value));
		}
	}

	attribute *getAttr(const char *name);
	unsigned long size();
	attributes_it begin();
	attributes_it end();
	void clear();
	void erase(const char *name);

};


#endif //BACHELOR_ATTRIBUTES_H
