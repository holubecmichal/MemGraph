//
// Created by Michael Holubec on 12.04.16.
//

#ifndef BACHELOR_PREDATOR_H
#define BACHELOR_PREDATOR_H


#include "plotter.h"
#include "graphviz_plotter.h"

class Predator {
public:
	enum {
		OFF,
		ON,
	};

private:
	edges_vect getAllEdges();

	void subgraphsEdgesRecursively(subgraphs_map *subgraphs, edges_vect *edges);
	void subgraphsSLSRecursively(subgraphs_map *subgraphs, subgraphs_vect *sls);
	bool isSLS(Subgraph *sls);

public:
	Plotter *plotter;
	subgraphs_vect getAllSLS();

	Predator(Plotter *plotter) : plotter(plotter) { }
	Predator() { plotter = new GraphvizPlotter(); }

	void pointsToOffset(bool status = ON);
	void rawObjectSLS(bool status = ON);
};


#endif //BACHELOR_PREDATOR_H
