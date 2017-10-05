#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <array>
#include <random>

using namespace std;

string solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    bool cont = true;
    map<string,string> m;
    m["AB"] = "AA";
    m["BA"] = "AA";
    m["CB"] = "CC";
    m["BC"] = "CC";
    m["AA"] = "A";
    m["CC"] = "C";

    string key;

    random_device r;
    default_random_engine e1(r());

    while (cont){
        vector<int> v;
        for (int i=0; i< S.size()-1;i++){
            key = S.substr(i,2);
            if (m.find(key)!= m.end())
                v.push_back(i);
        }
        if (v.size()==0)
            break;
        uniform_int_distribution<int> uniform_dist(0, v.size()-1);
        int index = uniform_dist(e1);
        key = S.substr(v[index],2);
        S.replace(v[index],2,m[key]);

    }

    return S;
}


int main(){
    /*
    std::string base="this is a test string.";
    std::string str2="n example";
    std::string str3="sample phrase";
    std::string str4="useful.";

    std::string str=base;           // "this is a test string."
    str.replace(9,5,str2);          // "this is an example string." (1)
    str.replace(19,6,str3,7,6);     // "this is an example phrase." (2)
    str.replace(8,10,"just a");     // "this is just a phrase."     (3)
    str.replace(8,6,"a shorty",7);  // "this is a short phrase."    (4)
    str.replace(22,1,3,'!');        // "this is a short phrase!!!"  (5)

    std::random_device r;
    std::default_random_engine e1(r());
    int n =3;
    std::uniform_int_distribution<int> uniform_dist(0, 0);
    int mean = uniform_dist(e1);
    std::cout << "Randomly-chosen mean: " << mean << '\n';
     */
    string S = "ABBCC";
    cout << solution(S) <<endl;

    return 0;
}
