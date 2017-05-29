#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['M']= 1000;
        m['D']= 500;
        m['C']= 100;
        m['L']= 50;
        m['X']= 10;
        m['V']= 5;
        m['I']= 1;

        int last = 3999, temp =0;
        int res = 0;
        for (char c:s){
            temp = m[c];
            res = temp > last? res+temp-last*2 : res+temp; // deal with IX
            last = temp;
        }
        return res;
    }
};

int main() {
   vector<int> v = {1,2,1,2,4};
    string s = "DCXXI";
    //for (int i=0; i!=s.size();i++)
      //  cout<<s[i]<<endl;
    array<int,3> a= {1,2,3};
    for (int a: a)
        cout<<a <<endl;

    cout<< Solution().romanToInt(s) <<endl;

    return 0;

}

