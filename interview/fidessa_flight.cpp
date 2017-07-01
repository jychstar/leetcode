/*
 * Complete the function below.
 */
#include <vector>
int findMinGates(vector < int > arrivals, vector < int > departures, int flights) {
    int res = 1;
    sort(   arrivals.begin(),   arrivals.end() ) ;
    sort( departures.begin(), departures.end() ) ;
    
    for (int i=0; i<flights-1;i++){
        int cur = 1;
        int dep = departures[i]; 
        for (int j=i+1; j< flights; j++){
            if (arrivals[j]<= dep)
                cur++;
        }
        res = max(cur,res);
        
    }
    return res;

}

