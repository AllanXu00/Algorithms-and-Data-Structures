bool visit[100005]; vector <int> graph[100005]; 

void dfs (int u, int dis){
    if (visit[u]) return; 
    visit[u] = true; 
    for (int i = 0; i < graph[u].size(); i++){
        dfs (graph[u][i], dis+1); 
    }
}
