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
	const char* name;
	static string_vector available_attrs;

	static void printWarning(std::string name);
	static bool isAvailableAttr(std::string name);

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
		checkAttr(name);
		attrs.setAttr(name, value);
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

};

typedef std::map< std::string, Node* > nodes_map;
typedef nodes_map::iterator nodes_it;
typedef std::pair< std::string, Node* > nodes_pair;


#endif //BACHELOR_NODE_H
