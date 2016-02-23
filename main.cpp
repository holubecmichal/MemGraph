#include <iostream>
#include "attribute.h"
#include "attributes.h"
#include "node.h"
#include "edge.h"
#include "graph.h"

using namespace std;

// todo construct, destruct
// todo refactoring

int main() {
	graph Graph;

	// todo inicializovat typ v konstruktoru
	Graph.setType(digraph);
	Graph.setDefaultNodeAttr("string", "asd");
	Graph.setDefaultNodeAttr("int", 10);
	Graph.setDefaultNodeAttr("double", 10.333);
	Graph.setDefaultNodeAttr("bool", true);

	Graph.setDefaultEdgeAttr("string", "asd");
	Graph.setDefaultEdgeAttr("int", 10);
	Graph.setDefaultEdgeAttr("double", 10.333);
	Graph.setDefaultEdgeAttr("bool", true);

	Graph.addEdge("prvni", "druhy");
	Graph.addEdge("zkouska", NULL);

	node *Node = Graph.getNode("zkouska");
	edge *Edge = Graph.getEdge(Node, NULL);

	return 0;
}