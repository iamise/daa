
#include<iostream>
#include<queue>
#include<cstring>

#define INF 1000

using namespace std;

void  dijkstra(int **a,int,int);
int findmin(int dist[],bool vis[],int n)
{
	int min=-1;
	for(int i=0;i<n;i++)
	{
		if(vis[i]==0&&(min==-1||dist[i]<dist[min]))
			min=i;
	}
	return min;
}

int main()
{
	int n;
	cout<<"\nEnter the number of vertices:\t"<<endl;
	cin>>n;
	int *a[n];
	for(int i=0;i<n;i++)
		a[i]=new int [n];
	
	cout<<"Enter the adjacency matrix:\t";
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
			
	cout<<"Enter the source vertex:\t";
	int s;
	cin>>s;
	
	dijkstra(a,n,s);

	return 0;
}

void dijkstra(int **a,int n,int s)
{
	bool visited[n];
	int dist[n];
	memset(visited,0,sizeof(visited)); //sets all values to 0
	
	for(int i=0;i<n;i++)
		dist[i]=INF;
		
	dist[s]=0;
	priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > >pq;
	/* pq.second is vertex and pq.first is dist of that vertex from source vertex */ 
	
	pq.push(make_pair(0,s));
	while(!pq.empty())
	{	
		int min=pq.top().second; //select min weighted vertex
		 pq.pop();
		visited[min]=1;
		
		for(int j=0;j<n;j++)
		{
			if(!visited[j]&&a[min][j])
			{
				int d=dist[min]+a[min][j];
				if(d<dist[j])
					{
						dist[j]=d;//dist[min]+a[min][j];
						pq.push(make_pair(dist[j],j));
					}
			}
		}
	
	}
	
	cout<<"\nOutput:\n";
	for(int i=0;i<n;i++)
		cout<<i<<"\t"<<dist[i]<<endl;
	
}

	OUTPUT:

Enter the number of vertices:	
5
Enter the adjacency matrix:	
0 3 2 1 0
3 0 4 1 5
2 4 0 6 0
1 1 6 0 4
0 5 0 4 0
Enter the source vertex:	1

Output:
0	2
1	0
2	4
3	1
4	5


