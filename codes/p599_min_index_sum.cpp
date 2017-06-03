
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> m1;
        for (int i= 0; i<= list1.size();i++)
            m1[list1[i]]= i;
        vector<string> s;
        int record = INT_MAX;

        for (int j=0; j<= list2.size();j++) {
            string key = list2[j];
            if (m1.find(key) != m1.end()) {
                int cur = m1[key] +j;
                if (j < record){
                    s.push_back(key);
                    record = j;
                }
                else if (j== record)
                    s.push_back(key);
                else
                    s.clear();
            }
        }

        return s;
    }
};

int main ()
{
    vector<string> s1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> s2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};

    vector<string> res = Solution().findRestaurant(s1,s2);
    for (auto item: res)
        cout << item <<endl;

    return 0;
}