 int binary_search(){
    int hi = 100000000, lo = 1; 
    hi = lim;
    lo = 1;
    while (lo < hi){
        mid = lo + (hi - lo)/2;
        if (query(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo; 
 }
