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

ll n, d, x, y, t1, t2, ar[1000005]; deque <pair <ll, ll> > q; 

int main() {
	scan(n); scan(d); 
	for (int i = 0; i < n; i++) scan(ar[i]);
	q.push_front(mp(0, ar[0])); 
	for (int i = 1; i < n; i++){
		while (i - q.front().first > d && !q.empty()) q.pop_front();
		x = q.front().first; y = q.front().second;
		while (q.back().second > ar[i]+y && !q.empty()) q.pop_back(); 
		q.push_back(mp(i, ar[i]+y)); 
	}
	printf ("%lld\n", q.back().second); 
	return 0;
}
//http://wcipeg.com/problem/smac081p3
//Solves this question
