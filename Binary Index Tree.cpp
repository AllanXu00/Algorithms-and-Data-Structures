ll bit[1000005];
void update(ll a, ll b) { 
    while (a <= 1000005){ 
    	//cout << a << endl;
        bit[a] += b; 
        a += (a & -a); 
    } 
}

long long add(ll a){
    ll sum = 0; 
    while (a > 0){
        sum += bit[a];
        a -= (a & -a);
    } 
    return sum;
}
