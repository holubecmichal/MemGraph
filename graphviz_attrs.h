/////////////////////////////////////////////////////////////////////////
//
// Bakalářská práce
// Vizualizace datových struktur pro verifikační nástroje
// Michael Holubec
// GNU GPLv3
//
//////////////////////////////////////////////////////////////////////////

//
// Created by Michael Holubec on 19.03.16.
//

#ifndef MEMGRAPH_GRAPHVIZ_ATTRS_H
#define MEMGRAPH_GRAPHVIZ_ATTRS_H

#include <string>
#include "node.h"

namespace memgraph {
	class GraphvizAttrs {
	public:
		static const char *NODE_ATTR_COLOR;
		static const char *NODE_ATTR_COLORSCHEME;
		static const char *NODE_ATTR_COMMENT;
		static const char *NODE_ATTR_DISTORTION;
		static const char *NODE_ATTR_FILLCOLOR;
		static const char *NODE_ATTR_FIXEDSIZE;
		static const char *NODE_ATTR_FONTCOLOR;
		static const char *NODE_ATTR_FONTNAME;
		static const char *NODE_ATTR_FONTSIZE;
		static const char *NODE_ATTR_GROUP;
		static const char *NODE_ATTR_HEIGHT;
		static const char *NODE_ATTR_ID;
		static const char *NODE_ATTR_IMAGE;
		static const char *NODE_ATTR_IMAGESCALE;
		static const char *NODE_ATTR_LABEL;
		static const char *NODE_ATTR_LABELLOC;
		static const char *NODE_ATTR_LAYER;
		static const char *NODE_ATTR_MARGIN;
		static const char *NODE_ATTR_NOJUSTIFY;
		static const char *NODE_ATTR_ORIENTATION;
		static const char *NODE_ATTR_PENWIDTH;
		static const char *NODE_ATTR_PERIPHERIES;
		static const char *NODE_ATTR_REGULAR;
		static const char *NODE_ATTR_SAMPLEPOINTS;
		static const char *NODE_ATTR_SHAPE;
		static const char *NODE_ATTR_SIDES;
		static const char *NODE_ATTR_SKEW;
		static const char *NODE_ATTR_STYLE;
		static const char *NODE_ATTR_TARGET;
		static const char *NODE_ATTR_TOOLTIP;
		static const char *NODE_ATTR_URL;
		static const char *NODE_ATTR_WIDTH;

		static const char *EDGE_ATTR_ARROWHEAD;
		static const char *EDGE_ATTR_ARROWSIZE;
		static const char *EDGE_ATTR_ARROWTAIL;
		static const char *EDGE_ATTR_COLOR;
		static const char *EDGE_ATTR_COLORSCHEME;
		static const char *EDGE_ATTR_COMMENT;
		static const char *EDGE_ATTR_CONSTRAINT;
		static const char *EDGE_ATTR_DECORATE;
		static const char *EDGE_ATTR_DIR;
		static const char *EDGE_ATTR_EDGEURL;
		static const char *EDGE_ATTR_EDGEHREF;
		static const char *EDGE_ATTR_EDGETARGET;
		static const char *EDGE_ATTR_EDGETOOLTIP;
		static const char *EDGE_ATTR_FONTCOLOR;
		static const char *EDGE_ATTR_FONTNAME;
		static const char *EDGE_ATTR_FONTSIZE;
		static const char *EDGE_ATTR_HEADCLIP;
		static const char *EDGE_ATTR_HEADHREF;
		static const char *EDGE_ATTR_HEADLABEL;
		static const char *EDGE_ATTR_HEADPORT;
		static const char *EDGE_ATTR_HEADTARGET;
		static const char *EDGE_ATTR_HEADTOOLTIP;
		static const char *EDGE_ATTR_HEADURL;
		static const char *EDGE_ATTR_HREF;
		static const char *EDGE_ATTR_ID;
		static const char *EDGE_ATTR_LABEL;
		static const char *EDGE_ATTR_LABELANGLE;
		static const char *EDGE_ATTR_LABELDISTANCE;
		static const char *EDGE_ATTR_LABELFLOAT;
		static const char *EDGE_ATTR_LABELFONTCOLOR;
		static const char *EDGE_ATTR_LABELFONTNAME;
		static const char *EDGE_ATTR_LABELFONTSIZE;
		static const char *EDGE_ATTR_LABELHREF;
		static const char *EDGE_ATTR_LABELURL;
		static const char *EDGE_ATTR_LABELTARGET;
		static const char *EDGE_ATTR_LABELTOOLTIP;
		static const char *EDGE_ATTR_LAYER;
		static const char *EDGE_ATTR_LHEAD;
		static const char *EDGE_ATTR_LTAIL;
		static const char *EDGE_ATTR_MINLEN;
		static const char *EDGE_ATTR_PENWIDTH;
		static const char *EDGE_ATTR_SAMEHEAD;
		static const char *EDGE_ATTR_SAMETAIL;
		static const char *EDGE_ATTR_STYLE;
		static const char *EDGE_ATTR_TAILCLIP;
		static const char *EDGE_ATTR_TAILHREF;
		static const char *EDGE_ATTR_TAILLABEL;
		static const char *EDGE_ATTR_TAILPORT;
		static const char *EDGE_ATTR_TAILTARGET;
		static const char *EDGE_ATTR_TAILTOOLTIP;
		static const char *EDGE_ATTR_TAILURL;
		static const char *EDGE_ATTR_TARGET;
		static const char *EDGE_ATTR_TOOLTIP;
		static const char *EDGE_ATTR_WEIGHT;

