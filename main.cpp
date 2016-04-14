#include <iostream>
#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>
#include "attributes.h"
#include "node.h"
#include "edge.h"
#include "graph.h"
#include "plotter.h"
#include "graphviz_plotter.h"
#include "examples.h"
#include "graphviz_attrs.h"
#include "predator.h"

using namespace std;

int main() {
	GraphvizPlotter *plotter = new GraphvizPlotter();

	plotter->setOutputFormat(GraphvizPlotter::PNG);
	plotter->setOutputPath("/Users/Michal/FIT/Bachelor/");
	plotter->setOutputName("out");

	plotter->parseDot(Examples::predator_sls_dls());
//	cout << plotter->getDot() << endl;
//	plotter->plot();

	Predator *predator = new Predator(plotter);
//	predator->plotOffset(Predator::OFF);


//	predator->getAllEdges();
//	predator->getAllSubgraphs();
//	predator->getAllNodes();
//	predator->getHasValuesEdges();
//	predator->getPointsToEdges();
//	predator->getValuesNodes();
//	predator->getSLSSubgraphs();
//	predator->getDLSSubgraphs();

//	predator->plotOffset(Predator::OFF);

//	predator->abstractValues(Predator::LVL_1);
//	predator->abstractSLS(Predator::LVL_1);
//	predator->abstractDLS(Predator::LVL_1);

	cout << plotter->getDot() << endl;
	predator->plotter->plot();

	// todo moznost vypnout warnig graphvizu
	// todo vizualni styly
	// todo mrknout na ddd - debuger, ktery dokaze znazornit zmeny -> pro isomorfismus

	return 0;
}