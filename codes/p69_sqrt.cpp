
class Solution {
public:
    int mySqrt(int x) {
        if (x==0)
            return 0;
        int left = 0, mid,right;
        if (x >= 46340*46340)
            return 46340; // upper limit value in (0, INT_MAX)
        else
            right = min (x,46339);

        while (left < right){
            mid = (left+ right)/2;
            //cout<< left <<"\t" << right <<endl;
            if (mid*mid <= x){
                if ((mid+1)*(mid+1) > x)
                    return mid;
                else
                    left = mid+1;
            }
            else
            if ((mid-1)*(mid-1) <= x)
                return mid-1;
            else
                right = mid-1;

        }
        return (left+right)/2;
    }
};