		static const char *GRAPH_ATTR_ASPECT;
		static const char *GRAPH_ATTR_BGCOLOR;
		static const char *GRAPH_ATTR_CENTER;
		static const char *GRAPH_ATTR_CLUSTERRANK;
		static const char *GRAPH_ATTR_COLOR;
		static const char *GRAPH_ATTR_COLORSCHEME;
		static const char *GRAPH_ATTR_COMMENT;
		static const char *GRAPH_ATTR_COMPOUND;
		static const char *GRAPH_ATTR_CONCENTRATE;
		static const char *GRAPH_ATTR_DPI;
		static const char *GRAPH_ATTR_FILLCOLOR;
		static const char *GRAPH_ATTR_FONTCOLOR;
		static const char *GRAPH_ATTR_FONTNAME;
		static const char *GRAPH_ATTR_FONTNAMES;
		static const char *GRAPH_ATTR_FONTPATH;
		static const char *GRAPH_ATTR_FONTSIZE;
		static const char *GRAPH_ATTR_ID;
		static const char *GRAPH_ATTR_LABEL;
		static const char *GRAPH_ATTR_LABELJUST;
		static const char *GRAPH_ATTR_LABELLOC;
		static const char *GRAPH_ATTR_LANDSCAPE;
		static const char *GRAPH_ATTR_LAYERS;
		static const char *GRAPH_ATTR_LAYERSEP;
		static const char *GRAPH_ATTR_MARGIN;
		static const char *GRAPH_ATTR_MINDIST;
		static const char *GRAPH_ATTR_NODESEP;
		static const char *GRAPH_ATTR_NOJUSTIFY;
		static const char *GRAPH_ATTR_ORDERING;
		static const char *GRAPH_ATTR_ORIENTATION;
		static const char *GRAPH_ATTR_OUTPUTORDER;
		static const char *GRAPH_ATTR_PAGE;
		static const char *GRAPH_ATTR_PAGEDIR;
		static const char *GRAPH_ATTR_PENCOLOR;
		static const char *GRAPH_ATTR_PENWIDTH;
		static const char *GRAPH_ATTR_PERIPHERIES;
		static const char *GRAPH_ATTR_RANK;
		static const char *GRAPH_ATTR_RANKDIR;
		static const char *GRAPH_ATTR_RANKSEP;
		static const char *GRAPH_ATTR_RATIO;
		static const char *GRAPH_ATTR_ROTATE;
		static const char *GRAPH_ATTR_SAMPLEPOINTS;
		static const char *GRAPH_ATTR_SEARCHSIZE;
		static const char *GRAPH_ATTR_SIZE;
		static const char *GRAPH_ATTR_SPLINES;
		static const char *GRAPH_ATTR_STYLE;
		static const char *GRAPH_ATTR_STYLESHEET;
		static const char *GRAPH_ATTR_TARGET;
		static const char *GRAPH_ATTR_TOOLTIP;
		static const char *GRAPH_ATTR_TRUECOLOR;
		static const char *GRAPH_ATTR_VIEWPORT;
		static const char *GRAPH_ATTR_URL;

		static string_vector node_attrs;
		static string_vector edge_attrs;
		static string_vector graph_attrs;

	};
}


#endif //MEMGRAPH_GRAPHVIZ_ATTRS_H
