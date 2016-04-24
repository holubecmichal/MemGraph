//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_EDGE_H
#define BACHELOR_EDGE_H


#include <vector>
#include "node.h"
#include "attributes.h"

class Edge {
private:
	Node *from;
	Node *to;
	static string_vector available_attrs;
	bool removed = false;

	static void printWarning(std::string name);
	static bool isAvailableAttr(std::string name);

public:
	Attributes attrs;

	Edge() {
		from = NULL;
		to = NULL;
	}

	Edge(Node *from, Node *to) : from(from), to(to) { }

	~Edge() {
		delete from;
		delete to;
	}

	void setFrom(Node *node);
	void setTo(Node *node);
	Node *getFrom();
	Node *getTo();
	Attribute *getAttr(const char *name);
	void setAttrs(Attributes *new_attrs);
	template <typename T>
	Edge *setAttr(const char *name, T value) {
		checkAttr(name);
		attrs.setAttr(name, value);
		return this;
	}
	Edge *setAttr(Attribute *attr) {
		checkAttr(attr->getName());
		attrs.setAttr(attr);
		return this;
	}
	template <typename T>
	Edge *setHtmlAttr(const char *name, T value) {
		checkAttr(name);
		attrs.setHtmlAttr(name, value);
		return this;
	}

	static void checkAttr(std::string name);
	static void setAvailableAttrs(string_vector attrs) {
		available_attrs = attrs;
	}

	attributes_map *getAttrs() {
		return this->attrs.getAttrs();
	}

	void remove() {
		removed = true;
	}

	bool isRemoved() {
		return removed;
	}

};

typedef std::vector< Edge* > edges_vect;
typedef edges_vect::iterator edges_it;


#endif //BACHELOR_EDGE_H
