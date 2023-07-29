#include<bits/stdc++.h>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    if (k == n) {
        return arr;
    }

    map<int, int> mp;

    
    for (int ele : arr) {

        mp[ele]++;
    }

   
    priority_queue<pair<int,int>> heap;
    for (auto x : mp) {
        heap.push({x.second, x.first});
    }

    vector<int> ans(k);

    for (int i = 0; i < k; i++) {

        ans[i] = heap.top().second;
        heap.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
}
