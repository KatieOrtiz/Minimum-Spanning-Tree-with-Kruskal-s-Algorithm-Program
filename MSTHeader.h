#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int, int> graphPair;

//Class for the Graph
class Graph{
public:
	//Member variables
	int graphVertices, graphEdges;
	vector <pair<int, graphPair> > edges;

	//Constructor
	Graph(int vertices, int edges);

	//Member function declarations
	void addEdge(int u, int v, int w);
	int kruskalMSTAlgorithm();
};


//Class for the Disjoints Sets data structure
class DisjointSets{
public:
	//Member variables
	int *parent, *rank;
	int x;

	//Constructor
	DisjointSets(int x);

	//Member function declarations
	int find(int node);
	void unite(int x, int y);
};

