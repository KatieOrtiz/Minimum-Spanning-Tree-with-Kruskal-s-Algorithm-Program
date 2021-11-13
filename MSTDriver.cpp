#include "MSTHeader.h"

int main(){
	
	int vertices = 7, edges = 12; //This sets the vertices of the graph to 7 and the edges of the graph to 12, as it is in the homework assignment
	Graph g(vertices, edges); //Object of Graph class

	//This adds the vertices, edges, and the weight of the path 
	g.addEdge(1, 2, 6); 
	g.addEdge(1, 6, 5);
	g.addEdge(2, 7, 7);
	g.addEdge(2, 6, 8);
	g.addEdge(2, 3, 10);
	g.addEdge(2, 6, 8);
	g.addEdge(3, 7, 5);
	g.addEdge(3, 4, 8);
	g.addEdge(3, 5, 10);
	g.addEdge(4, 5, 8);
	g.addEdge(5, 7, 7);
	g.addEdge(5, 6, 12);
	g.addEdge(6, 7, 7);

	cout << "Finding MST using Kruskal's Algorithm\n";
	cout << "Edges of MST are \n";

	int MSTWeight = g.kruskalMSTAlgorithm(); //This sets the MST weight to the value that is returned from the kruskalMSTAlgorithm function

	cout << "\nWeight of MST is " << MSTWeight << "\n"; //Outputs the MST weight 

	system("pause");
	return 0;
}

