#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    vector<vector<int>> res;
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());
    for(int i=0;i<n;i++){
        int currentStart=intervals[i][0];
        int currentEnd=intervals[i][1];
        if(res.size()==0||currentStart>res[res.size()-1][1])
        res.push_back(intervals[i]);
        else{
            res[res.size() - 1][1] = max(res[res.size() - 1][1], currentEnd);
        }
    }
    return res;
}
