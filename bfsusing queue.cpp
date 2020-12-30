/* we can utilize the bfs using c++ stl by using queue in following ways
in BFS we first start with a node 
1. first create a queue and enqueue the source to the queue and mark each source as visited
2. while queue is not empty do the following
a) dequeue a vetex from the queue. let this be F
b) print F
c) enqueue all not yet visited adjecent of F and mark them visited.
*/
#include<bits/stdc++.h>
using namespace std;
std::vector<bool> v;
std::vector<std::vector<int> > g;
void edge(int a , int b)
{
	g[a].push_back(b);
}
void bfs(int u)
{
	queue<int> q;
	q.push(u);
	v[u]=true;
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		cout<<f<<" ";
		for(auto i=g[f].begin();i!= g[f].end();i++)
		{
			if(!v[*i])
			{
				q.push(*i);
				v[*i]=true;
			}
		}
	}
}
//driver code
int main()
{
	int n,e;
	cin>>n>>e;
	v.assign(n,false);
	g.assign(n,std::vector<int>());
	int a,b;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		edge(a,b);
	}
	for(int i=0;i<n;i++)
	{
		if(!v[i])
			bfs(i);
	}
	return 0;
}