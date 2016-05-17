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

#include "graphviz_attrs.h"

namespace memgraph {
	const char *GraphvizAttrs::NODE_ATTR_COLOR = "color";
	const char *GraphvizAttrs::NODE_ATTR_COLORSCHEME = "colorscheme";
	const char *GraphvizAttrs::NODE_ATTR_COMMENT = "comment";
	const char *GraphvizAttrs::NODE_ATTR_DISTORTION = "distortion";
	const char *GraphvizAttrs::NODE_ATTR_FILLCOLOR = "fillcolor";
	const char *GraphvizAttrs::NODE_ATTR_FIXEDSIZE = "fixedsize";
	const char *GraphvizAttrs::NODE_ATTR_FONTCOLOR = "fontcolor";
	const char *GraphvizAttrs::NODE_ATTR_FONTNAME = "fontname";
	const char *GraphvizAttrs::NODE_ATTR_FONTSIZE = "fontsize";
	const char *GraphvizAttrs::NODE_ATTR_GROUP = "group";
	const char *GraphvizAttrs::NODE_ATTR_HEIGHT = "height";
	const char *GraphvizAttrs::NODE_ATTR_ID = "id";
	const char *GraphvizAttrs::NODE_ATTR_IMAGE = "image";
	const char *GraphvizAttrs::NODE_ATTR_IMAGESCALE = "imagescale";
	const char *GraphvizAttrs::NODE_ATTR_LABEL = "label";
	const char *GraphvizAttrs::NODE_ATTR_LABELLOC = "labelloc";
	const char *GraphvizAttrs::NODE_ATTR_LAYER = "layer";
	const char *GraphvizAttrs::NODE_ATTR_MARGIN = "margin";
	const char *GraphvizAttrs::NODE_ATTR_NOJUSTIFY = "nojustify";
	const char *GraphvizAttrs::NODE_ATTR_ORIENTATION = "orientation";
	const char *GraphvizAttrs::NODE_ATTR_PENWIDTH = "penwidth";
	const char *GraphvizAttrs::NODE_ATTR_PERIPHERIES = "peripheries";
	const char *GraphvizAttrs::NODE_ATTR_REGULAR = "regular";
	const char *GraphvizAttrs::NODE_ATTR_SAMPLEPOINTS = "samplepoints";
	const char *GraphvizAttrs::NODE_ATTR_SHAPE = "shape";
	const char *GraphvizAttrs::NODE_ATTR_SIDES = "sides";
	const char *GraphvizAttrs::NODE_ATTR_SKEW = "skew";
	const char *GraphvizAttrs::NODE_ATTR_STYLE = "style";
	const char *GraphvizAttrs::NODE_ATTR_TARGET = "target";
	const char *GraphvizAttrs::NODE_ATTR_TOOLTIP = "tooltip";
	const char *GraphvizAttrs::NODE_ATTR_URL = "URL";
	const char *GraphvizAttrs::NODE_ATTR_WIDTH = "width";

