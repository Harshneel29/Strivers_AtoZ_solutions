// tabulation

class Solution {
public:

    int f(int i,int p,vector<int> &v,int n,vector<vector<int>> &dp){
        if(i == n) return 0;
        if(dp[i][p + 1] != -1) return dp[i][p];

        int ans = 0 + f(i+1,p,v,n,dp);
        if(p == -1 || v[i] > v[p]) ans = max(ans,1 + f(i+1,i,v,n,dp));

        return dp[i][p + 1] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i = n-1; i >= 0; i--){
            for(int p = i-1; p >= -1; p--){

                int ans = 0 + dp[i+1][p+1];
                if(p == -1 || nums[i] > nums[p]) ans = max(ans,1 + dp[i+1][i+1]);

                dp[i][p + 1] = ans;

            }
        }

        return dp[0][0];



    }
};


// space optimization

class Solution {
public:

    int f(int i,int p,vector<int> &v,int n,vector<vector<int>> &dp){
        if(i == n) return 0;
        if(dp[i][p + 1] != -1) return dp[i][p];

        int ans = 0 + f(i+1,p,v,n,dp);
        if(p == -1 || v[i] > v[p]) ans = max(ans,1 + f(i+1,i,v,n,dp));

        return dp[i][p + 1] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1,0),cur(n+1,0);
        
        for(int i = n-1; i >= 0; i--){
            for(int p = i-1; p >= -1; p--){

                int ans = 0 + next[p+1];
                if(p == -1 || nums[i] > nums[p]) ans = max(ans,1 + next[i+1]);

                cur[p + 1] = ans;

            }
            next = cur;
        }

        return next[0];



    }
};