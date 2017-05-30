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
    bool isValid(string s) {
        vector<char> v;
        stack<char> st;  // store expected chars
        map<char,char> m;
        m['(']=')';
        m['[']=']';
        m['{']='}';
        string str1= "({[", str2=")}]";
        for (char ch:s){
            if (str1.find(ch) != string::npos)
                st.push(m[ch]);
            else if (str2.find(ch) != string::npos){
                if (st.size()==0) return false;
                char target = st.top();
                st.pop();
                if (ch != target) return false;
            }
            else
                continue;
        }
        return (st.empty());
    }
};


// To execute C++, please define "int main()"
int main() {
    auto words = { "Hello, ", "World!", "\n" };
    for (const string& word : words) {
        cout << word;
    }
    cout<< Solution().isValid("(({}))");
    return 0;
}