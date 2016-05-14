#include <iostream>
#include <fstream>
#include "graphviz_plotter.h"
#include "examples.h"
#include "predator.h"

using namespace std;

int main() {
	GraphvizPlotter *plotter = new GraphvizPlotter();
	plotter->setOutputPath("/Users/Michal/FIT/MemGraph/");
	plotter->setOutputFormat(GraphvizPlotter::PDF);
	plotter->setOutputName("dot_example");
	Examples::predator_1(plotter->graph);

	cout << plotter->getDot() << endl;
	plotter->plot();

	// todo pokusit se prepsat vsechna const char * na std::string
	// todo okomentovat

	delete plotter;


	return 0;
}