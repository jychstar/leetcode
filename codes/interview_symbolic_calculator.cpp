// write a function that takes a string of arithmetic equation below and returns a scalar as the evaluation of the equation
// arithmetic supports 4 operators: +, *, &, |, where + and * are defined as usual, & and | are defined as pairwise max, min, respectively.
// your algorithm should handle space and decimal
// priority: &, | > * > +
// e.g. 1 & 2 | 3 * 4 * 5 + 6
//    = 2 | 3 * 4 * 5 + 6
//    = 2 * 4 * 5 + 6
//    = 46

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double calculate( string &s) {

        // 1st step, parse input string
        vector<double> nums;
        vector<char> syms;
        string snum = "1234567890.", ss = "&|*+";
        string temp = "";
        for (char ch : s) {
            if (ch == ' ')
                continue; // skip space
            if (snum.find(ch) != string::npos)
                temp += ch;  // accumulate number
            else if (ss.find(ch) != string::npos) {
                nums.push_back(stof(temp)); // covert number and store
                temp = ""; // reset temp
                syms.push_back(ch); // store symbol
            } else
                cout << "something unexpected!" << endl;
        }

        // handle the last element
        if (!temp.empty())
            nums.push_back(stof(temp));
        // check parsed results
        if (nums.size() != syms.size() + 1)
            cout << "numbers and operators not matched!" << endl;


        // 2nd step, calculate by the priority, so there will be 4 iterations.

        for (char key: ss){
            int i = 0;
            int length = syms.size(); // this number will change after each calculation.

            while (i < length) {
                if (syms[i] == key ) {
                    switch (key){
                        case '&': nums[i] = max(nums[i], nums[i + 1]); break;
                        case '|': nums[i] = min(nums[i], nums[i + 1]); break;
                        case '*': nums[i] *= nums[i + 1]; break;
                        case '+': nums[i] += nums[i + 1]; break;
                    }
                    // handle processed element:
                    nums.erase(nums.begin() + i + 1);
                    syms.erase(syms.begin() + i);
                    length--;
                    continue;
                }
                i++;
            }
        } // end for loop

        return nums[0];
    }
};


int main() {
    string s = "1 & 2 | 3 * 4 * 5 + 6.0";
    double res = Solution().calculate(s);
    cout << res <<endl;  // 46

    string s1 = "1 + 2 | 3 * 4 & 5.7 + 6.1";
    res = Solution().calculate(s1);
    cout << res << '\n'; //18.5

    return 0;
}
