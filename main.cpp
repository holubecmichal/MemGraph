#include <iostream>
#include "attributes.h"
#include "node.h"
#include "edge.h"
#include "graph.h"
#include "plotter.h"
#include "graphviz_plotter.h"
#include "examples.h"

using namespace std;

	// todo implementace graphvizu
	// todo attrs prepsat na asociativni pole?

int main() {
	GraphvizPlotter *plotter = new GraphvizPlotter();
	Graph *graph = plotter->graph;

	plotter->setOutputFormat(GraphvizPlotter::PNG);
	plotter->setOutputPath("/Users/Michal/FIT/Bachelor/");
	plotter->setOutputName("out");

	Examples::forester_1(graph);
	//Examples::predator_1(graph);

	cout << plotter->getDot() << endl;
	plotter->plot();

	return 0;
}