#include<iostream>
#include<vector>
#include<queue>
#include<iterator>
using namespace std;

class Graph
{
 public:
    int size;
    int **adjmatrix;
    int *visited;
    vector<int>bfsOrder;
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
    void bfs(Graph&);
    void bfsHelp(Graph&, int);
    void display(Graph&);
};

void Graph::bfs(Graph& gr)
{
        for(int i=0;i<gr.size;i++)
            if(gr.visited[i]==0)
                bfsHelp(gr,i);

}

void Graph::bfsHelp(Graph& gr,int i)
{ 
    queue<int>bfsqueue;
    gr.visited[i]=1;
    bfsqueue.push(i);
    int rowIndex;
    while(!bfsqueue.empty())
    {    
        rowIndex=bfsqueue.front();
        for(int k=0;k<gr.size;k++)
        {
            if(gr.adjmatrix[rowIndex][k]==1 && gr.visited[k]==0)
            {
                gr.visited[k]=1;
                bfsqueue.push(k);
            }   
        }
        bfsOrder.push_back(bfsqueue.front());
        bfsqueue.pop();
    }    
}

void Graph::display(Graph& gr)
{
    vector<int>::iterator i;
	for(i=gr.bfsOrder.begin();i!=gr.bfsOrder.end();i++)
		cout<<*i<<" ";
	cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter the size of adj matrix(m=n)\n";
    cin>>n;
    Graph graph(n);
    graph.bfs(graph);
    cout<<"BFS order: \n";
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
BFS order: 
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
BFS order: 
0 2 3 4 5 1 
*/
