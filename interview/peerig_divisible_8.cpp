#include <iostream>
#include <vector>
#include <map>
using namespace std;


bool check(string s){
    int n = s.size();
    if (n==1) {
        if ( stoi(s) % 8 == 0)
            return true;
    }
    if (n==2){
        if ( stoi(s) % 8 == 0)
            return true;
        swap(s[0],s[1]);
        if ( stoi(s) % 8 == 0)
            return true;
    }
    if (n==3){
        //char a = s[0], b= s[1], c= s[2];
        // vector<string> v = {a+b+c,a+c+b,b+a+c,b+c+a,c+a+b,c+b+a};
        vector<string> v;
        v.push_back(s);
        swap(s[1],s[2]); //acb
        v.push_back(s);
        swap(s[0],s[2]); //bca
        v.push_back(s);
        swap(s[1],s[2]); //bac
        v.push_back(s);
        swap(s[0],s[2]); //cab
        v.push_back(s);
        swap(s[1],s[2]); //cba
        v.push_back(s);
        for (string ss: v){
            // cout << ss <<"\t";
            if ( stoi(ss) % 8 == 0)
                return true;
        }
    }
    return false;
}

bool check4(string s){
    for (int i=0; i<s.size(); i++)
        for (int j=i+1; j<s.size(); j++)
            for (int k=j+1; k<s.size(); k++){
                string ss =""; // combine 3 char
                ss += s[i];
                ss += s[j];
                ss += s[k];
                cout << ss <<endl;
                if (check(ss))
                    return true;
            }
    return false;
}



vector < string > checkDivisibility(vector < string > arr) {
    vector<string> res;
    bool b;
    for (string s:arr){
        if (s.size()<=3)
            b = check(s);
        else
            b = check4(s);
        if (b)
            res.push_back("YES");
        else
            res.push_back("NO");
        }
    
    return res;
}

int main ()
{
    string s = "1678";
    vector<string> v ={"1687","321","16","22"};
    auto vv = checkDivisibility(v);
    for (auto ss:vv)
        cout << ss<<endl;
    return 0;
}
