#include <iostream>
#include <fstream>
#include "graphviz_plotter.h"
#include "examples.h"
#include "predator.h"

using namespace std;

int main() {
//	GraphvizPlotter *plotter = new GraphvizPlotter();

//	plotter->setOutputFormat(GraphvizPlotter::PNG);
//	plotter->setOutputPath("/Users/Michal/FIT/Bachelor/");
//	plotter->setOutputName("out");

//	Examples::forester_1(plotter->graph);
//
//	std::string plotName("asdasd");
//	plotter->graph->setHtmlAttr("label", "<FONT POINT-SIZE=\"18\">" + plotName + "</FONT>");
//
//	cout << plotter->getDot() << endl;
//
//	plotter->plot();
//
//	Graph *graph = new Graph();
//
//	Attributes attrs;
//	attrs.setAttr("penwidth", 3.0);
//	attrs.setAttr("style", "dashed");
//
//	attrs.clear();
//
//	Node *node = graph->addNode("test")
//		->setAttr("shape", "box")
//		->setAttr("color","red")
//		->setAttr("fontcolor", "red");

//	node->setAttrs(&attrs);


//	plotter->parseDot(Examples::predator_dot_file());
//	cout << plotter->getDot() << endl;
//	plotter->plot();

//	Predator *predator = new Predator(plotter);
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

//	cout << plotter->getDot() << endl;
//	predator->plotter->plot();

//	std::cout << "asd" << endl;

	GraphvizPlotter *plotter = new GraphvizPlotter();
	plotter->setOutputPath("/Users/Michal/FIT/Bachelor/");
//
////	std::string file_name("/Users/Michal/FIT/Bachelor/00-0000_bcPlot.dot");
////	std::ifstream ifs(file_name);
////	std::string content( (std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()) );
//
//	plotter->parseDot(content.c_str());
//
	plotter->setOutputFormat(GraphvizPlotter::PDF);
	plotter->setOutputName("dot_example");
	Examples::predator_1(plotter->graph);
//	Examples::predator_2(plotter->graph);


//	Predator *predator = new Predator(plotter);
//	predator->plotOffset(Predator::OFF);
//
//	predator->abstractValues(Predator::LVL_1);
//	predator->abstractSLS(Predator::LVL_1);
//	predator->abstractDLS(Predator::LVL_1);

	cout << plotter->getDot() << endl;
	plotter->plot();

	// todo pokusit se prepsat vsechna const char * na std::string
	// todo okomentovat

	delete plotter;


	return 0;
}