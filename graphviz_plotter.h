//
// Created by Michael Holubec on 02.03.16.
//

#ifndef BACHELOR_GRAPHVIZPLOTTER_H
#define BACHELOR_GRAPHVIZPLOTTER_H


#include "plotter.h"

class GraphvizPlotter : public Plotter {
private:
	const char *print(std::string *content);
	std::string getIdent();
	const char *dotGraphHeader();
	const char *dotAttribute(const char *name, Attribute *attr);
	const char *dotNodes(nodes_map *nodes);
	const char *dotEdges(edges_vect *edges);
	const char *dotSubgraphs(subgraphs_map *subgraphs);
	const char *dotSubgraph(Subgraph *subgraph);
	template <typename T>
	const char *dotAttributes(T *element) {
		if(element->attrs.size() == 0) {
			return "";
		}

		attributes_it it = element->attrs.begin();

		std::string attributes = "[";
		while ( true ) {
			attributes += dotAttribute(it->first, it->second);

			if(++it == element->attrs.end()) {
				break;
			}

			attributes += ",";
		}
		attributes += "]";

		return attributes.c_str();
	}

public:

	const char *getDot();
	void plot(const char *file_name);
	void setOutputFormat();
};


#endif //BACHELOR_GRAPHVIZPLOTTER_H
