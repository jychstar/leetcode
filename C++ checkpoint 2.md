notes:

- class member is private by default, struct member is public by default
- all points should be initialized. Each pointer only takes 32 bit or 64 bit memory depending on the hardware/OS
- object pointer must use arrow `->` to access the class method and member.

## vector vs array

- it's recommend to use vector not array ( no matter c style or std::array) because array is error-prone.  
- use `size()` to to get size of a std::vector or std:array object. For c style array, there are 2 ways:   `sizeof(list) / sizeof(list[0])` or distance(begin(list),end(list))
- for std::vector, you can `push_back(value)` or `insert(iterator,value)` and  `erase(iterator)` 

## map

```c++
#include<iostream>
#include <map>
using namespace std;
int main() {
    map<string, int> m;
    m["hello"] = 23;
    m["world!"] = 24;
    m["fuck"] =25;
    // check if key is present
    if (m.find("world!") != m.end())
        std::cout << "map contains key world!\n";
    // use iterator to loop through
    for (map<string,int>::iterator i = m.begin(); i!=m.end(); i++){
        cout<< i->first
            << ":"
            << i->second<<endl;
    }
    // use foreach loop to loop through
    for (auto &i :m){
        cout<< i.first
            << ":"
            << i.second<<endl;
    }
    return 0;
}
```

There is a similar map called `unordered_map`, where the keys are randomly orgainized so the insertion is faster.

## auto and lambda

```c++
auto a = 1+1;
std::cout << "type of a: " << typeid(a).name() << '\n';

auto my_lambda = [](int x) { return x + 3; };
std::cout << "my_lambda: " << my_lambda(5) << '\n';
```

## sort c style array and vector by iterator

```c++
const int SIZE = 7;
int main(){
    int intArray[SIZE] = {5, 3, 32, -1, 1, 104};
    sort(intArray, intArray + SIZE); 
    cout << "Sorted Array looks like this." << endl;
    for (int i = 0; i != SIZE; ++i)
        cout << intArray[i] << " ";
  	vector<int> v ={5,3,32,7};
  	sort(v.begin(), v.end());
    return 0;
}
```

## c++ vs ++c

The following example illustrate how it works.

```c++
int i=0, j=0;
int before = ++i, after = j++;
cout << i <<j << before <<after;
// get 1110
```

So it is better to avoid use c++ because its value is not consistent with the assign variable and will lead to well-hidden errors. 

## unique of vector

```c++
vector<int> v ={1,1,2,2,3,3};
sort(v.begin(),v.end());
auto redund = unique(v.begin(),v.end()); //iterator
for (auto i: v)
    cout<<i<<"\t";
cout<<endl;
v.erase(redund,v.end()); // remove residual
for (auto i: v)
    cout<<i<<"\t";
```

Note :

1. `sort` the vector because `unique` only remove duplicate elements if they're neighbors.
2.  `unique`  only does half the job: move the unique elements to the front and return the pointer of the first redudant elements. 
3.  `erase` the redundant elements.

`unique` is actually equivalent to the following codes:

```c++
vector<int>::iterator u = v.begin();
for (auto i =u; i!=v.end();i++)
  if (*u != *i)
    *(++u) = *i;
return ++u; 
```

## 2D vector

```c++
vector<vector<int> > ary(row_num, vector<int>(col_num, 0));
```

