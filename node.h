//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_NODE_H
#define BACHELOR_NODE_H

#include <string>
#include "attributes.h"

class Node {
private:
	const char* name;

public:
	Attributes attrs;

	Node() {
		name = "";
	}
	Node(const char *value) {
		name = value;
	}
	virtual ~Node() { }

	Attribute *getAttr(const char *name);
	const char* getName();
	void setName(const char *value);
	template <typename T>
	Node *setAttr(const char *name, T value) {
		attrs.setAttr(name, value);
		return this;
	}
	template <typename T>
	Node *setHtmlAttr(const char *name, T value) {
		attrs.setHtmlAttr(name,value);
		return this;
	}

};

typedef std::map< const char *, Node* > nodes_map;
typedef nodes_map::iterator nodes_it;
typedef std::pair< const char *, Node* > nodes_pair;


#endif //BACHELOR_NODE_H
