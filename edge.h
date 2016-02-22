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
	void setAttr(std::string name, T value) {
		attrs.setAttr(name, value);
	}

	attribute *getAttr(std::string name);

};


#endif //BACHELOR_EDGE_H
