#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <array>
#include <time.h>
#include <assert.h>

using namespace std;

class Solution {
public:
    map<char,vector<char>> d;
    Solution(){
        d['0']={' '};
        d['1']={'*'};
        d['2']={'a','b','c'};
        d['3']={'d','e','f'};
        d['4']={'g','h','i'};
        d['5']={'j','k','l'};
        d['6']={'m','n','o'};
        d['7']={'p','q','r','s'};
        d['8']={'t','u','v'};
        d['9']={'w','x','y','z'};
    }

    vector<string> letterCombinations(string digits) {

        vector<string> res;
        if (digits.size()!=0)
            helper(digits,0,"",res);
        return res;
    }

    void helper(string digits,int level,string cur,vector<string> &res){
        if (level== digits.size())
            res.push_back(cur);
        for (char ch: d[digits[level]]){
            cur += ch;
            helper(digits,level+1,cur,res);
            cur.erase (cur.size()-1);
        }

    }
};

int main() {

    time_t timer0 = clock();
    auto so= Solution().letterCombinations("23");
    for (auto each:so)
        cout<< each <<endl;
    double t = difftime(clock(),timer0);
    cout <<"time in micro seconds: "<< t << endl;

    return 0;

}