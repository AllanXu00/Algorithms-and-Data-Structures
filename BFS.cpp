#include <bits/stdc++.h>
using namespace std;

#define inf 1<<30
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

queue <pair <int, int> > q;
bool visit[100005]; vector <int> graph[100005];
q.push(make_pair (1, 0)); int x, dis;

int main() {

    while (!q.empty()){
        x = q.front().first;
        y = q.front().second;
        if (visit[x]) continue;
        visit[x] = true;
        if (x == n){
            cout << dis << endl;
            return 0;
        }
        for (int i = 0; i < graph[x].size(); i++){
            q.push(make_pair(graph[x][i], dis+1));
        }
    }
	return 0;
}
