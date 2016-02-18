//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_ATTRIBUTES_H
#define BACHELOR_ATTRIBUTES_H


#include <map>
#include <string>
#include "attribute.h"

class attributes {
private:
	void insert(std::string name, attribute attr);
	std::map<std::string, attribute> attrs;

public:
	attributes() { attrs.empty(); }

	void setAttr(std::string name, attribute attr);
	template <typename T>
	void setAttr(std::string name, T value) {
		insert(name, attribute(value));
	}

	attribute *getAttr(std::string name);
};


#endif //BACHELOR_ATTRIBUTES_H
