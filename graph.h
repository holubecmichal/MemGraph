/////////////////////////////////////////////////////////////////////////
//
// Bakalářská práce
// Vizualizace datových struktur pro verifikační nástroje
// Michael Holubec
// GNU LGPLv3
//
//////////////////////////////////////////////////////////////////////////

//
// Created by Michael Holubec on 22.02.16.
//

#ifndef MEMGRAPH_GRAPH_H
#define MEMGRAPH_GRAPH_H


#include "graph_component.h"

namespace memgraph {
	// typ grafu
	enum graph_type {
		std_graph, // neorientovany
		digraph    // orientovany
	};

	class Graph : public GraphComponent {
	private:
		// typ grafu
		graph_type type;

	public:
		Graph() {
			type = digraph;
			parent = NULL;
		}

		Graph(graph_type value) {
			type = value;
			parent = NULL;
		};

		/**
		 * nastavi typ grafu
		 * @param graph_type value typ grafu
		 */
		void setType(graph_type value);

		/**
		 * vraci typ gafu
		 * @return graph_type value typ grafu
		 */
		graph_type getType();
	};
}


#endif //MEMGRAPH_GRAPH_H
