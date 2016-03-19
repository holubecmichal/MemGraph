//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_NODE_H
#define BACHELOR_NODE_H

#include <string>
#include <vector>
#include "attributes.h"
#include "available_attrs.h"
#include "graphviz_attrs.h"

class Node {
private:
	const char* name;
	static string_vector available_attrs;

	bool isAvailableAttrs(const char *name);

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
	void setAttrs(Attributes *attrs);
	template <typename T>
	Node *setAttr(const char *name, T value) {
		if(!isAvailableAttrs(name)) {
			std::cerr << "Node: Unknown atribute " << name << std::endl;
		}

		attrs.setAttr(name, value);
		return this;
	}
	template <typename T>
	Node *setHtmlAttr(const char *name, T value) {
		if(!isAvailableAttrs(name)) {
			std::cerr << "Node: Unknown atribute " << name << std::endl;
		}

		attrs.setHtmlAttr(name,value);
		return this;
	}

	static void setAvailableAttrs(string_vector attrs) {
		for(auto i : attrs) {
			available_attrs.push_back(i);
		}
	}

};

typedef std::map< const char *, Node* > nodes_map;
typedef nodes_map::iterator nodes_it;
typedef std::pair< const char *, Node* > nodes_pair;


#endif //BACHELOR_NODE_H
