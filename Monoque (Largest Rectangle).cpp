ll solve (){
	ll a=0, t=0;
	deque <pair <ll, ll> > dq; 
	for (int i = 0; i <= c; i++){
        dif = 0; 
        while (ar[i] < dq.front().first){
            x = dq.front().first; 
            y = dq.front().second; 
            t = x * (i-y); 
            dq.pop_front(); 
            a = max (a, t);
            dif++; 
        }
        dq.push_front(mp(ar[i], i-dif)); 
    }
	return a; 
}
