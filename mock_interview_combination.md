# 1 recursive 

- input?
- output?
-  base/corner cases?
-  **solve problem**
-  runtime
-  space

```c++
class Solution {
public:
    int combination (int n, int k) {
        cout<<"calling:"<<n <<","<<k <<endl;
        if (n<k) return 0;
        if (n==k) return 1;
        if (k==1) return n;
        if (n-k==1) return n;
        return combination(n-1,k) + combination(n-1,k-1);
    }
};
```
note the runtime complexity is something between 2^(n-k) and 2^k.

The space complexity is proportional to the algorithm depth or height of the tree.

Of course this is not an optimal solution. something 2^33 will easily get computer running desparetly.  (32,16) will take 2 seconds.

factorial increases very fast,  13! will be larger then 2^32 so it's out of the range of int, which is the reason why we need to discuss the input and output before everything.

# dynamic programming

use matrix to calculate from bottom up, which only takes 60 us for (32,16). 

analysis: runtime and space are both n*k,

```c++
#include <assert.h>
#include <vector>
class Solution {
public:
    int combination (int n, int k) {
        assert(n>=0 && k>=0);
        if (n<k) return 0;
        vector<vector<int>> c(n+1,vector<int>(k+1,0));
        for (int i=1; i<= n;i++)
            for (int j=0;j<=k;j++){
                if (j==0)
                    c[i][j]=0;
                else if (j==1)
                    c[i][j]=i;
                else if (i-j==1)
                    c[i][j]= i;
                else
                    c[i][j]=c[i-1][j]+c[i-1][j-1];
            }
        return c[n][k];
    }
};
```

