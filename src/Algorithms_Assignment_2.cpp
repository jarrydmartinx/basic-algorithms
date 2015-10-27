//============================================================================
// Name        : Algorithms_Assignment_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <time.h>
using namespace std;

class Vertex {
public:
	int index;
	int rank;
	Vertex* parent;
};

class Edge {
public:
	Vertex u;
	Vertex v;
	double weight;
};

class RandCompleteGraph {

public:
	Vertex* vertexList;
	Edge* edgeList;
	int n_vertices;
	int m_edges;
	double** weightMatrix;

	RandCompleteGraph(int n_vertices) {
		//Set dimensions of graph from parameter
		this->n_vertices = n_vertices;
		m_edges = n_vertices * (n_vertices - 1) / 2;

		//Construct n-length vertex list
		vertexList = new Vertex[n_vertices];

		//Construct m-length edgeList
		edgeList = new Edge[m_edges];

		//Construct n x n weightMatrix
		weightMatrix = new double*[n_vertices];
		for (int i = 0; i < n_vertices; i++)
			weightMatrix[i] = new double[n_vertices];

		// Populate edgeList and weightMatrix with random weights. Diagonal elements of weightMatrix set to 0.
		int k = 0;
		for (int i = 0; i < n_vertices; i++) {
			for (int j = i; j < n_vertices; j++) {
				if (i == j)
					weightMatrix[i][j] = 0;
				else {
					vertexList[i].index = i;
					vertexList[j].index = j;

					edgeList[k].u = vertexList[i];
					edgeList[k].v = vertexList[j];
					edgeList[k].weight = (rand() + 0.5) / (RAND_MAX + 1.0);

					weightMatrix[i][j] = edgeList[k].weight;
					weightMatrix[j][i] = edgeList[k].weight;

					k++;
				}
			}
		}
	}

	~RandCompleteGraph(void) {
		for (int i = 0; i < n_vertices; i++) {
			delete[] weightMatrix[i];
		}
		delete[] weightMatrix;
		delete[] vertexList;
		delete[] edgeList;
	}

};

//partitions the 2D subarray (array[p...r][]) around pivot row array[r][]
int partition2D(Edge* edges, int p, int r) {
	double pivot = edges[r].weight; // use last weight in the list as the pivot
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (edges[j].weight <= pivot) {
			i++;
			swap(edges[j], edges[i]);
		}
	}
	swap(edges[i + 1], edges[r]);
	return i + 1;
}

void quickEdgeSort(Edge* edges, int p, int r) {
	if (p < r) {
		int q = partition2D(edges, p, r);
		quickEdgeSort(edges, p, q - 1);
		quickEdgeSort(edges, q, r);
	}
	return;
}

Vertex* findSet(Vertex u) {
	if (u.parent != &u) {
		u.parent = findSet(*u.parent);
	}
	return u.parent;
}

void link(Vertex* u, Vertex* v) {
	if (u->rank > v->rank) {
		v->parent = u;
	} else {
		u->parent = v;
		if (u->rank == v->rank)
			v->rank++;
	}
}

void setUnion(Vertex u, Vertex v) {
	link(findSet(u), findSet(v));
}

Edge* kruskalMST(RandCompleteGraph* graph) {
	Edge* setA = new Edge[graph->n_vertices - 1]; //Set A begins empty, it is the set of edges in the minimum spanning tree

	//For all v, "Makeset(v)" simply sets parent[v] = v
	for (int i = 0; i < graph->n_vertices; i++) {
		graph->vertexList[i].parent = &graph->vertexList[i];
		graph->vertexList[i].rank = 0;
	}

	quickEdgeSort(graph->edgeList, 0, graph->m_edges - 1);

	int k = 0;
	for (int i = 0; i < graph->m_edges; i++)
		if (findSet(graph->edgeList[i].u) != findSet(graph->edgeList[i].v)) {
			setA[k] = graph->edgeList[i];
			k++;

			setUnion(graph->edgeList[i].u, graph->edgeList[i].v);
		}
	return setA;
}

int main() {

	int n_vec[5] = { 10, 100, 200, 500, 1000 };

	for (int n = 0; n < 1; n++) {
		RandCompleteGraph* graph = new RandCompleteGraph(n_vec[n]);

		clock_t t;
		t = clock();
		Edge* mst_edges = kruskalMST(graph);
		t = clock() - t;

		cout << "Time is: " << t << endl;
	}
	return 0;
}

