#include<iostream>
#include<vector>
#include<utility> // required to use pair
#include<limits> // required for numeric_limits
#include<algorithm> // required for using find()
using namespace std;

int prims(vector<vector<int> >&,vector<int>&,vector<pair<int,int> >&);

int main(){
	int size;
	vector<vector<int> > graph;
	vector<int> visited;
	vector<pair<int,int> > answer;
	cout<<"enter the number of vertices: ";
	cin>>size;
	
	graph.resize(size);
	
	cout<<"enter the graph:\n";
	for(int j=0;j<size;j++){
		for(int i=0;i<size;i++){
			graph[j].resize(size);
			cin>>graph[j][i];
		}
	}
	int cost = prims(graph,visited,answer);
	cout<<"the edges in the minimum spanning tree are: \n";
	for(int i=0;i<answer.size();i++){
		cout<<'('<<answer[i].first<<","<<answer[i].second<<") ";
	}
	cout<<"\nthe total cost is : "<<cost<<endl;
	return 0;
}

int prims(vector<vector<int> >&graph,vector<int>&visited,vector<pair<int,int> >&answer){
	pair<int,int> temp;
	int cost = 0;
	int prevWeight = numeric_limits<int>::max();
	visited.push_back(0);
	//spanning tree will always have n-1 edges(n is the number of vertices)
	for(int k=0;k<graph.size()-1;k++){
		for(int i=0;i<visited.size();i++){
			for(int j=0;j<graph.size();j++){
				//find the smallest edge
				if(graph[visited[i]][j] != 0 && (find(visited.begin(),visited.end(),j) == visited.end())){
					if(graph[visited[i]][j] < prevWeight){
						temp = make_pair(visited[i],j);
						prevWeight = graph[visited[i]][j];
					}
				}
			}
		}
		//push smallest edge into answer vector
		visited.push_back(temp.second);
		answer.push_back(temp);
		cost += graph[temp.first][temp.second];
		//reset prevWeight to a large value
		prevWeight = numeric_limits<int>::max();
	}
	return cost;
}
/*
output:
enter the number of vertices: 4
enter the graph:
0 1 2 0
1 0 0 3
2 0 0 4
0 3 4 0
the edges in the minimum spanning tree are: 
(0,1) (0,2) (1,3) 
the total cost is : 6

enter the number of vertices: 4
enter the graph:
0 3 1 3
3 0 4 5
1 4 0 2
3 5 2 0
the edges in the minimum spanning tree are: 
(0,2) (2,3) (0,1) 
the total cost is : 6

*/
