#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//node representation
typedef pair<int,int> node;
// for Kruskal we need edge weight representation
		//for weight with the edge repr
vector<pair<int,node>> edge;
class Graph{
	private:
			int V;
			int E;//for edge Kruskal 
			
			// vector<node>*adj;
			list <node> *adj;
			list<int> *AdjList;
public:
	
	
		int *parent_of_set,*rank;
		
		void addEdge_weighted(int v,int u,int w);
		void addEdge_Kruskal(int,int,int);
		void add_edge(int,int);
		Graph(int V);
		
		void Dijsktra(int src);
		void MSTPrims(int src);
		int MSTKruskal();
		
		void graph_colouring();
			
};
Graph::Graph(int V){
	this->V = V;
	adj = new list<node> [V];
	AdjList = new list<int>[V];
	
}

//adding edge for kruskal implementation
void Graph::addEdge_Kruskal(int u,int v,int w){
	edge.push_back({w,make_pair(u,v)});
}

void Graph::addEdge_weighted(int v,int u,int w){
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}

void Graph::add_edge(int u,int v){
	AdjList[u].push_back(v);
	AdjList[v].push_back(u);
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
	
	for(int i=0;i<V;i++){
		cout<<i<<" "<<distances[i]<<endl;
	}
	
	
}

void Graph::MSTPrims(int source){
	//create a priority queue of type node of MinHeap 
	priority_queue< node,vector<node>,greater<node> > pq;  
	//create a vector key to keep track of the weights included in mst
	vector<int> key(V,999);
	//to keep track of the nodes including in the mst
	vector<int> parent(V,-1);
	//checking whether already visited or not in the priority queue 
	vector<bool> inSpanningTree(V,false);
	int u;
	
	//make sourc of the vertex as zero
	key[source] = 0;
	//push to queue 
	pq.push(make_pair(0,source));
	//loop till not empty 
	while(!pq.empty()){
		//get the top element weight
		u = pq.top().second;
		//pop the element
		pq.pop();
		//set the visited status as true
		inSpanningTree[u] = true;
		//iterator to loop through the adjacency list
		list< pair<int,int> >::iterator it;
		for(it = adj[u].begin();it!=adj[u].end();it++){
			int v = (*it).first;//get the vertex
			int w = (*it).second;//get the weight
			//check if node is already visited and taken into and check the new weight is less than previous
			if(inSpanningTree[v]==false && key[v] > w){
				//add to the key array the new weight and push the node pair into queue
				key[v] = w;
				pq.push(make_pair(key[v],v));
				parent[v] = u;
			}
		}
	}
	for(int i=1;i<V;i++){
		cout<<parent[i]<<" "<<i<<endl;
	}
}

class DisjointSets{
private:
	int *parent_of_set;
		int *rank;
		int N;
public:
		DisjointSets(int);
		int find_Set(int);
		void union_of_set(int,int);
	
	
};

DisjointSets::DisjointSets(int N){
	this->N = N;
	parent_of_set = new int[N+1];
	rank = new int[N+1];
	
	
	for(int i=0;i<N+1;i++){
		parent_of_set[i] = i;
		rank[i] = 0;
	}
}

int DisjointSets::find_Set(int node_vertex){
	
	if(node_vertex!=parent_of_set[node_vertex]){
		parent_of_set[node_vertex] = find_Set(parent_of_set[node_vertex]);
	}
	return parent_of_set[node_vertex];
}

void DisjointSets::union_of_set(int u,int v){
	//int x,y;
	u = find_Set(u);
	v = find_Set(v);
	
	if(rank[u]>rank[v])
		parent_of_set[v] = u;
	else 
		parent_of_set[u] = v;
	
	if(rank[u]==rank[v])
		rank[v]++;
				
}

int Graph::MSTKruskal(){
	int mst_weight = 0;
	sort(edge.begin(),edge.end());
	DisjointSets D(V);
	
	vector<pair<int,node>>::iterator it;
	for(it=edge.begin();it!=edge.end();it++){
		int u = (*it).second.first;
		int v = (*it).second.second;
		int w = (*it).first;
		
		int set_U = D.find_Set(u);
		int set_V = D.find_Set(v);
		
		if(set_U!=set_V){
			cout<<u<<"-"<<v<<" ";
			mst_weight+=w;
			D.union_of_set(u,v);
			
			
		}
	}
	
	return mst_weight;
}

void Graph::graph_colouring(){
	int result[V];
	bool colours_available[V];
	
	result[0] = 0;
	
	for(int i=1;i<V;i++)
		result[i] = -1;
	for(int i=1;i<V;i++)
		colours_available[i] = false;
	
	for(int j=1;j<V;j++){
		list<int>::iterator it;
		for(it=AdjList[j].begin();it!=AdjList[j].end();it++){
			if(result[*it]!=-1){
				colours_available[result[*it]] = true;
			}
		}
			int k;
			for( k=0;k<V;k++){
				if(colours_available[k]!=true)
					break;
			}
			result[j] = k;
			
			for(it=AdjList[j].begin();it!=AdjList[j].end();it++){
			if(result[*it]!=-1){
				colours_available[result[*it]] = false;
			}
			
			
		}
		
	}
	
	 for (int u = 0; u < V; u++)
        cout << "Vertex no: " << u << " --->  Colour "
             << result[u] << endl;
	
}



int main(int argc, char **argv)
{
	//Graph g(9);
	 int V = 9;
    Graph g(V);
 
    //  making above shown graph
//    g.addEdge(0, 1, 4);
//    g.addEdge(0, 7, 8);
//    g.addEdge(1, 2, 8);
//    g.addEdge(1, 7, 11);
//    g.addEdge(2, 3, 7);
//    g.addEdge(2, 8, 2);
//    g.addEdge(2, 5, 4);
//    g.addEdge(3, 4, 9);
//    g.addEdge(3, 5, 14);
//    g.addEdge(4, 5, 10);
//    g.addEdge(5, 6, 2);
//    g.addEdge(6, 7, 1);
//    g.addEdge(6, 8, 6);
//    g.addEdge(7, 8, 7);

//	g.addEdge_Kruskal(0, 1, 4);
//	g.addEdge_Kruskal(0, 7, 8);
//    g.addEdge_Kruskal(1, 2, 8);
//    g.addEdge_Kruskal(1, 7, 11);
//    g.addEdge_Kruskal(2, 3, 7);
//    g.addEdge_Kruskal(2, 8, 2);
//    g.addEdge_Kruskal(2, 5, 4);
//    g.addEdge_Kruskal(3, 4, 9);
//    g.addEdge_Kruskal(3, 5, 14);
//    g.addEdge_Kruskal(4, 5, 10);
//    g.addEdge_Kruskal(5, 6, 2);
//    g.addEdge_Kruskal(6, 7, 1);
//    g.addEdge_Kruskal(6, 8, 6);
//    g.addEdge_Kruskal(7, 8, 7);
 
    //g.Dijsktra(0);
	//g.MSTPrims(0);
	//int mst_krusk_weight = g.MSTKruskal();
	//cout<<mst_krusk_weight;
	
	
	Graph g1(5);
	
    g1.add_edge(0, 1);
    g1.add_edge(0, 2);
    g1.add_edge(1, 2);
    g1.add_edge(1, 3);
    g1.add_edge(2, 3);
    g1.add_edge(3, 4);
    cout << "Coloring of graph 1 \n";
    g1.graph_colouring();
	
	
	return 0;
}
