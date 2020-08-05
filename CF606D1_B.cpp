//Two pair

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;


void BFS(int source, int cutVertex, char type, vector<vector<int> > &graph, vector<pair<int,int> > &components, vector<int> &visit, int c)
{
	int top;
	queue<int> q;
	q.push(source);
	visit[source] = 0;
	if(type == 'a') components[source].first = c;
	else components[source].second = c;
	while(!q.empty())
	{
		top = q.front();
		q.pop();
		int len = graph[top].size();
		for (int i = 0; i < len; ++i)
		{
			int vertex = graph[top][i];
			if(visit[vertex] == -1)
			{
				visit[vertex] = 0;
				if(vertex != cutVertex)
				{
					if(type == 'a') components[vertex].first = c;
					else components[vertex].second = c;
					q.push(vertex);
				}
			}
			/* code */
		}
		visit[top] = 1;

	}


}

void BFSComponent(int cutVertex, char type, int size, vector<vector<int> > &graph, vector<pair<int,int> > &components)
{
	vector<int> visit(size+1, -1);
	int c = 1; //Component
	for(int i=1; i <= size; i++)
	{
		if(visit[i] == -1 && i != cutVertex)
		{
			BFS(i, cutVertex, type, graph, components, visit, c );
			c++;
		}
	}

}


int main()
{
	
	int test;
	cin>>test;
	while(test--)
	{
		long long n;
		int m,a,b;
		int q1,q2;
		cin>>n>>m>>a>>b;

		vector<int> v;
		vector<vector<int> > graph(n+1,v);
		vector<pair<int,int> > components(n+1,make_pair(-1,-1));
		for(int i=0;i<m;i++)
		{
			cin>>q1>>q2;
			graph[q1].push_back(q2);
			graph[q2].push_back(q1);
		}

		BFSComponent(a, 'a', n, graph, components);
		BFSComponent(b, 'b', n, graph, components);

		//cout<<"Test Case"<<endl;
		map<int,int> pp1;
		map<int,int> pp2;
		map<pair<int,int>, int> pp3;
		long long ans = (long long) (n-2)*(n-3)/2;
		for (int i = 1; i < n+1; ++i)
		{
			if(i==a || i==b) continue;
			pp1[components[i].first]++;
			pp2[components[i].second]++;
			pp3[components[i]]++;
		}
		for(auto kv: pp1) ans -= ((long long)kv.second*(kv.second -1))/2;
		for(auto kv: pp2) ans -= ((long long)kv.second*(kv.second -1))/2;
		for(auto kv: pp3) ans += ((long long)kv.second*(kv.second -1))/2;
		cout<<ans<<endl;
	}

	return 0;
}