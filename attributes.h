//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_ATTRIBUTES_H
#define BACHELOR_ATTRIBUTES_H


#include <map>
#include <string>
#include "attribute.h"

class attributes {
protected:
	std::map<std::string, attribute> attrs;

public:
	int setAttrs(std::map<std::string, attribute>);
	int setAttr(std::string, attribute);
	std::map<std::string, attribute> getAttrs(std::string);
	attribute getAttr(std::string);
};


#endif //BACHELOR_ATTRIBUTES_H
