/////////////////////////////////////////////////////////////////////////
//
// Bakalářská práce
// Vizualizace datových struktur pro verifikační nástroje
// Michael Holubec
// GNU GPLv3
//
//////////////////////////////////////////////////////////////////////////


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
	plotter->setOutputName("subgraph");

	Examples::stdSubGraph(plotter->graph);


	cout << plotter->getDot() << endl;
	plotter->plot();

	delete plotter;

	return 0;
}