#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;

#define mp make_pair
#define pb push_back
int n, m, x=1, y, t, root[800];
double dis, gdis, tmp;
pair <int, pair<int, int> > ar[800];
vector <pair <double, pair <int, int> > > E;
vector <pair <int, int> > sol;
priority_queue <pair <double, pair <int, int> > > q;
bool visit[800], side[800][800];

int find_root(int x){
	if (root[x] != x){
		root[x] = find_root(root[x]);
	}
	return root[x];
}

double kruskal(int nodes) {
  sol.clear();
  sort(E.begin(), E.end());
  int u, v;
  double total_dist = 0;
  for (int i = 0; i <= nodes; i++) root[i] = i;
  for (int i = 0; i < (int)E.size(); i++) {
    u = find_root(E[i].second.first);
    v = find_root(E[i].second.second);
    if (u != v) {
      if (E[i].first != 0)sol.push_back(E[i].second);
      total_dist += E[i].first;
      root[u] = root[v];
    }
  }
  return total_dist;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		ar[i].first = i;
		scanf("%d%d", &ar[i].second.first, &ar[i].second.second);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++){
		scanf("%d%d", &x, &y);
		E.pb(mp(0, mp(x, y)));
		side[x][y] = true; side[y][x] = true;
	}
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			if (i != j && !side[i][j]){
				tmp = sqrt(pow((ar[i].second.first - ar[j].second.first), 2)+
					  pow((ar[i].second.second - ar[j].second.second), 2));
				E.pb(mp(tmp, mp(i, j)));
			}
		}
	}
	printf ("%.2f\n", kruskal(n));
	for (int i = 0; i < sol.size(); i++){
		printf ("%d %d\n", sol[i].first, sol[i].second);
	}
	return 0;
}
// Solves: http://wcipeg.com/problem/ccc02s2p5
