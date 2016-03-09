#include <iostream>
#include "attributes.h"
#include "node.h"
#include "edge.h"
#include "graph.h"
#include "plotter.h"
#include "graphviz_plotter.h"
#include <graphviz/gvc.h>

using namespace std;

int main() {
//	Graph graph;
//	Attributes *attrs;

	Edge *edge;
	Subgraph *subgraph;
	Node *node;
	GraphComponent *graphComponent;

	Plotter *plotter = new GraphvizPlotter();

	Graph *graph = plotter->graph;
	Attributes attrs;
	Attribute *attr = new Attribute("pointer", 10);

	attrs.setAttr("ahooj", "ahooj");
	attrs.setAttr("nazdar", "nazdar");
	attrs.setAttr("int", 10);

	graph->setDefaultNodeAttrs(&attrs);
	graph->setDefaultNodeAttr(attr);

//	graph->clearDefaultNodeAttrs();
	graph->setDefaultNodeAttr("ahooj", 10);

	cout << attr->getName() << endl;

//	Attributes node_attrs;
//	node_attrs.setAttr("shape","box");
//	node_attrs.setAttr("color","black");
//	node_attrs.setAttr("fontcolor","black");
//
//	Attributes graph_attrs;
//	graph_attrs.setAttr("label", "");
//	graph_attrs.setAttr("rank", "same");
//	graph_attrs.setAttr("color","black");
//	graph_attrs.setAttr("fontcolot","black");
//	graph_attrs.setAttr("bgcolor","white");
//	graph_attrs.setAttr("penwidth",1.0);
//	graph_attrs.setAttr("style","dashed");
//
//	Graph *graph = plotter->graph;
//	graph->setType(digraph);
//	// todo implementace graphvizu
//	// todo propisuji se v dotu defaultne nastavene atributy do subgraphs?
//
//	graph->setHtmlAttr("label", "<FONT POINT-SIZE=\"18\">test-0001-snapshot-0001</FONT>");
//	graph->setAttr("clusterrank", "local");
//	graph->setAttr("labelloc", "t");
//
//	graph->setDefaultNodeAttrs(node_attrs);
//
//	subgraph = graph->addSubgraph("cluster1");
//	subgraph->setGraphAttrs(graph_attrs);
//	subgraph->addNode("14")->setAttr("label", "#14 [SC_ON_HEAP, size = 8 B]");
//	subgraph->addNode("16")->setAttr("label", ".next #16");
//	subgraph->addEdge("14", "16")->setAttr("color", "black")->setAttr("fontcolor", "black")->setAttr("label","[+0]");
//
//	graph->addNode("20")->setAttr("label","CL#2335:ptr [obj = #20] field#22");
//
//	subgraph = graph->addSubgraph("cluster2");
//	subgraph->setGraphAttrs(graph_attrs);
//	subgraph->addNode("23")->setAttr("label", "#23 [SC_ON_HEAP, size = 8 B]");
//	subgraph->addNode("25")->setAttr("label", ".next #25");
//	subgraph->addEdge("23", "25")->setAttr("color", "black")->setAttr("fontcolor", "black")->setAttr("label","[+0]");
//
//	graph->clearDefaultNodeAttrs();
//
//	graph->setDefaultNodeAttr("shape","ellipse");
//	graph->setDefaultNodeAttr("penwidth","2");
//	graph->setDefaultNodeAttr("fontcolot","black");
//	graph->addNode("15")->setAttr("label","#15 [off = 0, obj = #14]");
//	graph->addNode("24")->setAttr("label","#24 [off = 0, obj = #23]");
//
//	graph->clearDefaultNodeAttrs();
//
//	graph->addNode("lonely3")->setAttr("shape","plaintext")->setAttr("fontcolor","blue")->setAttr("label","NULL");
//
//	graph->setDefaultEdgeAttr("color","blue");
//	graph->setDefaultEdgeAttr("fontcolor","blue");
//
//	graph->addEdge("16", "lonely3");
//	graph->addEdge("20", "24");
//	graph->addEdge("25", "15");
//
//	graph->setDefaultEdgeAttr("fontcolor", "black");
//	graph->setDefaultEdgeAttr("label", "[+0]");
//
//	graph->addEdge("24", "23");
//	graph->addEdge("15", "14");


//	digraph "test-0001-snapshot-0001" {
//		label=<<FONT POINT-SIZE="18">test-0001-snapshot-0001</FONT>>;
//		clusterrank=local;
//		labelloc=t;
//		subgraph "cluster1" {
//			rank=same;
//			label="";
//			color=black;
//			fontcolor=black;
//			bgcolor=white;
//			penwidth=1.0;
//			style=dashed;
//			"14" [shape=box, color=black, fontcolor=black, label="#14 [SC_ON_HEAP, size = 8 B]"];
//			"16" [shape=box, color=black, fontcolor=black, label=".next #16"];
//			"14" -> "16" [color=black, fontcolor=black, label="[+0]"];
//		}
//		"20" [shape=box, color=blue, fontcolor=blue, label="CL#2335:ptr [obj = #20] field#22"];
//		subgraph "cluster2" {
//			rank=same;
//			label="";
//			color=black;
//			fontcolor=black;
//			bgcolor=white;
//			penwidth=1.0;
//			style=dashed;
//			"23" [shape=box, color=black, fontcolor=black, label="#23 [SC_ON_HEAP, size = 8 B]"];
//			"25" [shape=box, color=black, fontcolor=black, label=".next #25"];
//			"23" -> "25" [color=black, fontcolor=black, label="[+0]"];
//		}
//		"15" [shape=ellipse, penwidth=2, fontcolor=black, label="#15 [off = 0, obj = #14]"];
//		"24" [shape=ellipse, penwidth=2, fontcolor=black, label="#24 [off = 0, obj = #23]"];
//		"lonely3" [shape=plaintext, fontcolor=blue, label="NULL"];
//		"16" -> "lonely3" [color=blue, fontcolor=blue];
//		"20" -> "24" [color=blue, fontcolor=blue];
//		"25" -> "15" [color=blue, fontcolor=blue];
//		"24" -> "23" [color=black, fontcolor=black, label="[+0]"];
//		"15" -> "14" [color=black, fontcolor=black, label="[+0]"];
//	}


//	cout << plotter->getDot() << endl;
//
//
//	GVC_t *gvc;
//	Agraph_t *g;
//	gvc = gvContext();
//
//	g = agmemread (plotter->getDot().c_str());
//
//	gvLayout(gvc, g, "dot");
//	//gvRender(gvc, g, "dot", stdout);
//	gvRenderFilename (gvc, g, "png", "/Users/Michal/FIT/Bachelor/out.png");
//	gvFreeLayout(gvc, g);
//	agclose(g);
//
//	return (gvFreeContext(gvc));

	return 0;
}