class Solution {
public:
    bool DFSVisit(int node, std::vector<std::vector<int> > &G, std::vector<int> &visited,std::vector<int> &topoOrder) {
	if(visited[node]==1){
		return false;
	}
	if(visited[node]==0){
		visited[node]=1;
		for(int i=0;i<G[node].size();i++){
		bool res = DFSVisit(G[node][i],G,visited,topoOrder);
			if(!res)
				return false;
		}
		visited[node]=2;
		topoOrder.push_back(node);
	}
	return true;
}


std::vector<int> topoSort(std::vector<std::vector<int> > &G) {
	int numVertices = G.size();
	// Do DFS 
	std::vector<int> visited(numVertices,0);
	std::vector<int> orderV;
	bool success = true;
	for(int i=0;i<numVertices;i++){
		if(visited[i]==0){
			bool res = DFSVisit(i,G,visited,orderV);
			success &= res;
		}
	}
	std::vector<int> retVec;
	if(success){
		std::reverse(orderV.begin(),orderV.end());
		retVec = orderV;
	}
	return retVec;
}


std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
	//Majke the graph (adj mat) 
	std::vector<std::vector<int> > G;
	G.resize(numCourses);
	for(auto it = prerequisites.begin();it != prerequisites.end();it++) {
		int toV = it->first;
		int fromV = it->second;
		G[fromV].push_back(toV);
	}
	//Perform toposort on it
	return topoSort(G);
}
};