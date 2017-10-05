#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <deque>
#include <array>
#include <queue>

using namespace std;

string intToRoman(int num) {
    if (num>=4000 || num <=0)
        cout <<"out of range" <<endl;
    string res = "";
    map<int, string,greater<int>> m;  // size 7 -> 13
    m[1000] = "M";
    m[900] = "CM";
    m[500] = "D";
    m[400] = "CD";
    m[100] = "C";
    m[90] = "XC";
    m[50] = "L";
    m[40] = "XL";
    m[10] = "X";
    m[9] = "IX";
    m[5] = "V";
    m[4] = "IV";
    m[1] = "I";

    for (map<int,string,greater<int>>::iterator i=m.begin(); i!=m.end();i++){
        int key = i->first;
        while (num>= key){
            res += i->second;
            num -= key;
        }
    }
    return res;
}

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

int main() {

    string s = intToRoman(999);
    cout<< s <<endl;
    cout<< romanToInt(s) <<endl;
    return 0;

}