//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_NODE_H
#define BACHELOR_NODE_H

#include <string>
#include <vector>
#include "attributes.h"
#include "graphviz_attrs.h"

class Node {
private:
	std::string name = "";
	static string_vector available_attrs;
	bool removed = false;

	static void printWarning(std::string name);
	static bool isAvailableAttr(std::string name);

public:
	Attributes attrs;

	Node() { }
	Node(const char *value) {
		name = value;
	}
	Node(std::string name) {
		this->name = name;
	}
	virtual ~Node() { }

	Attribute *getAttr(const char *name);
	const char* getName();
	void setName(const char *value);
	Node *setAttrs(Attributes *new_attrs);
	template <typename T>
	Node *setAttr(const char *name, T value) {
		checkAttr(name);
		attrs.setAttr(name, value);
		return this;
	}
	Node *setAttr(Attribute *attr) {
		checkAttr(attr->getName());
		attrs.setAttr(attr);
		return this;
	}
	template <typename T>
	Node *setHtmlAttr(const char *name, T value) {
		checkAttr(name);
		attrs.setHtmlAttr(name,value);
		return this;
	}

	static void checkAttr(std::string name);
	static void setAvailableAttrs(string_vector attrs) {
		available_attrs = attrs;
	}

	void remove() {
		removed = true;
	}
	bool isRemoved() {
		return removed;
	}

};

typedef std::map< std::string, Node* > nodes_map;
typedef nodes_map::iterator nodes_it;
typedef std::pair< std::string, Node* > nodes_pair;
typedef std::vector< Node* > nodes_vect;


#endif //BACHELOR_NODE_H
