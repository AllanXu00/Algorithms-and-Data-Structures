int KMP(string s, string p){
	if (s.size() < p.size()) return -1;
    int nxt[2005], i=1, j=-1; nxt[0]=-1;
    for(; i<p.size(); i++){
        while(j>=0 && p[j+1]!=p[i]) j=nxt[j];
        nxt[i] = (p[j+1]==p[i]? ++j:j);
    }
    for(i=0, j=-1; i<s.size(); i++){
        while(j>=0 && p[j+1]!=s[i]) j=nxt[j];
        if(p[j+1]==s[i]) ++j;
        if(j==p.size()-1) return i-p.size()+1;
    }
    return -1;
}
