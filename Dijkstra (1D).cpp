#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector < pair <int, int> > graph [1100];
int dist[1100]; 
int a, b, c, d, e, x, y, dis;
pair <int, int> pa;
priority_queue <pair<int, int> > qu;

int main() {
	
	for (int i = 0; i < 1100; i++) dist[i]=1000000;
	cin >> a >> b;
	for (int i = 0; i < b; i++)
	{
		cin >> c >> d >> e; 
		pa.first = e; 
		pa.second = d;
		graph [c].push_back(pa);
	}
	//cout << "runtime" << endl;
	pa.first = 0; 
	pa.second = 1;
	qu.push(pa);
	while (!qu.empty())
	{
		x = qu.top().second;
		dis = -qu.top().first;
		qu.pop();
		if (dist[x]<dis) continue;
		else dist[x]=dis;
		for (int i = 0; i < graph[x].size(); i++)
		{
			pa.first = -(dis+graph[x][i].first);
			pa.second = graph [x][i].second;
			qu.push(pa);
		}
	}
	cout << dist[a] << endl;
	
	return 0;
}
//Solves: http://wcipeg.com/problem/graph3p2
