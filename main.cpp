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

using namespace std;

	// todo implementace graphvizu
	// todo attrs prepsat na asociativni pole?
	// todo vsechna const char * predelat na string

typedef struct mynode_s {
	Agrec_t     h;
	int         count;
} mynode_t;

int main() {
//	GraphvizPlotter *plotter = new GraphvizPlotter();
//	Graph *graph = plotter->graph;
//
//	plotter->setOutputFormat(GraphvizPlotter::PNG);
//	plotter->setOutputPath("/Users/Michal/FIT/Bachelor/");
//	plotter->setOutputName("out");
//
//	Examples::tonyballantyne_com_51(graph);
//	Examples::predator_1(graph);
//	Examples::dotman_27(graph);
//
//	Attributes attrs;
//	attrs["asd"] = "aasdasd";
//	attrs["int"] = 10;
//	attrs["bool"] = true;
//
//	attrs["int"] = 50;
//	attrs["int"] = "asdadsasdadasdasda";
//
//	cout << plotter->getDot() << endl;
//	plotter->plot();

	Graph graph;
	GraphComponent::enable_warnings = false;

	GVC_t *gvc;
	Agraph_t *g;
	gvc = gvContext();

	g = agmemread(Examples::dotman_27_dot());

	// todo graph attrs
	// todo graph nodes
	// todo graph edges

	for(Agraph_t *subg = agfstsubg(g); subg; subg = agnxtsubg(subg)) {
		// todo subgraph attrs

		// postup vytazeni atributu a hodnoty
//		Agsym_t *sym = agnxtattr(g,AGNODE,0);
//		while (sym != NULL) {
//			printf("%s = %s\n",sym->name,sym->defval);
//			sym = agnxtattr(g,AGNODE,sym);
//		}

		Subgraph *subgraph = graph.addSubgraph(agnameof(subg));
		cout << agnameof(subg) << endl;

		Agnode_t *from_node = agfstnode(subg);
		while (from_node != NULL) {
			Node *node = subgraph->addNode(agnameof(from_node));
			cout << agnameof(from_node) << endl;

			for( auto i : GraphvizAttrs::node_attrs) {
				char *value = agget(from_node,(char*)i.c_str());

				if(value != NULL && strlen(value) > 0) {
					std::string str_value = value;

					if(str_value.compare("\\N") != 0) {
						cout << i << " " << value << endl;
						node->setAttr(i.c_str(), value);
					}
				}
			}

			Agedge_t *e = agfstout(subg, from_node);
			while(e != NULL) {
				Agnode_t *to_node = e->node;

				Edge *edge = subgraph->addEdge(agnameof(from_node), agnameof(to_node));
				cout << agnameof(from_node) << " -> " << agnameof(to_node) << endl;

				for( auto i : GraphvizAttrs::edge_attrs) {
					char *value = agget(e,(char*)i.c_str());

					if(value != NULL && strlen(value) > 0) {
						cout << i << " " << value << endl;
						edge->setAttr(i.c_str(), value);
					}
				}

				e = agnxtout(subg, e);
			}

			from_node = agnxtnode(subg, from_node);
		}
	}

	// todo moznost vypnout warnig graphvizu
	// todo vizualni styly
	// todo da se graphvi nastavit, aby mu sel nastavit minimalni uhel hran prekreslenych pres sebe ?
	// todo mrknout na predator adt - nastrankach pana Peringera
	// todo mrknout na ddd - debuger, ktery dokaze znazornit zmeny -> pro isomorfismus
	// todo pormyslet pouziti pro vykresleni adt v normalnich programech
	// todo verifit - smg 3

	return 0;
}