#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <array>
#include <random>

using namespace std;

int solution(vector<int> &A, vector<int> &B, int M, int X, int Y) {
    // write your code in C++14 (g++ 6.2.0)
    int res = 0, num = 0, totw = 0;
    int weight,floor;
    vector<int> v(M+1,0);
    for (unsigned i= 0; i!= A.size();i++){
        //cout<< i <<"\t"  << num<<"\t"<< totw <<"\t" <<res <<endl;
        weight = A[i];
        floor = B[i];
        if (num <= X-1 && totw <= Y-weight){
            num++;
            totw += weight;
            if (v[floor] == 0){
                v[floor] = 1;
                res++;
            }
        }
        else{
            num = 1;
            totw = weight;
            fill(v.begin(), v.end(), 0);
            v[floor] = 1;
            res += 2; // add stop at ground
        }
    } // end loop through queue
    res ++; // back to ground
    return res;
}

int main(){

    vector<int> A = {60,80,40};
    vector<int> B = {2,3,5};
    cout << solution(A,B,5,2,200) <<endl;

    //vector<int> A = {40,40,100,80,20};
    //vector<int> B = {3,3,2,2,3};
    //cout << solution(A,B,3,5,200) <<endl;

    return 0;
}
