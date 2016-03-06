//
// Created by Michael Holubec on 02.03.16.
//

#ifndef BACHELOR_PLOTTER_H
#define BACHELOR_PLOTTER_H


#include "graph.h"

const std::string new_line = "\n";
const std::string tab = "\t";
const std::string q_mark = "\"";

class Plotter {
public:
	Graph *graph;
	int ident_step;

	Plotter(Graph *graph) : graph(graph) { ident_step = 0; }
	Plotter() { graph = new Graph; ident_step = 0; }

	virtual std::string getDot() = 0;
	virtual void plot(const char *name) = 0;
	virtual void setOutputFormat() = 0;

};


#endif //BACHELOR_PLOTTER_H
