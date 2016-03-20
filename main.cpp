#include <iostream>
#include "attributes.h"
#include "node.h"
#include "edge.h"
#include "graph.h"
#include "plotter.h"
#include "graphviz_plotter.h"
#include "examples.h"
#include "graphviz_attrs.h"

using namespace std;

	// todo implementace graphvizu
	// todo attrs prepsat na asociativni pole?

int main() {
	GraphvizPlotter *plotter = new GraphvizPlotter();
	Graph *graph = plotter->graph;

	plotter->setOutputFormat(GraphvizPlotter::PNG);
	plotter->setOutputPath("/Users/Michal/FIT/Bachelor/");
	plotter->setOutputName("out");

	Examples::tonyballantyne_com_51(graph);
//	Examples::predator_1(graph);

	Attributes attrs;
	attrs["asd"] = "aasdasd";
	attrs["int"] = 10;
	attrs["bool"] = true;

	attrs["int"] = 50;
	attrs["int"] = "asdadsasdadasdasda";

	cout << plotter->getDot() << endl;
	plotter->plot();

	// todo moznost vypnout warnig graphvizu
	// todo vizualni styly
	// todo da se graphvi nastavit, aby mu sel nastavit minimalni uhel hran prekreslenych pres sebe ?
	// todo mrknout na predator adt - nastrankach pana Peringera
	// todo mrknout na ddd - debuger, ktery dokaze znazornit zmeny -> pro isomorfismus
	// todo pormyslet pouziti pro vykresleni adt v normalnich programech
	// todo verifit - smg 3

	return 0;
}