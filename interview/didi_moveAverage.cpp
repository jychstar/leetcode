#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <array>
#include <random>
#include <stack>
#include <queue>

using namespace std;

// Computes the average of a sliding window.
class MovingAverage {
public:
    double cur; //current sum
    int curlen; //current len
    //bool _isfull;
    int _size;
    queue<int> q;
    MovingAverage(int size);
    double GetAverage(int n);
};


MovingAverage::MovingAverage(int size){
    _size = size;
    cur = 0;
    curlen = 0;
   // _isfull = false;

}

double MovingAverage::GetAverage(int n){
    q.push(n);
    cur += n;
    curlen++;

    if (curlen <= _size){
        return cur/curlen;
    }
    else {
        cur -= q.front();
        q.pop();
        return cur/_size;
    }


}

int main(){

    MovingAverage ma(3);
    cout<< ma.GetAverage(5) <<endl;
    cout<< ma.GetAverage(2) <<endl;
    cout<< ma.GetAverage(8) <<endl;
    cout<< ma.GetAverage(2) <<endl;
}