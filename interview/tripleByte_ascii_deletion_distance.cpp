#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <array>
#include <random>
#include <stack>
#include <queue>

using namespace std;

int ascii_deletion_distance(string str1, string str2){
    int second = 0;
    int len1 = str1.size(), len2 = str2.size();
    int res = 0;
    for (int i = 0; i< len1; i++){
        char ch = str1[i];
        res += int(ch);
        int j = second;
        while (j < len2){
            if (ch == str2[j]){
                second = j+1;
                res -= 2 * int (ch);
                cout << ch <<endl;
                break;
            }
            else
                j++;

        }
    } // end for loop
    for (char ch: str2)
        res += int(ch);
    return res;
}

int main(){

    cout << ascii_deletion_distance("at","cat") << endl;
    cout << ascii_deletion_distance("boat","got") << endl;
    cout << ascii_deletion_distance("thought","sloughs") << endl;  // wrong
    return 0;
}