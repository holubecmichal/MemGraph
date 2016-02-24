//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_NODE_H
#define BACHELOR_NODE_H

#include <string>
#include "attributes.h"

class node {
private:
	const char* name;

public:
	attributes attrs;

	node() {
		name = "";
	}

	node(const char* value) {
		name = value;
	}

	const char* getName();
	void setName(const char* value);

	template <typename T>
	void setAttr(const char *name, T value) {
		attrs.setAttr(name, value);
	}

	attribute *getAttr(const char *name);

};


#endif //BACHELOR_NODE_H
