class Solution {
public:
    int addDigits(int num) {
        // return 1 + (num - 1) % 9;
        while (num>9) 
            num = num/10 + num%10;
        return num;
    }
};