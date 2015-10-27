/*
 * scraps.cpp
 *
 *  Created on: 27/10/2015
 *      Author: u5712904
 */

//void quickSort(vector<int>& A, int p,int q)
//{
//    int r;
//    if(p<q)
//    {
//        r=partition(A, p,q);
//        quickSort(A,p,r);
//        quickSort(A,r+1,q);
//    }
//}



//
//	// DIRECTED FOREST - for each vertex v, forest(v,1) = parent[v], forest(v,2) = rank(parent[v]) vertices are indexed from 0 to n-1
//			int forest[n_vec[i]][2];
//
//	// KRUSKAL'S ALGORITHM
//
//			//For all vertices v, Makeset(v)
//			for (int v = 0; v < n_vec[i]; v++) {
//				forest[v][1] = v;
//				forest[v][2] = 0; //initially all trees in forest have rank 0
//			}





//
//class Graph {
//private:
//      bool** adjacencyMatrix;
//      int vertexCount;
//public:
//      Graph(int vertexCount) {
//            this->vertexCount = vertexCount;
//            adjacencyMatrix = new bool*[vertexCount];
//            for (int i = 0; i < vertexCount; i++) {
//                  adjacencyMatrix[i] = new bool[vertexCount];
//                  for (int j = 0; j < vertexCount; j++)
//                        adjacencyMatrix[i][j] = false;
//            }
//      }
//
//      void addEdge(int i, int j) {
//            if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount) {
//                  adjacencyMatrix[i][j] = true;
//                  adjacencyMatrix[j][i] = true;
//            }
//      }
//
//      void removeEdge(int i, int j) {
//            if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount) {
//                  adjacencyMatrix[i][j] = false;
//                  adjacencyMatrix[j][i] = false;
//            }
//      }
//
//      bool isEdge(int i, int j) {
//            if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount)
//                  return adjacencyMatrix[i][j];
//            else
//                  return false;
//      }
//
//      ~Graph() {
//            for (int i = 0; i < vertexCount; i++)
//                  delete[] adjacencyMatrix[i];
//            delete[] adjacencyMatrix;
//      }
//};

//
//
//expected declaration before ‘}’ token
//
//
//		double expected_weight_MST(); //expected weighted sum of the MST of the graph
//		double kruskalRuntime(); //the running time of Kruskals algorithm
//		CompleteGraph(double size);
//};
//
////Constructor and member functions
//CompleteGraph::CompleteGraph(double size)
//{
//	weight_matrix[][]
//}
//
//double CompleteGraph::kruskalRuntime()
//{
//	return
//
//
//
//for (int i=0; i<5; i++)
//	kruskal(n[i]);
//
//	cout << "For n = " << n[i] << " vertices: L(n)= " << CompleteGraph.expected_weight_MST << ", runtime: " << CompleteGraph.kruskalRuntime << endl; // prints !!!Hello World!!!
//	return 0;
//}




