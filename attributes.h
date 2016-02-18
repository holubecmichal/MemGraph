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
	void insert(std::string name, base_attribute attr);

protected:
	std::map<std::string, base_attribute> attrs;

public:
	attributes() { attrs.empty(); }

	void setAttr(std::string name, base_attribute attr);
	void setAttr(std::string name, int value);
	void setAttr(std::string name, double value);
	void setAttr(std::string name, std::string value);
	void setAttr(std::string name, bool value);
	std::map<std::string, base_attribute> getAttrs();
//	attribute getAttr(std::string name);
};


#endif //BACHELOR_ATTRIBUTES_H
