class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <2) return 0;
        int result= 0, area=0;
        auto left = height.begin(), right= height.end()-1;
        while (left <right){
            area = distance(left,right)*min(*left,*right);
            result = max(result,area);
            if (*left < *right)
                left++;
            else
                right--;
        }
        return result;
    }
};