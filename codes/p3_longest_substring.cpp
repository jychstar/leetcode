class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        vector<int> v(256,-1); // use converted char as index, position as value, all initial positions are 0
        int res = 0, pos = -1;
        for (int i= 0; i!= s.length();i++){
            int index = s[i]; // convert char to index of v
            if (v[index]> pos) // means duplicated char is found
                pos = v[index]; // update new boundary position
            v[index]=i;  // update position for each char
            //cout<< i << s[i] <<pos<<endl;
            res = max(res,i-pos);  // update max dynamically
        }
        return res;
    }
};