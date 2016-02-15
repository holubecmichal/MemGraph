//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_EDGE_H
#define BACHELOR_EDGE_H


#include "node.h"
#include "attributes.h"

class edge {
private:
	node from;
	node to;

public:
	attributes attrs;

	void setFrom(node from);
	node getFrom();
	void setTo(node to);
	node getTo();

	// TODO attrs getter setter

};


#endif //BACHELOR_EDGE_H
