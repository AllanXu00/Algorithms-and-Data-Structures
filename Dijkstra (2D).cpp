ll n, m, st, en, a, b, t, s, h, x, y, hi, lo, mid; ll lim, dis, wor, ans;
vector <pair <ll, ll> > graph[10001];
priority_queue <pair <pair <ll, ll>, pair <ll, ll> > > q;
unordered_map <ll, bool> shrine; 
bool query (ll ob){
	priority_queue <pair<ll, pair <ll, ll> > > qu;
	ll dist[10001], worship[10001]; 
	for (int i = 0; i < 10001; i++) {dist[i] = 100000000000; worship[i] = 1000000000000; }
	qu.push(mp(0, mp(0, st))); 
	while (!qu.empty()){
		dis = -qu.top().first; 
		wor = -qu.top().second.first; 
		x = qu.top().second.second;
		qu.pop(); 
		//cout << x << ' ' << dis << ' ' << wor << endl; 
		if (dis > lim || wor > ob) continue; 
		if (x == en){
			return true; 
		}
		if (dis < dist[x] || wor < worship[x]){
			dist[x] = min (dist[x], dis);
			worship[x] = min (worship[x], wor);
			if (shrine[x]) wor = 0; 
			for (int i = 0; i < graph[x].size(); i++){
				qu.push(mp(-(dis + graph[x][i].second), mp(-(wor+graph[x][i].second), graph[x][i].first))); 
			}
		}
	}
	return false; 
}
