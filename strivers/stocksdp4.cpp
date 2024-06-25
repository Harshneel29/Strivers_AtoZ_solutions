class Solution {
public:

    int solve(vector<int>& prices,int n,int i,int b,int c,vector<vector<vector<int>>> &dp){
        if(i == n) return 0;
        if(c == 0) return 0;

        if(dp[i][b][c] != -1) return dp[i][b][c];

        if(b) return dp[i][b][c] = max(-prices[i] + solve(prices,n,i+1,0,c,dp),solve(prices,n,i+1,1,c,dp));
        return dp[i][b][c] = max(prices[i] + solve(prices,n,i+1,1,c-1,dp),solve(prices,n,i+1,0,c,dp));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,n,0,1,k,dp);
    }
};