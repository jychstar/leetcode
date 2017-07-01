/*
 * Complete the function below.
 */
#include <iostream>
#include <vector>
#include <map>
int verifyItems(vector < string > origItems, vector < float > origPrices, vector < string > items, vector < float > prices) {
    int res=0;
    map<string,float> orig;
    for (int i=0; i< origItems.size();i++)
        orig[origItems[i]] = origPrices[i];
    for (int i=0; i< Items.size();i++){
        if (orig.find(Items[i]) !=orig.end() && orig[Items[i]] == Prices[i])
            continue;
        else
            res++;
    }
    return res;
}