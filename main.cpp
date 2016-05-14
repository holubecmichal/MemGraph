#include <iostream>
#include <fstream>
#include "graphviz_plotter.h"
#include "examples.h"
#include "predator_wrapper.h"

using namespace std;
using namespace memgraph;

int main() {
	GraphvizPlotter *plotter = new GraphvizPlotter();
	plotter->setOutputPath("/Users/Michal/FIT/MemGraph/");
	plotter->setOutputFormat(GraphvizPlotter::PDF);
	plotter->setOutputName("dot_example");
//	Examples::predator_2(plotter->graph);
	plotter->parseDot(Examples::predatorTransformExample());
	cout << plotter->getDot() << endl;
	plotter->plot();

	// todo okomentovat

	delete plotter;


	return 0;
}