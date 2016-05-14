//
// Created by Michael Holubec on 12.04.16.
//

#ifndef MEMGRAPH_PREDATOR_H
#define MEMGRAPH_PREDATOR_H


#include "plotter.h"
#include "graphviz_plotter.h"

using namespace memgraph;
class Predator {
public:
	enum {
		OFF,
		ON,
	};

	enum {
		LVL_1,
		LVL_2,
	};

private:

	void walkEdgesRecursively(GraphComponent *graph, edges_vect *edges);
	void walkSubgraphsRecursively(GraphComponent *graph, subgraphs_vect *subgraphs);
	void walkNodesRecursively(GraphComponent *graph, nodes_vect *nodes);
	bool isSLS(Subgraph *sls);
	bool isHasValueEdge(Edge *edge);
	bool isPointsToEdge(Edge *edge);
	bool isValuesNode(Node *node);
	bool isDLS(Subgraph *dls);

public:
	Plotter *plotter;
	edges_vect getAllEdges();
	subgraphs_vect getAllSubgraphs();
	nodes_vect getAllNodes();
	edges_vect getHasValuesEdges();
	edges_vect getPointsToEdges();
	nodes_vect getValuesNodes();
	subgraphs_vect getSLSSubgraphs();
	subgraphs_vect getDLSSubgraphs();

	void abstractValues(int lvl);
	void abstractSLS(int lvl);
	void abstractDLS(int lvl);

	Predator(Plotter *plotter) : plotter(plotter) { }
	Predator() { plotter = new GraphvizPlotter(); }

	void plotOffset(bool status = ON);
};


#endif //MEMGRAPH_PREDATOR_H
