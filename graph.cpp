//
// Created by Michael Holubec on 22.02.16.
//

#include "graph.h"

namespace memgraph {
	void Graph::setType(graph_type value) {
		type = value;
	}

	graph_type Graph::getType() {
		return type;
	}
}
