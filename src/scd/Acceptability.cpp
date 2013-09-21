/*
 * Acceptability.cpp
 *
 *  Created on: 16.06.2013
 *  Author: cls, Yassine Marrakchi
 */

#include "Acceptability.h"

namespace NetworKit {


Acceptability::Acceptability(
	const Graph& G, std::unordered_set<node>& community, std::unordered_set<node>& shell) : G(&G), community(&community), shell(&shell) {
}

NodeClusterSimilarity::NodeClusterSimilarity(
	const Graph& G, std::unordered_set<node>& community, std::unordered_set<node>& shell): Acceptability(G, community, shell) {
}

NodeClusterSimilarity::~NodeClusterSimilarity() {
}

double NodeClusterSimilarity::getValue(node v) {

	double intersection = 0;
	// Compute the intersection of the node's neighborhood and the current community's neighborhood
	this->G->forNeighborsOf(v, [&](node u) {

		if (this->community->find(u) != this->community->end()||this->shell->find(u) != this->shell->end()) {
			intersection++;
		}
	});

	if (this->shell->find(v) != this->shell->end()) {
		intersection++;
	}

	if (G->hasEdge(v, v)) {
		return (intersection - 1) / (G->degree(v) + community->size() + shell->size() - intersection  + 1);
	}

	return intersection / (G->degree(v) + 1 + community->size() + shell->size() - intersection);
}

Acceptability::~Acceptability() {
}

DummySimilarity::DummySimilarity(
		const Graph& G, std::unordered_set<node>& community, std::unordered_set<node>& shell): Acceptability(G, community, shell) {
}

DummySimilarity::~DummySimilarity() {
}

double DummySimilarity::getValue(node v) {
	return 0.5;
}

}
