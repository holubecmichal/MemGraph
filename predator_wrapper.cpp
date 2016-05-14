//
// Created by Michael Holubec on 12.04.16.
//

#include <regex>
#include "predator_wrapper.h"

void PredatorWrapper::plotOffset(bool status) {
	if(status == OFF) {
		for(auto i : getAllEdges()) {
			i->setAttr("label", "");
		}
	}
}

edges_vect PredatorWrapper::getAllEdges() {
	edges_vect edges;

	walkEdgesRecursively(plotter->graph, &edges);

	return edges;
}

void PredatorWrapper::walkEdgesRecursively(GraphComponent *graph, edges_vect *edges) {
	// nejdriv ulozim vsechny hrany teto grafove komponenty
	for(auto edge : *graph->getEdges()) {
		edges->push_back(edge);
	}

	// a ted ulozim hrany vsechn svych podgrafu
	for(auto i : *graph->getSubgraphs()) {
		Subgraph *subgraph = i.second;

		walkEdgesRecursively(subgraph, edges);
	}
}

bool PredatorWrapper::isSLS(Subgraph *sls) {
	// vytahnu potrebne atributy
	Attribute *attr_label = sls->getAttr(GraphvizAttrs::GRAPH_ATTR_LABEL);
	Attribute *attr_color = sls->getAttr(GraphvizAttrs::GRAPH_ATTR_COLOR);
	Attribute *attr_style = sls->getAttr(GraphvizAttrs::GRAPH_ATTR_STYLE);
	Attribute *attr_fontcolor = sls->getAttr(GraphvizAttrs::GRAPH_ATTR_FONTCOLOR);

	// nastavim re vyrazu ktery se objevuje v SLS labelech
	std::regex re(".*SLS \\d+\\+,.+");

	// kontroluju, zda se atributy shoduji s atributy klasickeho SLS
	if(attr_label && attr_color && attr_style && attr_fontcolor) {
		if( attr_color->getValue() == "red"     &&
			attr_style->getValue() == "dashed"  &&
		    attr_fontcolor->getValue() == "red" &&
		    std::regex_match(attr_label->getValue(), re))
		{

			return true;

		}
	}

	return false;
}

bool PredatorWrapper::isDLS(Subgraph *dls) {
	// vytahnu potrebne atributy
	Attribute *attr_label = dls->getAttr(GraphvizAttrs::GRAPH_ATTR_LABEL);
	Attribute *attr_color = dls->getAttr(GraphvizAttrs::GRAPH_ATTR_COLOR);
	Attribute *attr_style = dls->getAttr(GraphvizAttrs::GRAPH_ATTR_STYLE);
	Attribute *attr_fontcolor = dls->getAttr(GraphvizAttrs::GRAPH_ATTR_FONTCOLOR);

	// nastavim re vyrazu ktery se objevuje v SLS labelech
	std::regex re(".*DLS \\d+\\+,.+");

	// kontroluju, zda se atributy shoduji s atributy klasickeho DLS
	if(attr_label && attr_color && attr_style && attr_fontcolor) {
		if( attr_color->getValue()     == "orange" &&
		    attr_style->getValue()     == "dashed" &&
		    attr_fontcolor->getValue() == "orange" &&
		    std::regex_match(attr_label->getValue(), re))
		{

			return true;

		}
	}

	return false;
}

subgraphs_vect PredatorWrapper::getAllSubgraphs() {
	subgraphs_vect subgraphs;

	walkSubgraphsRecursively(plotter->graph, &subgraphs);

	return subgraphs;
}

void PredatorWrapper::walkSubgraphsRecursively(GraphComponent *graph, subgraphs_vect *subgraphs) {
	for(auto i : *graph->getSubgraphs()) {
		Subgraph *subgraph = i.second;

		subgraphs->push_back(subgraph);

		if(subgraph->getSubgraphs()->size() > 0) {
			walkSubgraphsRecursively(subgraph, subgraphs);
		}
	}
}

void PredatorWrapper::walkNodesRecursively(GraphComponent *graph, nodes_vect *nodes) {
	for(auto i : *graph->getNodes()) {
		Node *node = i.second;

		nodes->push_back(node);
	}

	for(auto j : *graph->getSubgraphs()) {
		Subgraph *subgraph = j.second;

		walkNodesRecursively(subgraph, nodes);
	}
}

nodes_vect PredatorWrapper::getAllNodes() {
	nodes_vect nodes;

	walkNodesRecursively(plotter->graph, &nodes);

	return nodes;
}

edges_vect PredatorWrapper::getHasValuesEdges() {
	edges_vect edges;

	for(auto edge : getAllEdges()) {
		if(isHasValueEdge(edge)) {
			edges.push_back(edge);
		}
	}

	return edges;
}

