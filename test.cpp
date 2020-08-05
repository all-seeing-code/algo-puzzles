#include <iostream>
#include <string>
#include <vector>
#include <queue>
//#include <pair>
//#include <bits/stdc++. h> 
using namespace std;

void reset(int size, vector<int> &v)
{
	for (int i=0; i<size; i++) v[i] = -1;
	return;
}


int bfs(int start, pair<int,int> avoid_edge, int size, vector<int> &dist, vector<int> &visit, vector<vector<int> >&graph)
{	
	dist[start] = visit[start] = 0;
	queue<int> bfs_q;
	bfs_q.push(start);
	while(!bfs_q.empty())
	{
		int top = bfs_q.front();
		bfs_q.pop();
		for (int i = 0; i < graph[top].size(); ++i)
		{
			if( (graph[top][i] == avoid_edge.first && top == avoid_edge.second) || (graph[top][i] == avoid_edge.second && top == avoid_edge.first) ) continue;
			else
			{
				if(visit[graph[top][i]] == -1)
				{
					visit[graph[top][i]] = 0;
					dist[graph[top][i]] = dist[top] + 1;
					bfs_q.push(graph[top][i]);
				}
			}
			/* code */
		}
		visit[top] = 1;

	}
	return 0;
}


int diameter( int start, int avoid, int size, vector<vector<int> >&graph )
{

	pair<int, int> avoid_edge = make_pair(start, avoid);
	vector<int> dist(size, -1);
	vector<int> visit(size, -1);

	bfs(start, avoid_edge, size, dist, visit, graph);

	int vert = 0; 
	int distance = dist[0];
	for(int i=1; i<size; i++)
	{
		if(dist[i] > distance)
		{
			vert = i;
			distance = dist[i];
		}
	};
	
	reset(size, dist);
	reset(size, visit);
	bfs(vert, avoid_edge, size, dist, visit, graph);

	vert = 0; 
	distance = dist[0];
	for(int i=1; i<size; i++)
	{
		if(dist[i] > distance)
		{
			vert = i;
			distance = dist[i];
		}
	};

	return distance;

}


int main()
{
	
	int n, ans;
	cin>>n;
	vector<int> v;
	vector<vector<int> > graph(n,v);
	vector< pair<int,int> > edges;
	
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		edges.push_back(make_pair(a,b));
		cout<<edges[i-1].first;
	}

	for (int i = 0; i < edges.size(); ++i)
	{
		//break edge[i]
		int dist1 = diameter(edges[i].first, edges[i].second, n, graph);
		int dist2 = diameter(edges[i].second, edges[i].first, n, graph);
		if(i==0) ans = dist1*dist2;
		else ans = max(ans, dist1*dist2);
	}




	cout << "Ans " << ans <<endl;
	return 0;
}