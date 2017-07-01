 * Complete the function below.
 */
int maxDifference(vector < int > a) {
    int res = 0;
    int low = a[0];
    for (int num:a){
        if (num<low){
            low = num;
            continue;
        }
        res = max (res, num-low);
             
    }
    if (res == 0)
        return -1;
    return res;
}
