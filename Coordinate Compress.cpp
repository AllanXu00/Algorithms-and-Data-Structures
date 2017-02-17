vector <long long> comp; map <long long, int> f; 
void compress(){
  sort (comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for (int i = 0; i < comp.size(); i++){
		f[comp[i]] = i; 
	}
}
