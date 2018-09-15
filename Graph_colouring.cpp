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
