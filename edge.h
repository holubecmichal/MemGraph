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

	static void printWarning(const char *name);
	static bool isAvailableAttr(const char *name);

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
	void setAttrs(Attributes *attrs);
	template <typename T>
	Edge *setAttr(const char *name, T value) {
		checkAttr(name);
		attrs.setAttr(name, value);
		return this;
	}
	template <typename T>
	Edge *setHtmlAttr(const char *name, T value) {
		checkAttr(name);
		attrs.setHtmlAttr(name, value);
		return this;
	}

	static void checkAttr(const char *name);
	static void setAvailableAttrs(string_vector attrs) {
		available_attrs = attrs;
	}

};

typedef std::vector< Edge* > edges_vect;
typedef edges_vect::iterator edges_it;


#endif //BACHELOR_EDGE_H
