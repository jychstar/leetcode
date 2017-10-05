class Solution {
public:
    bool judgeCircle(string moves) {
        int x= 0, y = 0;
        for (char ch:moves){
            if (ch == 'R')
                x++;
            if (ch == 'L')        
                x--;
            if (ch =='U')
                 y++;
            if (ch == 'D')
                y--;
            }
            //cout << x << y <<endl;
        } // end for

        if (x==0 && y== 0)
            return true;
        else
            return false;
    }

};