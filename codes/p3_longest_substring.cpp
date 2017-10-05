#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        vector<int> v(256,-1); // use char's ascii value as index, initial all positions as 0
        int res = 0, pos = -1;
        for (int i= 0; i!= s.length();i++){
            int index = s[i]; // convert char to index of v
            pos = max (pos, v[index]); // update boundary if it goes past old boundary
            v[index]=i;  // update position for each char
            //cout<< i << s[i] <<pos<<endl;
            res = max(res,i-pos);  // update max dynamically
        }

        //res = max(res, int(s.length()-1-pos));
        return res;
    }
};

int main(){

    cout <<Solution().lengthOfLongestSubstring("hello") << endl;

    return 0;
}