bool PredatorWrapper::isHasValueEdge(Edge *edge) {
	// vytahnu potrebne atributy
	Attribute *attr_color = edge->getAttr(GraphvizAttrs::EDGE_ATTR_COLOR);
	Attribute *attr_fontcolor = edge->getAttr(GraphvizAttrs::EDGE_ATTR_FONTCOLOR);

	// kontroluju, zda se vlastnosti shoduji s hasValue vlastnostmi
	if(attr_color && attr_fontcolor) {
		if(attr_color->getValue() == "blue" && attr_fontcolor->getValue() == "blue") {

			return true;

		}
	}

	return false;
}

bool PredatorWrapper::isPointsToEdge(Edge *edge) {
	Node *from = edge->getFrom();
	Node *to = edge->getTo();

	Attribute *from_shape = from->getAttr(GraphvizAttrs::NODE_ATTR_SHAPE);
	Attribute *to_shape = to->getAttr(GraphvizAttrs::NODE_ATTR_SHAPE);

	if(from_shape && to_shape) {
		if( from_shape->getValue() == "ellipse" && to_shape->getValue() == "box") {
			return true;
		}
	}

	return false;
}

edges_vect PredatorWrapper::getPointsToEdges() {
	edges_vect edges;

	for(auto edge : getAllEdges()) {
		if(isPointsToEdge(edge)) {
			edges.push_back(edge);
		}
	}

	return edges;
}

bool PredatorWrapper::isValuesNode(Node *node) {
	Attribute *attr_shape = node->getAttr(GraphvizAttrs::NODE_ATTR_SHAPE);

	if(attr_shape) {
		if(attr_shape->getValue() == "ellipse") {
			return true;
		}
	}

	return false;
}

nodes_vect PredatorWrapper::getValuesNodes() {
	nodes_vect nodes;

	for(auto node : getAllNodes()) {
		if(isValuesNode(node)) {
			nodes.push_back(node);
		}
	}

	return nodes;
}

subgraphs_vect PredatorWrapper::getSLSSubgraphs() {
	subgraphs_vect subgraphs;

	for(auto i : getAllSubgraphs()) {
		if(isSLS(i)) {
			subgraphs.push_back(i);
		}
	}

	return subgraphs;
}

subgraphs_vect PredatorWrapper::getDLSSubgraphs() {
	subgraphs_vect subgraphs;

	for(auto i : getAllSubgraphs()) {
		if(isDLS(i)) {
			subgraphs.push_back(i);
		}
	}

	return subgraphs;
}

void PredatorWrapper::abstractValues(int lvl) {
	for(auto node : getValuesNodes()) {
		// pro vsechny Value vrcholy zmenim jejich vlastnosti podle pozadovaneho level-of-details
		if(lvl == LVL_1) {
			Attribute *attr_label = node->getAttr(GraphvizAttrs::NODE_ATTR_LABEL);

			if(attr_label) {
				attr_label->setValue("");
			}
		} else if(lvl == LVL_2) {
			Attribute *attr_label = node->getAttr(GraphvizAttrs::NODE_ATTR_LABEL);
			Attribute *attr_shape = node->getAttr(GraphvizAttrs::NODE_ATTR_SHAPE);

			if(attr_label) {
				attr_label->setValue("");
			}
			if(attr_shape) {
				attr_shape->setValue("point");
			}
		}
	}
}

