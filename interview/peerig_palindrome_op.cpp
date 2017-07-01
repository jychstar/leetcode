/*
 * Complete the function below.
 */
vector < int > mystery(vector < string > letter) {
    vector<int> res;
    
    for (string s: letter){
        int op = 0;
        int left =0, right = s.size()-1;
        while (left<right){
            op += int (abs(s[left]-s[right]));
            
            left++;
            right--;
        }
        res.push_back(op);
    }
    return res;    


}