	const char *GraphvizAttrs::EDGE_ATTR_ARROWHEAD = "arrowhead";
	const char *GraphvizAttrs::EDGE_ATTR_ARROWSIZE = "arrowsize";
	const char *GraphvizAttrs::EDGE_ATTR_ARROWTAIL = "arrowtail";
	const char *GraphvizAttrs::EDGE_ATTR_COLOR = "color";
	const char *GraphvizAttrs::EDGE_ATTR_COLORSCHEME = "colorscheme";
	const char *GraphvizAttrs::EDGE_ATTR_COMMENT = "comment";
	const char *GraphvizAttrs::EDGE_ATTR_CONSTRAINT = "constraint";
	const char *GraphvizAttrs::EDGE_ATTR_DECORATE = "decorate";
	const char *GraphvizAttrs::EDGE_ATTR_DIR = "dir";
	const char *GraphvizAttrs::EDGE_ATTR_EDGEURL = "edgeURL";
	const char *GraphvizAttrs::EDGE_ATTR_EDGEHREF = "edgehref";
	const char *GraphvizAttrs::EDGE_ATTR_EDGETARGET = "edgetarget";
	const char *GraphvizAttrs::EDGE_ATTR_EDGETOOLTIP = "edgetooltip";
	const char *GraphvizAttrs::EDGE_ATTR_FONTCOLOR = "fontcolor";
	const char *GraphvizAttrs::EDGE_ATTR_FONTNAME = "fontname";
	const char *GraphvizAttrs::EDGE_ATTR_FONTSIZE = "fontsize";
	const char *GraphvizAttrs::EDGE_ATTR_HEADCLIP = "headclip";
	const char *GraphvizAttrs::EDGE_ATTR_HEADHREF = "headhref";
	const char *GraphvizAttrs::EDGE_ATTR_HEADLABEL = "headlabel";
	const char *GraphvizAttrs::EDGE_ATTR_HEADPORT = "headport";
	const char *GraphvizAttrs::EDGE_ATTR_HEADTARGET = "headtarget";
	const char *GraphvizAttrs::EDGE_ATTR_HEADTOOLTIP = "headtooltip";
	const char *GraphvizAttrs::EDGE_ATTR_HEADURL = "headURL";
	const char *GraphvizAttrs::EDGE_ATTR_HREF = "href";
	const char *GraphvizAttrs::EDGE_ATTR_ID = "id";
	const char *GraphvizAttrs::EDGE_ATTR_LABEL = "label";
	const char *GraphvizAttrs::EDGE_ATTR_LABELANGLE = "labelangle";
	const char *GraphvizAttrs::EDGE_ATTR_LABELDISTANCE = "labeldistance";
	const char *GraphvizAttrs::EDGE_ATTR_LABELFLOAT = "labelfloat";
	const char *GraphvizAttrs::EDGE_ATTR_LABELFONTCOLOR = "labelfontcolor";
	const char *GraphvizAttrs::EDGE_ATTR_LABELFONTNAME = "labelfontname";
	const char *GraphvizAttrs::EDGE_ATTR_LABELFONTSIZE = "labelfontsize";
	const char *GraphvizAttrs::EDGE_ATTR_LABELHREF = "labelhref";
	const char *GraphvizAttrs::EDGE_ATTR_LABELURL = "labelURL";
	const char *GraphvizAttrs::EDGE_ATTR_LABELTARGET = "labeltarget";
	const char *GraphvizAttrs::EDGE_ATTR_LABELTOOLTIP = "labeltooltip";
	const char *GraphvizAttrs::EDGE_ATTR_LAYER = "layer";
	const char *GraphvizAttrs::EDGE_ATTR_LHEAD = "lhead";
	const char *GraphvizAttrs::EDGE_ATTR_LTAIL = "ltail";
	const char *GraphvizAttrs::EDGE_ATTR_MINLEN = "minlen";
	const char *GraphvizAttrs::EDGE_ATTR_PENWIDTH = "penwidth";
	const char *GraphvizAttrs::EDGE_ATTR_SAMEHEAD = "samehead";
	const char *GraphvizAttrs::EDGE_ATTR_SAMETAIL = "sametail";
	const char *GraphvizAttrs::EDGE_ATTR_STYLE = "style";
	const char *GraphvizAttrs::EDGE_ATTR_TAILCLIP = "tailclip";
	const char *GraphvizAttrs::EDGE_ATTR_TAILHREF = "tailhref";
	const char *GraphvizAttrs::EDGE_ATTR_TAILLABEL = "taillabel";
	const char *GraphvizAttrs::EDGE_ATTR_TAILPORT = "tailport";
	const char *GraphvizAttrs::EDGE_ATTR_TAILTARGET = "tailtarget";
	const char *GraphvizAttrs::EDGE_ATTR_TAILTOOLTIP = "tailtooltip";
	const char *GraphvizAttrs::EDGE_ATTR_TAILURL = "tailURL";
	const char *GraphvizAttrs::EDGE_ATTR_TARGET = "target";
	const char *GraphvizAttrs::EDGE_ATTR_TOOLTIP = "tooltip";
	const char *GraphvizAttrs::EDGE_ATTR_WEIGHT = "weight";

