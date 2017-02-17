bool hungary (int u){
    for (int i = 0; i < graph[u].size(); i++){
        if (!visit[graph[u][i]]){
            visit[graph[u][i]] = true;
            if (pre[graph[u][i]] == 0|| hungary(pre[graph[u][i]])){
                pre[i] = u; return true;
            }
        }
    }
    return false;
}
