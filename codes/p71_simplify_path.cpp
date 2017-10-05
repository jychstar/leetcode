#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss,tmp,'/')){
            if (tmp == "" || tmp == ".") // current directory
                continue;
            if (tmp == ".." && !stk.empty())  // upper level drectory
                stk.pop_back();
            else if (tmp!="..")   // valid directory
                stk.push_back(tmp);
        }
        for (string str:stk)
            res += "/"+ str;

        return res.empty()? "/": res;
    }
};

int main()
{
    vector<int> v = {3,3,4};
    vector<int> w(v);

    cout << Solution().simplifyPath("/a/./b/../../c/") <<endl;

    return 0;
}