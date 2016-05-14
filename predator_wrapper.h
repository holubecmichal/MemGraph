//
// Created by Michael Holubec on 12.04.16.
//

#ifndef MEMGRAPH_PREDATOR_H
#define MEMGRAPH_PREDATOR_H


#include "plotter.h"
#include "graphviz_plotter.h"

using namespace memgraph;
class PredatorWrapper {
public:
	enum {
		OFF,
		ON,
	};

	enum {
		LVL_1,
		LVL_2,
	};

private:

	/**
	 * metoda prochazi a uklada hrany komponenty grafu
	 * @param GraphComponent *graph
	 * @param edges_vect *edges vektor hran, kam jsou nove nalezene hrany ulozeny
	 */
	void walkEdgesRecursively(GraphComponent *graph, edges_vect *edges);

	/**
	 * metoda prochazi a uklada podgrafy komponenty grafu
	 * @param GraphComponent *graph
	 * @param subgraphs_vect *subgraphs vektor podgrafu, kam jsou nove nalezene podgrafy ulozeny
	 */
	void walkSubgraphsRecursively(GraphComponent *graph, subgraphs_vect *subgraphs);

	/**
	 * metoda prochazi a uklada vrcholy komponenty grafu
	 * @param GraphComponent *graph
	 * @param nodes_vect *edges vektor vrcholu, kam jsou nove nalezene vrcholy ulozeny
	 */
	void walkNodesRecursively(GraphComponent *graph, nodes_vect *nodes);

	/**
	 * metoda kontroluje vlastnosti podgrafu a vyhodnocuje, zda jsou shodne s vlastnostmi SLS komponenty nastroje Predator
	 * @param Subgraph* sls podgraf
	 * @return bool
	 */
	bool isSLS(Subgraph *sls);

	/**
	 * metoda kontroluje vlastnosti hrany a vyhodnocuje, zda jsou shodne s vlastnostmi hasValue hrany nastroje Predator
	 * @param Subgraph* sls podgraf
	 * @return bool
	 */
	bool isHasValueEdge(Edge *edge);

	/**
	 * metoda kontroluje vlastnosti hrany a vyhodnocuje, zda jsou shodne s vlastnostmi pointsTo hrany nastroje Predator
	 * @param Subgraph* sls podgraf
	 * @return bool
	 */
	bool isPointsToEdge(Edge *edge);

	/**
	 * metoda kontroluje vlastnosti vrcholu a vyhodnocuje, zda jsou shodne s vlastnostmi Value vrcholu nastroje Predator
	 * @param Subgraph* sls podgraf
	 * @return bool
	 */
	bool isValuesNode(Node *node);

	/**
	 * metoda kontroluje vlastnosti podgrafu a vyhodnocuje, zda jsou shodne s vlastnostmi DLS komponenty nastroje Predator
	 * @param Subgraph* sls podgraf
	 * @return bool
	 */
	bool isDLS(Subgraph *dls);

	/**
	 * vraci vsechny hrany grafoveho prostoru
	 * @return edges_vect vektor vsech hran
	 */
	edges_vect getAllEdges();

	/**
	 * vraci vsechny podgrafy grafoveho prostoru
	 * @return subgraphs_vect vektor vsech podgrafu
	 */
	subgraphs_vect getAllSubgraphs();

	/**
	 * vraci vsechny vrcholy grafoveho prostoru
	 * @return nodes_vect vektor vsech vrcholu
	 */
	nodes_vect getAllNodes();

public:
	Plotter *plotter;

	/**
	 * vraci vsechny hasValue hrany grafoveho prostoru
	 * @return edges_vect vektor vsech hasValue hran
	 */
	edges_vect getHasValuesEdges();

	/**
	 * vraci vsechny pointsTo hrany grafoveho prostoru
	 * @return edges_vect vektor vsech hasValue hran
	 */
	edges_vect getPointsToEdges();

	/**
	 * vraci vsechny Value vrcholu grafoveho prostoru
	 * @return nodes_vect vektor Value vrcholu
	 */
	nodes_vect getValuesNodes();

	/**
	 * vraci vsechny SLS komponenty grafoveho prostoru
	 * @return subgraphs_vect vektor SLS podgrafu
	 */
	subgraphs_vect getSLSSubgraphs();

	/**
	 * vraci vsechny DLS komponenty grafoveho prostoru
	 * @return nodes_vect vektor DLS podgrafu
	 */
	subgraphs_vect getDLSSubgraphs();

	/**
	 * dle predane urovne nastavi detaily k vykresleni vsem vrcholum typu Value
	 * @param int lvl level-of-details
	 */
	void abstractValues(int lvl);

	/**
	 * dle predane urovne nastavi detaily k vykresleni vsem podgrafum typu SLS
	 * @param int lvl level-of-details
	 */
	void abstractSLS(int lvl);

	/**
	 * dle predane urovne nastavi detaily k vykresleni vsem podgrafum typu DLS
	 * @param int lvl level-of-details
	 */
	void abstractDLS(int lvl);

	PredatorWrapper(Plotter *plotter) : plotter(plotter) { }
	PredatorWrapper() { plotter = new GraphvizPlotter(); }

	/**
	 * vykresli|nevykresli offset label hrany
	 * @param bool
	 */
	void plotOffset(bool status = ON);
};


#endif //MEMGRAPH_PREDATOR_H
