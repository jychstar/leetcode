#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <array>
#include <time.h>
#include <assert.h>
#include <stack>
#include <regex>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, dis = 0;
        int dis1,dis2, temp;
        for (int i= 0; i!= s.size(); i++){
            dis1 = expand(s,i,i);   // even distance
            dis2 = expand(s,i,i+1); // odd distance
            temp = max(dis1,dis2);

            if (temp > dis){
                dis = temp;
                start = (dis%2==0) ? i-dis/2 : i-(dis-1)/2;
                cout << start << dis <<endl;
            }
        }
        return s.substr(start,dis+1);
    }

    int expand (string &s, int left, int right){
        while (left>=0 && right<s.size() &&  s[left] == s[right]){
            left--;
            right++;
        }
        return right -left -2;
    }
};

int main()
{
    vector<int> v = {3,3,4};
    cout << Solution().longestPalindrome("babad")<<endl;
    return 0;
}