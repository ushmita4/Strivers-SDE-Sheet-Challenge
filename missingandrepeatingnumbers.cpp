#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int findxor=0;
	for(int i=1;i<=n;i++){
		findxor^=i;
	}
	for(int i=0;i<n;i++){
		findxor^=arr[i];
	}
	int bitIndex=findxor& ~(findxor-1);
	int bitSet=0,bitNotSet=0;
	for(int i=0;i<n;i++){
		if(arr[i]&bitIndex)
		bitSet=bitSet^arr[i];
		else
		bitNotSet=bitNotSet^arr[i];
	}
	  for (int i = 1; i <= n; i++) 
    { 
        if (i & bitIndex) 
        {
            bitSet = bitSet ^ i; 
          }
          
        else
        {
            bitNotSet = bitNotSet ^ i; 
        }
    } 
    
    int m, r;
    
    
    for(int i = 0; i < n; i += 1)
    {
        
        if(bitSet == arr[i])
        {
            r = bitSet ; 
            m = bitNotSet;
            break;
        }
        
        
        if(bitNotSet == arr[i])
        {
            r = bitNotSet;
            m = bitSet;
            break;
        }
    }
    
    pair<int, int>ans;
    
    ans.first = m;
    ans.second = r;
    
    return ans;

}
