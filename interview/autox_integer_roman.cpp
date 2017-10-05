#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> nums = {1000,900,500,400, 100,  90, 50, 40,  10,  9,   5,  4,  1};
    vector<string> vs ={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int num = 416;
    int index = 0;
    string s;
    while (num>0)
        if(num >= nums[index]){
            num -= nums[index];
            s +=vs[index];
        }
        else
            index++;

    cout << s<<endl;
    return 0;
}