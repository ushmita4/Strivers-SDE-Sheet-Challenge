#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int buy=prices[0],maxProfit=0,n=prices.size();
    for(int i=0;i<n;i++){
        if(prices[i]<buy)
        buy=prices[i];

        else{
            if((prices[i]-buy)>maxProfit)
            maxProfit=prices[i]-buy;
        }
    }
    return maxProfit;
}
