#include <iostream>
#include <vector>
using namespace std;

void max_insert(vector<int> & heap, int element){
    heap.push_back(element);
    size_t index = heap.size()-1;
    while( (index>1)&&(heap[index]>heap[index/2])){
        swap(heap[index],heap[index/2]);
        index /=2;
    }

}

vector<int> max_create(){
    return {0};
}

int main (){
    vector<int> h = max_create();
    max_insert(h,3);
    max_insert(h,6);
    max_insert(h,4);
    max_insert(h,8);
    max_insert(h,4);
    max_insert(h,7);

    for (auto item:h)
    	cout <<item<<endl;  // 0,8,6,7,3,4,4
    return 0;
}

// After thought: the swap algorithm is a little weird. However, it can ensure the max value is at index=1 position