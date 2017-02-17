int ar[100005], tree[500005];

void build (int n, int l, int r){
	if (l == r){
		tree[n] = ar[l]; 
		return; 
	}
	build (2*n+1, l, (l+r)/2);
	build (2*n+2, (l+r)/2+1, r); 
	tree[n] = min (tree[2*n+1], tree[2*n+2]); 
	return; 
}
void update (int n, int l, int r){
	if (l == x && r == x){
		tree[n] = y;
		return; 
	}
	else if (l > x || r < x) return;
	else{
		update (2*n+1, l, (l+r)/2);
		update (2*n+2, (l+r)/2+1, r);
	}
	tree[n] = min (tree[2*n+1], tree[2*n+2]); 
}

int query (int n, int l, int r){
	if (l >= x && r <= y){
		return tree[n]; 
	}
	else if (l > y || r < x) return 1<<30; 
	else{
		return min(query(2*n+1, l, (l+r)/2), query (2*n+2, (l+r)/2+1, r)); 
	}
}
