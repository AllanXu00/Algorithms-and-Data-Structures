#include <bits/stdc++.h>
using namespace std;

#define inf 1<<30
#define ll long long
#define mp make_pair
#define pb push_back
#define BLOCK 555
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

struct node {ll l, r, val;} line[200005];
ll n, q, t, l, r, curl=1, curr=0, tmp, a[200005], ver[200005], ans[200005];

bool cmp(node x, node y) {
	if(x.l/BLOCK != y.l/BLOCK) {
		return x.l/BLOCK < y.l/BLOCK;
	}
	return x.r < y.r;
}
int main() {
	scan(n);
	for (int i = 1; i <= n; i++) scan(a[i]);
	scan(q);
	for (int i = 0; i < q; i++){ scan(line[i].l); scan(line[i].r); line[i].val = i; }
	sort (line, line+q, cmp);
	for (int i = 0; i < q; i++){
		l = line[i].l; r = line[i].r;
		while (curr < r){
			curr++;
			ver[a[curr]]++;
			if (ver[a[curr]] %2 == 1 && ver[a[curr]] > 1) tmp--;
			else if (ver[a[curr]] != 0 && ver[a[curr]]%2== 0) tmp++;
		}
		while (curr > r){
			ver[a[curr]]--;
			if (ver[a[curr]] %2 == 1) tmp--;
			else if (ver[a[curr]] != 0 && ver[a[curr]]%2== 0) tmp++;
			//tmp = max (tmp, 0LL);
			curr--;
		}
		while (curl < l){
		  ver[a[curl]]--;
			if (ver[a[curl]] %2 == 1) tmp--;
			else if (ver[a[curl]] != 0 && ver[a[curl]]%2== 0) tmp++;
			curl++;
		}
		while (curl > l){
			curl--;
			ver[a[curl]]++;
			if (ver[a[curl]] %2 == 1 && ver[a[curl]] > 1) tmp--;
			else if (ver[a[curl]] != 0 && ver[a[curl]]%2== 0) tmp++;
		}

		ans[line[i].val] = tmp;
	}
	for (int i = 0; i < q; i++) printf ("%lld\n", ans[i]);
	return 0;
}
