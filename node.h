//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_NODE_H
#define BACHELOR_NODE_H

#include <string>
#include "attributes.h"

class node {
private:
	std::string name;

public:
	attributes attrs;

	node() {
		name = "";
	}

	node(std::string value) {
		name = value;
	}

	std::string getName();
	void setName(std::string value);

	template <typename T>
	void setAttr(std::string name, T value) {
		attrs.setAttr(name, value);
	}

	attribute *getAttr(std::string name);

};


#endif //BACHELOR_NODE_H
