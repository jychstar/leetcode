

#include <iostream>
#include <vector>
using namespace std;

struct wackstack{
    vector<int> ws;
    size_t cap;
    size_t cur;
    void init(size_t capacity){
        cap = capacity;
        cur = 0;
        cout << "EMPTY" <<endl;
    }
    void push(int num){
        if (cur<cap){
            ws.push_back(num);
            cur++;
        }
        cout << ws[cur-1] <<endl;
    }
    void pop(){
        if (cur>0){
            ws.erase(ws.end()-1);
            cur--;
        }
        if (cur==0)
            cout << "EMPTY" <<endl;
        else
            cout << ws[cur-1] <<endl;
    }
    void bump(int offset,int count, int delta){
        for (int i= cur-offset-count; i< cur-offset;i++)
            ws[i] += delta;
        if (cur==0)
            cout << "EMPTY" <<endl;
        else
            cout << ws[cur-1] <<endl;
    }
};


int main ()
{
    wackstack w;
    w.init(1000);
    w.push(123);
    w.push(456);
    w.bump(1,1,666);
    w.pop();
    w.push(222);
    w.bump(0,1,333);
    w.pop();
    w.pop();

    return 0;
}
