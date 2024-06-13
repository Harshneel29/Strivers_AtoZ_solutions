class Solution {
public:


    int change(int amount, vector<int>& coins) {
        int tar = 0;
        for(auto it : coins) tar += it;
        int n = coins.size();
        vector<int> arr = coins;
      vector<vector<int>> dp(n,vector<int>(amount+1));
    for(int i=0; i<n; i++){
        for(int tar=0; tar<=amount; tar++){
            if(i == 0){
                if(tar % arr[i]!=0) dp[i][tar] = 0;
                else dp[i][tar] = 1;
                continue;
            }
            int take = 0;
            if(arr[i] <= tar) take = dp[i][tar-arr[i]];
            int notake = dp[i-1][tar];
            dp[i][tar] = (take + notake);
        }
    }
    return dp[n-1][amount];
    }
};