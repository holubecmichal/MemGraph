//
// Created by Michael Holubec on 02.03.16.
//

#ifndef BACHELOR_GRAPHVIZPLOTTER_H
#define BACHELOR_GRAPHVIZPLOTTER_H


#include "plotter.h"

class GraphvizPlotter : public Plotter {
private:
	const char *dotGraphHeader();
	const char *dotNodes();
	const char *getIdent();
	const char *dotNodeAttributes(Node *node);
	const char *dotAttribute(const char *name, Attribute *attr);
	const char *dotEdges();
	const char *dotEdgeAttributes(Edge *edge);

public:

	const char *getDot();
	void plot(const char *file_name);
	void setOutputFormat();
};


#endif //BACHELOR_GRAPHVIZPLOTTER_H