void PredatorWrapper::abstractSLS(int lvl) {
	for(auto subgraph : getSLSSubgraphs()) {
		Node *root_node = NULL;
		nodes_vect others_nodes;
		edges_vect root_edges;
		edges_vect nodes_edges;

		// nactu vsechny "TO" vrcholy
		for(auto edge : *subgraph->getEdges()) {
			// nastavim hlavni vrchol - ten co nese label celeho SLS
			if(root_node == NULL) {
				root_node = edge->getFrom();
			}

			// ostatni vrcholy SLS (.next, .data, ...)
			others_nodes.push_back(edge->getTo());
		}

		// nactu hrany
		for(auto edge : getAllEdges()) {
			// ulozim hranu, ktera vede z hlavniho vrcholu SLS
			if(edge->getFrom() == root_node) {
				root_edges.push_back(edge);
			}

			// ulozim vsechny hrany, ktere vychazi z daneho vrchlou
			for(auto node : others_nodes) {
				if(edge->getFrom() == node) {
					nodes_edges.push_back(edge);
				}
			}
		}

		// zkontroluju, jestli je mozne zmenit vlastnosti SLS
		// je mozne zmenit jen pokud na ostatni vrcholy nevedou zadne jine hrany krome te z root vrcholu
		for(auto root_edge : root_edges) {
			for(auto node_edge : nodes_edges) {
				if(root_edge->getTo() == node_edge->getFrom()) {
					Node *node_to_remove = node_edge->getFrom();
					Edge *root_edge_to_remove = root_edge;

					for(auto edge : getAllEdges()) {
						// neni mozne zmenit vlastnosti, koncim
						if(edge != root_edge_to_remove && edge->getTo() == node_to_remove) return;
					}
				}
			}
		}

		if(lvl == LVL_1 || lvl == LVL_2) {
			// prochazim vsechny hrany, ktere vychazi z root vrcholu
			for(auto root_edge : root_edges) {
				// prochazim vsechny hrany, ktere vychazi z ostatnich vrcholu podgrafu
				for(auto node_edge : nodes_edges) {
					// najdu vrchol, ktery se bude odstranovat
					if(root_edge->getTo() == node_edge->getFrom()) {
						// vrchol k odstraneni
						Node *node_to_remove = node_edge->getFrom();
						// hrana k odstraneni vedouci od vrcholu
						Edge *edge_to_remove = node_edge;
						// hrana k odstraneni vedouci od root vrcholu
						Edge *root_edge_to_remove = root_edge;

						// vytvorime novou hranu, ktera bude spojovat root vrchol s vrcholem, na ktery vedla hrana z vrcholu typu .next, .data, ...
						Edge *new_edge = plotter->graph->addEdge(root_edge->getFrom(), node_edge->getTo());

						// nastavime stejne atributy hrany
						for(auto attr : *node_edge->getAttrs()) {
							new_edge->setAttr(attr.first.c_str(), attr.second);
						}

						// nastaveni dodatecnych atributu
						new_edge->setAttr("label", node_to_remove->getAttr("label"));
						new_edge->setAttr("fontcolor", node_to_remove->getAttr("fontcolor"));

						// odstraneni vrcholu ze struktury grafu
						node_to_remove->remove();
						// odstraneni hrany ze struktury grafu
						edge_to_remove->remove();
						// odstraneni hrany vedouci z root vrcholu ze struktury grafu
						root_edge_to_remove->remove();
					}
				}
			}

			// pri level-2 donastaveni nekterych dodtacnych atributu
			if (lvl == LVL_2) {
				for(auto attr : *subgraph->getAttrs()) {
					attr.second->remove();
				}

				subgraph->setAttr("label","");
				subgraph->setAttr("color","white");

				if(root_node) {
					root_node->setAttr("shape","triangle");
					root_node->setAttr("label","");
				}
			}
		}
	}
}

// level of detail

void PredatorWrapper::abstractDLS(int lvl) {

	// stejne jako v pripade SLS, jen zmenene nektere atributy

	for(auto subgraph : getDLSSubgraphs()) {
		Node *root_node = NULL;
		nodes_vect others_nodes;
		edges_vect root_edges;
		edges_vect nodes_edges;

		for(auto edge : *subgraph->getEdges()) {
			if(root_node == NULL) {
				root_node = edge->getFrom();
			}

			others_nodes.push_back(edge->getTo());
		}

		for(auto edge : getAllEdges()) {
			if(edge->getFrom() == root_node) {
				root_edges.push_back(edge);
			}

			for(auto node : others_nodes) {
				if(edge->getFrom() == node) {
					nodes_edges.push_back(edge);
				}
			}
		}

		// check if abstract is possible
		for(auto root_edge : root_edges) {
			for(auto node_edge : nodes_edges) {
				if(root_edge->getTo() == node_edge->getFrom()) {
					Node *node_to_remove = node_edge->getFrom();
					Edge *root_edge_to_remove = root_edge;

					for(auto edge : getAllEdges()) {
						// abstract is impossible
						if(edge != root_edge_to_remove && edge->getTo() == node_to_remove) return;
					}
				}
			}
		}

		if(lvl == LVL_1 || lvl == LVL_2) {
			for(auto root_edge : root_edges) {
				for(auto node_edge : nodes_edges) {
					if(root_edge->getTo() == node_edge->getFrom()) {
						Node *node_to_remove = node_edge->getFrom();
						Edge *edge_to_remove = node_edge;
						Edge *root_edge_to_remove = root_edge;
						bool do_continue = false;

						for(auto edge : getAllEdges()) {
							if(edge != root_edge_to_remove && edge->getTo() == node_to_remove) do_continue = true;
						}

						if(do_continue) continue;

						Edge *new_edge = plotter->graph->addEdge(root_edge->getFrom(), node_edge->getTo());

						for(auto attr : *node_edge->getAttrs()) {
							new_edge->setAttr(attr.first.c_str(), attr.second);
						}

						new_edge->setAttr("label", node_to_remove->getAttr("label"));
						new_edge->setAttr("fontcolor", node_to_remove->getAttr("fontcolor"));

						node_to_remove->remove();
						edge_to_remove->remove();
						root_edge_to_remove->remove();
					}
				}
			}

			if (lvl == LVL_2) {
				for(auto attr : *subgraph->getAttrs()) {
					attr.second->remove();
				}

				subgraph->setAttr("label","");
				subgraph->setAttr("color","white");

				if(root_node) {
					root_node->setAttr("shape","diamond");
					root_node->setAttr("label","");
				}
			}
		}
	}
}
