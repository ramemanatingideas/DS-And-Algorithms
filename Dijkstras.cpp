#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> node;

void shortestPathUtil(vector<int>&v){
	for(int it = 0;it<v.size();it++)
		cout<<it<<" "<<v[it]<<endl;
}


class Graph{
	private:
			int V;

			// vector<node>*adj;
			list <node> *adj;
	public:
		void addEdge(int v,int u,int w);
		Graph(int V);
		void Dijsktra(int src);

};
Graph::Graph(int V){
	this->V = V;
	adj = new list<node> [V];
}

void Graph::addEdge(int v,int u,int w){
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}

void Graph::Dijsktra(int source){
	priority_queue <node,vector<node>,greater<node> >pq;
	vector<int> distances (V,999);

	pq.push(make_pair(0,source));
	distances[source] = 0;

	while(!pq.empty()){
		int top_val = pq.top().second;//we want only the weights for dijsktras
		pq.pop();

		list<pair<int,int>>::iterator it;
		for( it = adj[top_val].begin() ; it !=adj[top_val].end(); it++ )
		{
			int v = (*it).first;
			int w = (*it).second;

			if(distances[v] > distances[top_val] + w ){
				distances[v] = distances[top_val] + w;
				pq.push(make_pair(distances[v],v));
			}
		}
	}
	shortestPathUtil(distances);
}

int main(int argc, char **argv)
{
	//Graph g(9);
	 int V = 9;
    Graph g(V);
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.Dijsktra(0);



	return 0;
}
