#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <deque>
#include <array>
#include <queue>
#include <time.h>

using namespace std;

int find_needle(string needle, string haystack){
    map<char,int> m;
    int length = needle.size();
    for (char ch: needle) {
        if (m.find(ch) != m.end()) {
            m[ch] += 1;
        } else {
            m[ch] = 1;
        }
    }
    if (haystack.size()< length){
            return -1;
        }
    for (int ini = 0; ini!=haystack.size()-length+1;ini++){
            string sub = haystack.substr(ini,length);
            //cout << sub <<endl;
            map<char,int> m1= m;
        /*
            for (map<char,int>::iterator i=m1.begin();i!=m1.end();i++)
                cout << i->first
                     <<":"
                     << i->second <<endl;
        */
            bool found = true;
            for (char ch: sub){
                if(m1.find(ch)!= m1.end()){
                    //cout << ch <<endl;
                    m1[ch]-=1;
                    if (m1[ch] ==0){
                        m1.erase(ch);}

                }
                else
                { found = false;
                    break;}
            } //
            if (found){
                return ini;
            }

        }
        return -1;

    }



int main() {
/*
 * needle: ‘abcbd’
haystack: ‘befbbacd…’
return: 3
 */
    time_t timer0 = clock();
    cout << find_needle("abcbd","befbbacd") <<endl;

    double t = difftime(clock(),timer0);
    cout<<"time in micro seconds: "<< t <<endl;

    return 0;

}