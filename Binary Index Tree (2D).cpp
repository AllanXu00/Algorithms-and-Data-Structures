ll bit[3005][3005];

void add(ll x, ll y, ll v) {
  for (int i = x; i <= m; i += i & -i)
    for (int j = y; j <= n; j += j & -j)
      bit[i][j] += v;
}
ll sum(ll x, ll y) {
  ll ret = 0;
  for (int i = x; i > 0; i -= i & -i)
    for (int j = y; j > 0; j -= j & -j)
      ret += bit[i][j];
  return ret;
}
ll tot(ll x1, ll y1, ll x2, ll y2) {
  return sum(x2, y2) + sum(x1 - 1, y1 - 1) -
         sum(x1 - 1, y2) - sum(x2, y1 - 1);
}
