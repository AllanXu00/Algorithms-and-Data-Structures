#include <bits/stdc++.h>
using namespace std;
const int M=3000002;
int T, N, K, a[M]; deque<int> Q1, Q2;
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d %d", &N, &K);
    for(int i=1; i<=N; i++)
        scanf("%d", &a[i]);
    long long ans = 0;
    for(int l=1, r=1; r<=N; r++){
        while(!Q1.empty() && a[r]<Q1.back()) Q1.pop_back();
        while(!Q2.empty() && a[r]>Q2.back()) Q2.pop_back();
        Q1.push_back(a[r]); Q2.push_back(a[r]);
        while(!Q1.empty() && !Q2.empty() && Q2.front()-Q1.front()>K){
            if(Q1.front()==a[l]) Q1.pop_front();
            if(Q2.front()==a[l]) Q2.pop_front();
            l++;
        }
        ans += (r-l+1);
    }
    printf("%lld\n", ans);
}
// Solves: https://dmoj.ca/problem/dmopc15c6p5
