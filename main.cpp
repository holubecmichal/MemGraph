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
	attributes *attrs;
	edge *Edge;
	subgraph *Subgraph;

	Subgraph = Graph.addSubgraph("cluster_0");
	Subgraph->setAttr("label", "Subgraph A");
	Subgraph->addEdge("a", "b");
	Subgraph->addEdge("b", "c");
	Subgraph->addEdge("c", "d");

	Subgraph = Graph.addSubgraph("cluster_1");
	Subgraph->setAttr("label", "Subgraph B");
	Subgraph->addEdge("a", "f");
	Subgraph->addEdge("f", "c");

	return 0;
}