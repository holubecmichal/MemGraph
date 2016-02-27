//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_EDGE_H
#define BACHELOR_EDGE_H


#include "node.h"
#include "attributes.h"

class Edge {
private:
	Node *from;
	Node *to;

public:
	Attributes attrs;

	Edge() {
		from = NULL;
		to = NULL;
	}

	Edge(Node *from, Node *to) : from(from), to(to) { }

	~Edge() {
		delete(from);
		delete(to);
	}

	void setFrom(Node *node);
	void setTo(Node *node);
	Node *getFrom();
	Node *getTo();
	void setAttrs(Attributes *attrs);
	Attribute *getAttr(const char *name);
	template <typename T>
	void setAttr(const char *name, T value) {
		attrs.setAttr(name, value);
	}

};

typedef std::map< const char *, Edge* > edges_map;
typedef nodes_map::iterator edges_it;
typedef std::pair< const char *, Edge* > edges_pair;


#endif //BACHELOR_EDGE_H
