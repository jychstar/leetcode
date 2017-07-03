#include <iostream>
#include <vector>
#include <map>
#include <array>

using namespace std;
// it's an interesting challenge, each time you unlock something slightly different
// note the tricky part (pixels 10, 8) has not be solved.

vector<array<size_t, 2>> expanse(vector<vector<int>>& grid,
             map<array<size_t, 2>,int>& finalist,
             vector<array<size_t, 2>>& cads,
             size_t H, size_t W, size_t D, int &low, int &high){
    vector<array<size_t, 2>> update;
    size_t i, j;
    int value;
    for (array<size_t,2> cad:cads){
        i = cad[0];
        j = cad[1];
        value = grid[i][j];
        if ( value >0) {
            if (value >= low - D && value <= high + D) { // distance condition
                //cout << i << "\t" << j << "\t"<< value <<endl;
                low = min(low, value);
                high = max(high, value);
                finalist[cad] = value;
                grid[i][j] = 0; // lock
                if (i>0)
                    update.push_back({i-1,j});
                if (i<H-1)
                    update.push_back({i+1,j});
                if (j>0)
                    update.push_back({i,j-1});
                if (j<W-1)
                    update.push_back({i,j+1});

            } else {
                //cout << "reserve:" << value<< endl;
                update.push_back(cad);
            }
        }

    } // end for loop through candidates

    return update;
}

vector<vector<int>> classify(size_t H, size_t W, size_t S, size_t D, vector<vector<int>> data){
    vector<vector<int>> res(H,vector<int>(W,0));
    size_t ID=0;

    for (size_t i = 0; i!= H; i++) {
        for (size_t j = 0; j != W; j++)
            if (data[i][j] > 0) {
                int low = data[i][j];
                int high = low;
                map<array<size_t, 2>,int> finalist;
                vector<array<size_t, 2>> candidate;
                int record = -1;
                candidate.push_back({i,j});

                while (finalist.size()!= record){
                    record = finalist.size();
                    candidate = expanse(data, finalist, candidate, H, W, D, low, high);
                    //cout<<"range: "<< low <<"\t"<<high<<endl;
                }

                if (finalist.size()> S){
                    //cout << "final > S" <<endl;
                    ID +=1;
                    for (auto item: finalist){
                        int row = item.first[0];
                        int col = item.first[1];
                        res[row][col] = ID;
                    }
                }
                else{
                    //cout << "final < S" <<endl;
                    for (auto item: finalist){
                        int row = item.first[0];
                        int col = item.first[1];
                        int val = item.second;
                        data[row][col] = val;
                    }
                }
            }
    } // end for loop
    return res;
}






int main ()
{
    vector<vector<int> > img = {{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                { 0,10,12, 0, 0, 0,22,40,41, 0},
                                { 0,14,11,13, 0, 0, 0, 0, 0, 0},
                                { 0,11,13, 0, 0, 0, 0, 0, 0, 0},
                                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                { 0, 0, 0, 0, 0, 4, 3, 0, 0, 0},
                                { 0, 0, 0, 0, 0, 6, 3, 5, 0, 0},
                                { 0, 0, 0, 0, 0,10, 0, 7, 0, 0},
                                {35,37,38,39, 0, 8, 0, 7, 0, 0},
                                { 0, 0, 0, 0, 0, 0, 7, 6, 0, 0},};
    for (vector<int> v:img){
        for (int f:v)
            cout<<f<<'\t';
        cout<<endl;
    }

    vector<vector<int> > res = classify(10,10,2,2,img);
    for (vector<int> v:res){
        for (int f:v)
            cout<<f<<'\t';
        cout<<endl;
    }


    return 0;
}
