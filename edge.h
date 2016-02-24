//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_EDGE_H
#define BACHELOR_EDGE_H


#include "node.h"
#include "attributes.h"

class edge {
private:
	node *from;
	node *to;

public:
	attributes attrs;

	edge() {
		from = NULL;
		to = NULL;
	}
	~edge() {
		delete(from);
		delete(to);
	}

	edge(node *from, node *to) : from(from), to(to) { }

	void setFrom(node *from_node);
	node *getFrom();
	void setTo(node *to_node);
	node *getTo();

	template <typename T>
	void setAttr(const char *name, T value) {
		attrs.setAttr(name, value);
	}

	void setAttrs(attributes *attrs);

	attribute *getAttr(const char *name);

};


#endif //BACHELOR_EDGE_H
