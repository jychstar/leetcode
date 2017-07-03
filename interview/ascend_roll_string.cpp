#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// two ways to split a string
char rollChar(char letter, char roll){
    if (roll == 'R'){
        letter +=1;
        if (letter > 'z')
            letter = 'a';
    }
    if (roll == 'L'){
        letter -=1;
        if (letter <'a')
            letter = 'z';
    }
    //cout <<letter<<endl;
    return letter;
}

string rollingString(string s, vector<string> operations) {

    vector <char> v;
    for (char ch:s)
        v.push_back(ch);
    for (string op: operations){
        cout << op <<endl;
        vector<string> split;
        istringstream iss(op);
        for (string temp; iss>>temp;)
            split.push_back(temp);
        /*
        string temp = "";
        for (char ch:op){
            if (ch == ' '){
                split.push_back(temp);
                temp = "";
            }
            else
                temp += ch;
        }
        split.push_back(temp);
         */

        int i = stoi(split[0]);
        int j = stoi(split[1]);
        char roll = split[2][0];

        cout << i <<j <<roll <<endl;
        for (int index=i; index != j+1;index++)
            v[index] = rollChar(v[index],roll);

    }
    string str(v.begin(),v.end());
    return str;

}


int main ()
{

    vector <string> zombies;
    zombies.push_back("0 0 L");
    zombies.push_back("2 2 L");
    zombies.push_back("0 2 R");
    cout << rollingString("abc",zombies) <<endl; // acc
    
    return 0;
}
