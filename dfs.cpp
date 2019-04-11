#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

class Graph
{
 public:
    int size;
    int **adjmatrix;
    int *visited;
    vector<int>dfsOrder;
    Graph(int n): size(n)
    {
    	adjmatrix=new int*[size];
    	for(int i=0;i<size;i++)
    		adjmatrix[i]=new int[size];
    	visited=new int[size];
        cout<<"Enter the adjacency matrix\n";
        for(int i=0;i<size;i++)
        {
          for(int j=0;j<size;j++)
             cin>>adjmatrix[i][j];
          visited[i]=0;
        }       
    }
    void dfs(Graph&);
    void dfsHelp(Graph&, int);
    void display(Graph&);
};

void Graph::dfs(Graph& gr)
{
        for(int i=0;i<gr.size;i++)
            if(gr.visited[i]==0)
                dfsHelp(gr,i);

}

void Graph::dfsHelp(Graph& gr,int i)
{ 
    gr.visited[i]=1;
    gr.dfsOrder.push_back(i);
    int rowIndex=i;
    for(int k=0;k<gr.size;k++)
    {
        if(gr.adjmatrix[rowIndex][k]==1 && gr.visited[k]==0)
        {
            dfsHelp(gr,k);
        }
    }
}

void Graph::display(Graph& gr)
{
	vector<int>::iterator i;
	for(i=gr.dfsOrder.begin();i!=gr.dfsOrder.end();i++)
		cout<<*i<<" ";
	cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter the size of adj matrix(m=n)\n";
    cin>>n;
    Graph graph(n);
    graph.dfs(graph);
    cout<<"DFS order: \n";
   	graph.display(graph);
    return 0;
}

/*output

Enter the size of adj matrix(m=n)
3
Enter the adjacency matrix
0 1 1
1 0 1
1 1 0
DFS order: 
0 1 2 

Enter the size of adj matrix(m=n)
6
Enter the adjacency matrix
0 0 1 1 1 0
0 0 0 0 1 1
1 0 0 1 0 1
1 0 1 0 0 0
1 1 0 0 0 1
0 1 1 0 1 0
DFS order: 
0 2 3 5 1 4 
*/

