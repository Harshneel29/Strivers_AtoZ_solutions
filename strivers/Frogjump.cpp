#include <bits/stdc++.h>
int sol(int i, vector<int> &h, vector<int> &dp){
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];

    int left = sol(i-1,h,dp) + abs(h[i] - h[i-1]);
    int right = INT_MAX;
    if(i > 1) right = sol(i-2,h,dp) + abs(h[i] - h[i-2]);

    return dp[i] = min(left,right);
} 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);

    return sol(n-1,heights,dp);
}