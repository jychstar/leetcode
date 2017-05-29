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

    vector<string> letterCombinations(string digits) {
        vector<string> v = { "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits.empty()) return res;
        res.push_back(""); // initialize
        if (digits.size()==0) return res;
        for (char key: digits){
            cout<< key<<endl;
            int num = key - '0'; // convert char to single digit
            if (num<0 || num >9) break;
            string candidate = v[num];
            if (candidate.empty()) continue; //avoid clearing res
            vector<string> temp;
            for (char ch: candidate)
                for (string s: res)
                    temp.push_back(s+ch);
            swap(res,temp); // key step
        }

        return res;

    }
};

int main() {

    time_t timer0 = clock();
    auto so= Solution().letterCombinations("123");
    for (auto each:so)
        cout<< each <<endl;
    double t = difftime(clock(),timer0);
    cout <<"time in micro seconds: "<< t << endl;

    cout << '9'-'0' <<endl;
    return 0;

}