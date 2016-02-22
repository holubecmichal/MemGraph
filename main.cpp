#include <iostream>
#include "attribute.h"
#include "attributes.h"
#include "node.h"
#include "edge.h"
#include "graph.h"

using namespace std;

// todo - construct, destruct

int main() {
	graph Graph;

	Graph.setType(digraph);
	Graph.setDefaultNodeAttr("string", "asd");
	Graph.setDefaultNodeAttr("int", 10);
	Graph.setDefaultNodeAttr("double", 10.333);
	Graph.setDefaultNodeAttr("bool", true);

	Graph.addEdge("prvni", "druhy");

	return 0;
}