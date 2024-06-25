class Solution {
public:

       int solve(vector<int> &v,int i,int k,int n,vector<vector<int>> &dp,int fee){
        if(i >= n) return 0;

        long long profit = 0;

        if(dp[i][k] != -1) return dp[i][k];

        if(k){
            profit = max(-v[i] + solve(v,i+1,0,n,dp,fee),solve(v,i+1,1,n,dp,fee));
        }else{
            profit = max(v[i] + solve(v,i+1,1,n,dp,fee) - fee,solve(v,i+1,0,n,dp,fee));
        }

        return dp[i][k] = profit;

    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,1,n,dp,fee);
    }
};