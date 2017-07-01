
#include <vector>
#include <map>
vector < int > getMinimumDifference(vector < string > a, vector < string > b) {
    vector<int> res;
    for (int i=0; i<a.size();i++){
        if (a[i].size()!=b[i].size()){
            res.push_back(-1);
            continue;
        }

        string text1= a[i];
        string text2= b[i];
        map<char,int> m;
        int diff = 0;

/*  this doesn't work well because it highly depends on order
    sort( text1.begin(), text1.end() ) ;
    sort( text2.begin(), text2.end() ) ;
    */

        for (char ch: text1){
            if (m.find(ch) != m.end()) //found
                m[ch]+=1;
            else
                m[ch] =1;
        }
        for (char ch: text2){
            if (m.find(ch) != m.end()){
                m[ch]-=1;
                if (m[ch] == 0)
                    m.erase(ch);
            }else
                diff +=1;
        }
        
        res.push_back(diff);
    }
    return res;

}

