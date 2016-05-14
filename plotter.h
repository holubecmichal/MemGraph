//
// Created by Michael Holubec on 02.03.16.
//

#ifndef MEMGRAPH_PLOTTER_H
#define MEMGRAPH_PLOTTER_H


#include "graph.h"

namespace memgraph {
	const std::string new_line = "\n";
	const std::string tab = "\t";

	class Plotter {
	private:
		std::string getIdent();

		std::string dotGraphHeader();

		std::string dotAttribute(std::string name, Attribute *attr);

		std::string dotNodes(nodes_map *nodes);

		std::string dotEdges(edges_vect *edges);

		std::string dotSubgraphs(subgraphs_map *subgraphs);

		std::string dotSubgraph(Subgraph *subgraph);

		std::string dotEdgeType();

		std::string dotGraphAttrs(Attributes *attrs);

		std::string dotGraphNodeAttrs(Attributes *attrs);

		std::string dotGraphEdgeAttrs(Attributes *attrs);

		std::string dotAttributes(Attributes *attrs);

	public:
		Graph *graph = NULL;
		int ident_step = 0;

		Plotter(Graph *graph) : graph(graph) { }

		Plotter() { graph = new Graph; }


		virtual ~Plotter() {
			if (graph != NULL) {
				delete graph;
			}
		}

		std::string getDot();

		virtual void plot() = 0;

		virtual void setOutputPath(std::string path) = 0;

		virtual void setOutputName(std::string name) = 0;

	};
}


#endif //MEMGRAPH_PLOTTER_H
