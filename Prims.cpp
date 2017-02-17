#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector <pair <pair <int, int>, pair <int, int> > > graph [110];
pair <pair <int, int>, pair <int, int> > pa; 
priority_queue <pair <pair <int, int>, pair <int, int> > > qu;
int a, b, c, x, y, z, dan, co, gco, gdan;
vector <int> ans;
bool visit [110];

int main() {
	cin >> a >> b; 
	memset (visit, false, sizeof visit);
	for (int i = 0; i < b; i++)
	{
		cin >> x >> y >> co >> dan; 
		pa.first.first = dan;
		pa.first.second = co;
		pa.second.first = x;
		pa.second.second = 0;
		graph[y].push_back(pa);
		pa.second.first = y; 
		graph[x].push_back(pa);
	}
	pa.first.first = 0; 
	pa.first.second = 0; 
	pa.second.first = 1;
	pa.second.second =0;
	qu.push(pa);
	
	while (!qu.empty())
	{
		dan = -qu.top().first.first;
		co = -qu.top().first.second;
		x = qu.top().second.first; 
		qu.pop();
		
		
		if (!visit [x])
		{
		gdan+=dan;
		gco+=co;
			for (int i = 0; i < graph[x].size(); i++)
			{
				if (!visit [graph[x][i].second.first])
				{
					pa.first.first = -graph[x][i].first.first;
					pa.first.second = -graph [x][i].first.second;
					pa.second.first = graph[x][i].second.first;
					//cout << graph[x][i].second.first << endl;
					qu.push(pa);
				}
				
			}
			visit [x]=true;
		}
		else
		{
			ans.push_back(co);
		}
		//cout << x << " " << co << " " << gco << endl;
	}
	
	cout << gdan<< " " << gco; 
	return 0;
}
//Solves: http://wcipeg.com/problem/graph3p3
