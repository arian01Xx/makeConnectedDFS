#ifndef SOLUTION_ONE_HPP
#define SOLUTION_ONE_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class SolutionTwelve{
public:
	void dfs(int node, unordered_map<int,vector<int>>& graph, unordered_set<int>& visited){
		queue<int> q;
		q.push(node);
		visited.insert(node);
		while(!q.empty()){
			int curr=q.front();
			q.pop();
			for(int neighbor: graph[curr]){
				if(visited.find(neighbor)==visited.end()){
					visited.insert(neighbor);
					q.push(neighbor);
				}
			}
		}
	}
	int makeConnected(int n, vector<vector<int>>& connections){
		if(connections.size()<n-1) return -1;
		//construccion del grafo
		unordered_map<int,vector<int>> graph;
		for(int i=0; i<connections.size(); i++){
			graph[connections[i][0]].push_back(connections[i][1]);
			graph[connections[i][1]].push_back(connections[i][0]);
		}
		//contar componentes conectados
		unordered_set<int> visited;
		int components=0;
		for(int i=0; i<n; i++){
			if(visited.find(i)==visited.end()){
				//de esa forma llena el unordered_set
				dfs(i,graph,visited);
				components++;
			}
		}
		return components-1;
	}
};

#endif