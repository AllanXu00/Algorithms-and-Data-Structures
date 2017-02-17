 int binary_search(){
    hi = lim;
    lo = 1;
    while (lo < hi){
        mid = lo + (hi - lo)/2;
        if (query(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo; 
 }
