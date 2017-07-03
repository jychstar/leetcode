#include <iostream>
#include <vector>
#include <map>
#include <array>

using namespace std;
// only the zombie at the diagnol position may be source
// not sure why my code doesn't pass all the cases.

int zombieCluster(vector < string > zombies) {
    size_t row = zombies.size();
    size_t col = zombies[0].size();
    map<size_t,int> m;
    int cnt = 0;

    for (size_t i=0; i< row; i++){
        for (size_t j= 0; j< col; j++){
            if (zombies[i][j] == '1'){
                if (i==j && m.find(i)==m.end()){
                    m[i] = 1;
                    cnt++;
                }
                else if (m.find(i)==m.end() || m.find(j)==m.end())
                    m[j] = 1;
            }
        }
        //cout <<endl;
    }

    return cnt;
}


int main ()
{

    vector <string> zombies ={"100","010","001"};
    cout << zombieCluster(zombies) <<endl;




    return 0;
}