	const char *GraphvizAttrs::GRAPH_ATTR_ASPECT = "aspect";
	const char *GraphvizAttrs::GRAPH_ATTR_BGCOLOR = "bgcolor";
	const char *GraphvizAttrs::GRAPH_ATTR_CENTER = "center";
	const char *GraphvizAttrs::GRAPH_ATTR_CLUSTERRANK = "clusterrank";
	const char *GraphvizAttrs::GRAPH_ATTR_COLOR = "color";
	const char *GraphvizAttrs::GRAPH_ATTR_COLORSCHEME = "colorscheme";
	const char *GraphvizAttrs::GRAPH_ATTR_COMMENT = "comment";
	const char *GraphvizAttrs::GRAPH_ATTR_COMPOUND = "compound";
	const char *GraphvizAttrs::GRAPH_ATTR_CONCENTRATE = "concentrate";
	const char *GraphvizAttrs::GRAPH_ATTR_DPI = "dpi";
	const char *GraphvizAttrs::GRAPH_ATTR_FILLCOLOR = "fillcolor";
	const char *GraphvizAttrs::GRAPH_ATTR_FONTCOLOR = "fontcolor";
	const char *GraphvizAttrs::GRAPH_ATTR_FONTNAME = "fontname";
	const char *GraphvizAttrs::GRAPH_ATTR_FONTNAMES = "fontnames";
	const char *GraphvizAttrs::GRAPH_ATTR_FONTPATH = "fontpath";
	const char *GraphvizAttrs::GRAPH_ATTR_FONTSIZE = "fontsize";
	const char *GraphvizAttrs::GRAPH_ATTR_ID = "id";
	const char *GraphvizAttrs::GRAPH_ATTR_LABEL = "label";
	const char *GraphvizAttrs::GRAPH_ATTR_LABELJUST = "labeljust";
	const char *GraphvizAttrs::GRAPH_ATTR_LABELLOC = "labelloc";
	const char *GraphvizAttrs::GRAPH_ATTR_LANDSCAPE = "landscape";
	const char *GraphvizAttrs::GRAPH_ATTR_LAYERS = "layers";
	const char *GraphvizAttrs::GRAPH_ATTR_LAYERSEP = "layersep";
	const char *GraphvizAttrs::GRAPH_ATTR_MARGIN = "margin";
	const char *GraphvizAttrs::GRAPH_ATTR_MINDIST = "mindist";
	const char *GraphvizAttrs::GRAPH_ATTR_NODESEP = "nodesep";
	const char *GraphvizAttrs::GRAPH_ATTR_NOJUSTIFY = "nojustify";
	const char *GraphvizAttrs::GRAPH_ATTR_ORDERING = "ordering";
	const char *GraphvizAttrs::GRAPH_ATTR_ORIENTATION = "orientation";
	const char *GraphvizAttrs::GRAPH_ATTR_OUTPUTORDER = "outputorder";
	const char *GraphvizAttrs::GRAPH_ATTR_PAGE = "page";
	const char *GraphvizAttrs::GRAPH_ATTR_PAGEDIR = "pagedir";
	const char *GraphvizAttrs::GRAPH_ATTR_PENCOLOR = "pencolor";
	const char *GraphvizAttrs::GRAPH_ATTR_PENWIDTH = "penwidth";
	const char *GraphvizAttrs::GRAPH_ATTR_PERIPHERIES = "peripheries";
	const char *GraphvizAttrs::GRAPH_ATTR_RANK = "rank";
	const char *GraphvizAttrs::GRAPH_ATTR_RANKDIR = "rankdir";
	const char *GraphvizAttrs::GRAPH_ATTR_RANKSEP = "ranksep";
	const char *GraphvizAttrs::GRAPH_ATTR_RATIO = "ratio";
	const char *GraphvizAttrs::GRAPH_ATTR_ROTATE = "rotate";
	const char *GraphvizAttrs::GRAPH_ATTR_SAMPLEPOINTS = "samplepoints";
	const char *GraphvizAttrs::GRAPH_ATTR_SEARCHSIZE = "searchsize";
	const char *GraphvizAttrs::GRAPH_ATTR_SIZE = "size";
	const char *GraphvizAttrs::GRAPH_ATTR_SPLINES = "splines";
	const char *GraphvizAttrs::GRAPH_ATTR_STYLE = "style";
	const char *GraphvizAttrs::GRAPH_ATTR_STYLESHEET = "stylesheet";
	const char *GraphvizAttrs::GRAPH_ATTR_TARGET = "target";
	const char *GraphvizAttrs::GRAPH_ATTR_TOOLTIP = "tooltip";
	const char *GraphvizAttrs::GRAPH_ATTR_TRUECOLOR = "truecolor";
	const char *GraphvizAttrs::GRAPH_ATTR_VIEWPORT = "viewport";
	const char *GraphvizAttrs::GRAPH_ATTR_URL = "URL";


