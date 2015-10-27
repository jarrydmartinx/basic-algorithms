/*
 * oldversion.cpp
 *
 *  Created on: 27/10/2015
 *      Author: u5712904
 */




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
using namespace std;

class Vertex{
	public:
		int color;
};

class Edge{
	public:
		Vertex u;
		Vertex v;
		double w;
};

class RandCompleteGraph {
	public:
		Vertex* mVertices;
		Edge* mEdges;
		int n_vertices;
		int m_edges;
		double** weightMatrix;
		double** edgeWeightList;

		RandCompleteGraph(int n_vertices)
		{
	            this->n_vertices = n_vertices;
	            this->m_edges = n_vertices*(n_vertices-1)/2;

	            edgeWeightList = new double*[m_edges];
	            for (int i = 0; i < m_edges; i++)
	            	edgeWeightList[i]= new double[3];

	            weightMatrix = new double*[n_vertices];
	            for (int i = 0; i < n_vertices; i++)
	                weightMatrix[i] = new double[n_vertices];

	            mVertices = new Vertex[n_vertices];
	            mEdges = new Edge[n_vertices*(n_vertices-1)/2];
	            for (int i = 0; i < n_vertices; i++){
	            	mVertices[i] =new Vertex();
	            }

	            // Populate weightMatrix and edgeWeightList with random values
	            int k = 0;
	            //int debug_edgecount = 1;
	            for (int i = 0; i < n_vertices; i++)
				{
					for (int j = i; j < n_vertices; j++)
					{
						  if (i==j)
							  weightMatrix[i][j] = 0;
						  else
						  {
							  edgeWeightList[k][0] = (double)i; //from vertex u
							  edgeWeightList[k][1] = (double)j; //to vertex v
							  edgeWeightList[k][2] = (rand()+0.5)/(RAND_MAX + 1.0); //weight of edge (u,v)

							  mEdges[k] = new Edge(mVertices[i],mVertices[j],(rand()+0.5)/(RAND_MAX + 1.0));

							  weightMatrix[i][j] = edgeWeightList[k][2];
							  weightMatrix[j][i] = edgeWeightList[k][2];

							 // cout << debug_edgecount << ", " << edgeWeightList[0][k] << ", " << edgeWeightList[1][k] << ", " << edgeWeightList[2][k] << endl;
							  k++;
						//	  debug_edgecount++;
						  }
					}
				}
		}

//	      double getEdgeWeight(int i, int j) {
//	      	            if (i >= 0 && i < n_vertices && j > 0 && j < n_vertices)
//	      	                  return weightMatrix[i][j];
//	      	            else
//	      	                  return 0.0;
//	      }
//
//	      double extractEdgeWeight(int index) {
//	    	  return edgeWeightList[3][index];
//	      }

	      ~RandCompleteGraph(void) {
	            for (int i = 0; i < n_vertices; i++)
	                  delete[] weightMatrix[i];
	         //   	  delete[] edgeWeightList[i];
	            delete[] weightMatrix;
	         //   delete[] edgeWeightList;
	      }
	};


//partitions the 2D subarray (array[p...r][]) around pivot row array[r][]
int partition2D(double** array, int p, int r)
{
	double pivot = array[r][2]; // use last weight in the list as the pivot
	int i = p-1;
	for (int j=p; j < r; j++)
	{
		if (array[j][2] <= pivot)
			{
				i++;
				swap(array[j],array[i]);
			}
	}
	swap(array[i+1],array[r]);
	cout << ", pivot is: --------------------, " << pivot << endl;
//	for (int k = 0; k < (r-p)+1;k++)
//	{
//		cout << array[k][0] << ", " << array[k][1] << ", " << array[k][2] << endl;
//	}
	return i+1;
}

void quickEdgeSort(double** array, int p, int r)
{
	if (p < r)
	{
		int q = partition2D(array,p,r);
		quickEdgeSort(array, p, q-1);
		quickEdgeSort(array, q, r);
	}
	return;
}



int main() {

	int n_vec[5] = {10,100,200,500,1000};

	for(int n=0; n < 1;n++)
	{
		RandCompleteGraph* Graph = new RandCompleteGraph(n_vec[n]);
//
//	for (int i=0; i < Graph->m_edges; i++)
//			cout << Graph->edgeWeightList[i][0] << ", " << Graph->edgeWeightList[i][1] << ", " << Graph->edgeWeightList[i][2] << endl;
//	cout << "|-------------------------------------------------------------------------|" << endl;
////
	quickEdgeSort(Graph->edgeWeightList, 0, Graph->m_edges-1);
		for (int i=0; i < Graph->m_edges-1; i++)
			cout << Graph->edgeWeightList[i][0] << ", " << Graph->edgeWeightList[i][1] << ", " << Graph->edgeWeightList[i][2] << endl;

	//cout << "i + 1 = " << pig << endl;
	}
	return 0;
}


