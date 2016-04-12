//
// Created by Michael Holubec on 12.04.16.
//

#include <regex>
#include "Predator.h"

void Predator::pointsToOffset(bool status) {
	if(status == OFF) {
		for(auto edge : getAllEdges()) {
			Attribute *attr_label = edge->getAttr(GraphvizAttrs::EDGE_ATTR_LABEL);

			if(!attr_label) continue;

			Attribute *attr_fontcolor = edge->getAttr(GraphvizAttrs::EDGE_ATTR_FONTCOLOR);
			Attribute *attr_color = edge->getAttr(GraphvizAttrs::EDGE_ATTR_COLOR);
			std::regex re(".\\[\\+?\\d+\\].");

			if(attr_label && attr_fontcolor && attr_color) {
				if( attr_color->getValue()     == "black" &&
					attr_fontcolor->getValue() == "black" &&
					std::regex_match(attr_label->getValue(), re))
				{

					attr_label->setValue("");

				}
			}
		}
	}
}

edges_vect Predator::getAllEdges() {
	Graph *graph = plotter->graph;
	edges_vect edges;

	for(auto i : *graph->getEdges()) {
		edges.push_back(i);
	}

	subgraphsEdgesRecursively(graph->getSubgraphs(), &edges);

	return edges;
}

void Predator::subgraphsEdgesRecursively(subgraphs_map *subgraphs, edges_vect *edges) {
	for(auto map : *subgraphs) {
		Subgraph *subgraph = map.second;

		for(auto edge : *subgraph->getEdges()) {
			edges->push_back(edge);
		}

		if(subgraph->getSubgraphs()->size()) {
			subgraphsEdgesRecursively(subgraph->getSubgraphs(), edges);
		}
	}
}

subgraphs_vect Predator::getAllSLS() {
	subgraphs_vect sls;

	subgraphsSLSRecursively(plotter->graph->getSubgraphs(), &sls);

	return sls;
}

void Predator::subgraphsSLSRecursively(subgraphs_map *subgraphs, subgraphs_vect *sls) {

	for(auto i : *subgraphs) {
		Subgraph *subgraph = i.second;

		if(isSLS(subgraph)) {
			sls->push_back(subgraph);
		}

		if(subgraph->getSubgraphs()->size()) {
			subgraphsSLSRecursively(subgraph->getSubgraphs(), sls);
		}
	}

}

bool Predator::isSLS(Subgraph *sls) {
	Attribute *attr_label = sls->getAttr(GraphvizAttrs::GRAPH_ATTR_LABEL);
	Attribute *attr_color = sls->getAttr(GraphvizAttrs::GRAPH_ATTR_COLOR);
	Attribute *attr_style = sls->getAttr(GraphvizAttrs::GRAPH_ATTR_STYLE);
	Attribute *attr_fontcolor = sls->getAttr(GraphvizAttrs::GRAPH_ATTR_FONTCOLOR);

	std::regex re(".SLS \\d+\\+,.+");

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

//void Predator::rawObjectSLS(bool status) {
//	if(status == OFF) {
//		for( auto subgraph : getAllSLS()) {
//			for( auto node : *subgraph->getNodes() ) {
//
//			}
//		}
//	}
//}
