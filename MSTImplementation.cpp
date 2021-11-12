//Katie Ortiz - Homework #5 - CS 236 - 4/25/2021
#include "MSTHeader.h"


//Implementation for the Graph constructor
Graph::Graph(int vertices, int edges){

	this->graphVertices = vertices;
	this->graphEdges = edges;
}
//Implementation of the DisjointSets constructor
DisjointSets::DisjointSets(int x) {
	this->x = x;
	x = 15;
	parent = new int[x];
	rank = new int[x];

	for (int i = 0; i <= x; i++) {

		rank[i] = 0; //The rank of all vertices is set to 0 and all vertices are in different sets 		
		parent[i] = i; //This sets the element to be a parent of itself
	}
}

//Implementation of the addEdge function
void Graph::addEdge(int x, int y, int z){

	edges.push_back({ z, {x, y} }); //This helps to add edges
}


//Implementation of the kruskalMSTAlgorithm function
int Graph::kruskalMSTAlgorithm() {

	int MSTWeight = 0; //This initializes the MST weight to 0

	sort(edges.begin(), edges.end()); //This sorts the edges in increasing order based on the cost

	DisjointSets ds(graphVertices); //This will create the Disjoint Sets

	vector <pair<int, graphPair> >::iterator repeater;

	for (repeater = edges.begin(); repeater != edges.end(); repeater++) { //This will go through all the sorted edges

		int x = repeater->second.first;
		int y = repeater->second.second;
		int setX = ds.find(x); //The set for X will be created
		int setY = ds.find(y); //The set for Y will be created

		if (setX != setY) { //This checks if the current edge is creating a cycle or not

			cout << x << " - " << y << " = " << repeater->first << "\n";

			MSTWeight += repeater->first; //This updates the MST weight

			ds.unite(setX, setY); //This will merge the two sets
		}
	}

	return MSTWeight; //Returns the MST weight
}

//Implementation of the find function 
int DisjointSets::find(int node) {

	if (node != parent[node]) {
		parent[node] = find(parent[node]); //This makes the parent of the nodes in the path point to the parent
	}

	return parent[node]; //Returns the parent[node] that was found
}

//Implementation of the unite function
void DisjointSets::unite(int x, int y){

	x = find(x), y = find(y);

	if (rank[x] > rank[y]) { //This is a comparison if rank of x is larger than rank of y
		parent[y] = x;
	}

	else {
		parent[x] = y; //This happens if the rank of x is less than the rank of y
	}

	if (rank[x] == rank[y]) { //This is a comparison if the rank of x is equal to the rank of y. It will increment rank of y
		rank[y]++;
	}
}


