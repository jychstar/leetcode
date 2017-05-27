C++ for programmers: https://classroom.udacity.com/courses/ud999/

This course is still in development and welcome feedback to Catherine Gamboa (catherine@udacity.com).

Interview with Bjarne Stroustrup, creator of C++. Topic on what's C++, why learn C++, where is C++ used. **C++ work directly with hardware and is very fast**.

Comments should be added to explain **what the code does at a higher level and why we do so**.

Teach the concept in concrete examples. People don't get abstract idea without examples.

Study [C++ Guidelines](https://github.com/isocpp/CppCoreGuidelines) by Bjarne

You shouldn't be obsessive by little thing. Get a big picture because things have to work together. 

[C++ Programming Language, 4th Edition](https://www.amazon.com/C-Programming-Language-4th/dp/0321563840), 2013 by Bjarne. \$ 46.

[Programming: Principles and Practice Using C++](https://www.amazon.com/Programming-Principles-Practice-Using-2nd/dp/0321992784/ref=dp_ob_title_bk) , 2014. recommend to beginners.

## getting started

Tips from instructor Catherine:

1. learning to program by doing
2. quiz based learning; look at the answer when you get stuck
3. it's for students who know how to code in other language.

3 parts:

1. quickly go through something unique to c++
2. slow down to some topics such as pointers
3. classes and inheritance.

For more information on the standard library visit: [C++ Standard Library](http://www.cplusplus.com/reference/)

```c++
#include <iostream>
using namespace std; // standard library
int main() {
  cout << "Hello world, I am ready for C++";
  cout<<"size of a data type: "<<sizeof(int)<<endl;
  const float pi = 3.14;
  return 0;
}
```

### IDE

Download Clion, use student version. 

UI theme can be changed at preference -> appearance 

toolchains: CMake 3.7.2, debugger: bundled LLDB 3.9.0. 

C++ compiler: /Library/Developer/CommandLIneTools/usr/bin/c++

### compile and run without IDE

```shell
g++  main.cpp -o main.out  # default name is a.out
./main.out input.txt
```

### style guide

There are a number of style guides available, **the best one is the one used by the people who are paying you**.

A straightforward style guide is:
​               [Modern C++ Coding Guidelines](https://github.com/Microsoft/AirSim/blob/master/docs/coding_guidelines.md)

For a more detailed guideline:
​               [Google C++ Style Guideline](https://google.github.io/styleguide/cppguide.html)

## file io

```c++
#include <iostream>
#include <fstream>
using namespace std;
int main () {
    string line;
    //create an input stream to write to the file
    ifstream file ("input.txt");
    if (file.is_open()) {
        while ( getline (file,line)){
            cout << line << '\n';
        }
        file.close();
    }
    else cout << "Unable to open file for reading";
    return 0;
}
```

Header file `#include "header.hpp" `

detail explanation of [compilation](https://classroom.udacity.com/courses/ud999/lessons/6b9a7102-460d-4f9f-9fb7-668df8e19fea/concepts/a2e09c86-3058-464a-9509-b95fc25d1693)



## arithmetic

```c++
# include <cmath>
int a = 5 %3;
int b = pow(2,10);
float area = M_PI * pow(3,2); // a constant in <cmath>
```

## array

```c++
int nums [] = {1,2,3};  // note Java is int [] nums
int nums [3];  // java is int [] nums = new int [3];
```

## class and constructor

```c++
#include<iostream>
using namespace std;

//The cats class that we used earlier in the lesson. 
class Cats{
    string name;
    string breed; 
    int age;
public:
    Cats(); //declaring the constructor
    void setName(string nameIn);
    void setBreed(string breedIn);
    void setAge(int ageIn);
    string getName();
    string getBreed();
    int getAge();
    void printInfo();
};
//defining the constructor
Cats::Cats(){
    cout<<"Assigning inital values in the constructor\n";
    name = "Unknown";
    breed = "Unknown"; //the initial value of the breed
    age = 99; //the initial value of the age
}
void Cats::setName(string nameIn){
    name = nameIn;
}

void Cats::setBreed(string breedIn){
    breed = breedIn;
}

void Cats::setAge(int ageIn){
    age = ageIn;
}
string Cats::getName(){
    return name;
}
string Cats::getBreed(){
    return breed;
}
int Cats::getAge(){
    return age;
}
void Cats::printInfo(){
    cout<<name<<" "<<breed<<" "<<age;
}

//+++++++
int main(){
    Cats cat1;
    cout<<"Cat1 information: ";
    cat1.printInfo();
    return 0;
}
```

## Template

```c++
#include<iostream>
using namespace std;
//Our generic function
template <typename T>  //tell the compiler we are using a template
T findSmaller(T input1,T  input2); 
int main(){
    int a = 54; 
    int b = 89;
    float f1 = 7.8;
    float f2 = 9.1;
    char c1 = 'f';
    char c2 = 'h';
    string s1 = "Hello";
    string s2 = "Bots are fun";
    
    //Wow! We can use one function for different variable types
    cout<<"\nIntegers compared: "<<findSmaller(a,b);
    cout<<"\nFloats compared: "<<findSmaller(f1,f2);
    cout<<"\nChars compared: "<<findSmaller(c1,c2);
    cout<<"\nStrings compared: "<<findSmaller(s1,s2);   
    return 0;
}

template <typename T>
T findSmaller(T  input1,T  input2){
    if(input1 < input2)
        return input1;
    else
        return input2;
}
```

