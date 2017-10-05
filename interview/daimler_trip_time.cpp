#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    
    string row;
    cin >> row; // headline
    map<string,long> m_stamp;
    map<string,long> m_duration;

    map<string,int> m_count;
    //string state =""; 
    
    // read line by line
    while (cin>>row){
        //cout << row <<endl;
        string vin ="";
        long stamp = 0;
        string temp ="";
        //vector<string> v;
        int cnt = 0;
        for (char ch: row){
            if (ch == ' ')
                continue;
            else if (ch == ';' && cnt==0){
                vin = temp;
                cnt +=1;
                temp = "";
            }
            else if (ch == ';' && cnt==1){
                stamp = stol(temp);
                break;    
            }
            else 
                temp +=ch;
        } // end for-loop
        //cout << vin <<" " <<stamp<<endl;
        
        // process parsed data
        if (m_stamp.find(vin)== m_stamp.end()){ // first record
            m_stamp[vin] = stamp;
            m_duration[vin] = 0;
            m_count[vin] = 0;
            continue;
        }
        if (stamp == m_stamp[vin]) // duplicated record
            continue;
        if (m_stamp[vin]==0)
            m_stamp[vin] = stamp; // new record
        else{
            m_duration[vin] += stamp - m_stamp[vin];
            m_stamp[vin] = 0;
            m_count[vin] +=1;
        }
            
            
    } // end while loop
    
    for (map<string,int>::iterator i = m_count.begin(); i!=m_count.end(); i++){
        string vin = i->first;
        double ave = m_duration[vin]/m_count[vin];
        
        cout<< vin
            << " "
            << ave<<endl;
    } 
    
    return 0;
}