	string_vector GraphvizAttrs::node_attrs({
	    NODE_ATTR_COLOR,
	    NODE_ATTR_COLORSCHEME,
	    NODE_ATTR_COMMENT,
	    NODE_ATTR_DISTORTION,
	    NODE_ATTR_FILLCOLOR,
	    NODE_ATTR_FIXEDSIZE,
	    NODE_ATTR_FONTCOLOR,
	    NODE_ATTR_FONTNAME,
	    NODE_ATTR_FONTSIZE,
	    NODE_ATTR_GROUP,
	    NODE_ATTR_HEIGHT,
	    NODE_ATTR_ID,
	    NODE_ATTR_IMAGE,
	    NODE_ATTR_IMAGESCALE,
	    NODE_ATTR_LABEL,
	    NODE_ATTR_LABELLOC,
	    NODE_ATTR_LAYER,
	    NODE_ATTR_MARGIN,
	    NODE_ATTR_NOJUSTIFY,
	    NODE_ATTR_ORIENTATION,
	    NODE_ATTR_PENWIDTH,
	    NODE_ATTR_PERIPHERIES,
	    NODE_ATTR_REGULAR,
	    NODE_ATTR_SAMPLEPOINTS,
	    NODE_ATTR_SHAPE,
	    NODE_ATTR_SIDES,
	    NODE_ATTR_SKEW,
	    NODE_ATTR_STYLE,
	    NODE_ATTR_TARGET,
	    NODE_ATTR_TOOLTIP,
	    NODE_ATTR_URL,
	    NODE_ATTR_WIDTH
	});

	string_vector GraphvizAttrs::edge_attrs({
	    EDGE_ATTR_ARROWHEAD,
	    EDGE_ATTR_ARROWSIZE,
	    EDGE_ATTR_ARROWTAIL,
	    EDGE_ATTR_COLOR,
	    EDGE_ATTR_COLORSCHEME,
	    EDGE_ATTR_COMMENT,
	    EDGE_ATTR_CONSTRAINT,
	    EDGE_ATTR_DECORATE,
	    EDGE_ATTR_DIR,
	    EDGE_ATTR_EDGEURL,
	    EDGE_ATTR_EDGEHREF,
	    EDGE_ATTR_EDGETARGET,
	    EDGE_ATTR_EDGETOOLTIP,
	    EDGE_ATTR_FONTCOLOR,
	    EDGE_ATTR_FONTNAME,
	    EDGE_ATTR_FONTSIZE,
	    EDGE_ATTR_HEADCLIP,
	    EDGE_ATTR_HEADHREF,
	    EDGE_ATTR_HEADLABEL,
	    EDGE_ATTR_HEADPORT,
	    EDGE_ATTR_HEADTARGET,
	    EDGE_ATTR_HEADTOOLTIP,
	    EDGE_ATTR_HEADURL,
	    EDGE_ATTR_HREF,
	    EDGE_ATTR_ID,
	    EDGE_ATTR_LABEL,
	    EDGE_ATTR_LABELANGLE,
	    EDGE_ATTR_LABELDISTANCE,
	    EDGE_ATTR_LABELFLOAT,
	    EDGE_ATTR_LABELFONTCOLOR,
	    EDGE_ATTR_LABELFONTNAME,
	    EDGE_ATTR_LABELFONTSIZE,
	    EDGE_ATTR_LABELHREF,
	    EDGE_ATTR_LABELURL,
	    EDGE_ATTR_LABELTARGET,
	    EDGE_ATTR_LABELTOOLTIP,
	    EDGE_ATTR_LAYER,
	    EDGE_ATTR_LHEAD,
	    EDGE_ATTR_LTAIL,
	    EDGE_ATTR_MINLEN,
	    EDGE_ATTR_PENWIDTH,
	    EDGE_ATTR_SAMEHEAD,
	    EDGE_ATTR_SAMETAIL,
	    EDGE_ATTR_STYLE,
	    EDGE_ATTR_TAILCLIP,
	    EDGE_ATTR_TAILHREF,
	    EDGE_ATTR_TAILLABEL,
	    EDGE_ATTR_TAILPORT,
	    EDGE_ATTR_TAILTARGET,
	    EDGE_ATTR_TAILTOOLTIP,
	    EDGE_ATTR_TAILURL,
	    EDGE_ATTR_TARGET,
	    EDGE_ATTR_TOOLTIP,
	    EDGE_ATTR_WEIGHT
	});

