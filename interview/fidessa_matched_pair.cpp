#include <iostream>
#include <vector>
#include <map>
using namespace std;

#include <stack>
int findMatchingPair(string input) {
    int res=-1;
    stack<char> s;
    char ch = input[0];
    if (ch>=65 && ch <=90)
        s.push(ch);
    else
        return res;
    for (int i=1;i<input.size();i++){
        ch = input[i];
        if (ch>=65 && ch <=90)
            s.push(ch);
        else if (ch>=97 || ch<=112) {
            if (s.empty())
                return res;
            char up = s.top();
            //cout << int(up)<<endl;
            //cout << int(ch)<<endl;
            if (up + 32 == ch){
                res = i;
                s.pop();
                continue;
            }
            else
                return res;
        }
    } // end loop through input
    return res;
}

int main ()
{
    char a = 'a';
    //string s = "ABab";
    string s = "ABba";
    cout << findMatchingPair(s) <<endl;
    cout <<a <<endl;

    return 0;
}
