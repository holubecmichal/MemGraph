//
// Created by Michael Holubec on 19.03.16.
//

#ifndef BACHELOR_AVAILABLE_ATTRS_H
#define BACHELOR_AVAILABLE_ATTRS_H


#include <vector>

class AvailableAttrs {
public:
	enum type {
		NODE,
		EDGE,
		GRAPH
	};

	std::vector<std::string> node_attrs;
	std::vector<std::string> edge_attrs;
	std::vector<std::string> graph_attrs;
};


#endif //BACHELOR_AVAILABLE_ATTRS_H