	string_vector GraphvizAttrs::graph_attrs({
		GRAPH_ATTR_ASPECT,
		GRAPH_ATTR_BGCOLOR,
		GRAPH_ATTR_CENTER,
		GRAPH_ATTR_CLUSTERRANK,
		GRAPH_ATTR_COLOR,
		GRAPH_ATTR_COLORSCHEME,
		GRAPH_ATTR_COMMENT,
		GRAPH_ATTR_COMPOUND,
		GRAPH_ATTR_CONCENTRATE,
		GRAPH_ATTR_DPI,
		GRAPH_ATTR_FILLCOLOR,
		GRAPH_ATTR_FONTCOLOR,
		GRAPH_ATTR_FONTNAME,
		GRAPH_ATTR_FONTNAMES,
		GRAPH_ATTR_FONTPATH,
		GRAPH_ATTR_FONTSIZE,
		GRAPH_ATTR_ID,
		GRAPH_ATTR_LABEL,
		GRAPH_ATTR_LABELJUST,
		GRAPH_ATTR_LABELLOC,
		GRAPH_ATTR_LANDSCAPE,
		GRAPH_ATTR_LAYERS,
		GRAPH_ATTR_LAYERSEP,
		GRAPH_ATTR_MARGIN,
		GRAPH_ATTR_MINDIST,
		GRAPH_ATTR_NODESEP,
		GRAPH_ATTR_NOJUSTIFY,
		GRAPH_ATTR_ORDERING,
		GRAPH_ATTR_ORIENTATION,
		GRAPH_ATTR_OUTPUTORDER,
		GRAPH_ATTR_PAGE,
		GRAPH_ATTR_PAGEDIR,
		GRAPH_ATTR_PENCOLOR,
		GRAPH_ATTR_PENWIDTH,
		GRAPH_ATTR_PERIPHERIES,
		GRAPH_ATTR_RANK,
		GRAPH_ATTR_RANKDIR,
		GRAPH_ATTR_RANKSEP,
		GRAPH_ATTR_RATIO,
		GRAPH_ATTR_ROTATE,
		GRAPH_ATTR_SAMPLEPOINTS,
		GRAPH_ATTR_SEARCHSIZE,
		GRAPH_ATTR_SIZE,
		GRAPH_ATTR_SPLINES,
		GRAPH_ATTR_STYLE,
		GRAPH_ATTR_STYLESHEET,
		GRAPH_ATTR_TARGET,
		GRAPH_ATTR_TOOLTIP,
		GRAPH_ATTR_TRUECOLOR,
		GRAPH_ATTR_VIEWPORT,
		GRAPH_ATTR_URL
	});
}