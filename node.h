//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_NODE_H
#define BACHELOR_NODE_H

#include <string>
#include "attributes.h"

class node {
private:
	std::string name;

public:
	attributes attrs;

	std::string getName();
	void setName(std::string name);

	// TODO attrs getter setter
};


#endif //BACHELOR_NODE_H
