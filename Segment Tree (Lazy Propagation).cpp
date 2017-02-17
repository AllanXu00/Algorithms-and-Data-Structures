int ar[30005], tree[100005], lazy[100005];
void prop (int n, int l, int r){
    tree[n] = max (tree[n]+lazy[n], 0);
    if (l != r){
        lazy[2*n+1] += lazy[n];
        lazy[2*n+2] += lazy[n];
    }
    lazy[n] = 0;
}
void build (int n, int l, int r){
	//cout << n << " " << l << ' ' << r << endl;
    if (l == r){
        tree[n] = ar[l];
        return;
    }
    build (2*n+1, l, (l+r)/2);
    build (2*n+2, (l+r)/2 + 1, r);
    tree[n] = min (tree[2*n+1], tree[2*n+2]);
}
void update (int n, int l, int r){
    if (lazy[n] != 0) prop (n, l, r);
    if (l > b || r < a) return;
    if (l >= a && r <= b){
        lazy[n] -= c; 
        prop (n, l, r);
        return;
    }
    update(2*n+1, l, (l+r)/2);
    update(2*n+2, (l+r)/2 + 1, r);
    tree[n] = min (tree[2*n+1], tree[2*n+2]);
}
int query(int n, int l, int r){
    if (lazy[n] != 0) prop (n, l, r);
    if (l > b || r < a) return 1<<30;
    if (l >= a && r <= b) return tree[n];
    return min(query (2*n+1, l, (l+r)/2), query (2*n+2, (l+r)/2 + 1, r));
}
