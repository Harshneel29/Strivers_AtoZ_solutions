class Solution {
public:

    int solve(int i, int j,vector<vector<int>> &v,int m,vector<vector<int>> &dp){
        if(i == m-1){
            return v[m-1][j];
        }

        if(dp[i][j] != -1) return dp[i][j];

        int up = v[i][j] + solve(i+1,j,v,m,dp);
        int left = v[i][j] + solve(i+1,j+1,v,m,dp);

        return dp[i][j] =  min(up,left);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> front(m,0), cur(m,0);
        for(int j = 0; j < m; j++) front[j] = triangle[m-1][j];

        for(int i = m-2;i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int up = triangle[i][j] + front[j];
                int left = triangle[i][j] + front[j+1];

                cur[j] = min(up,left);
            }
            front = cur;
        }

        return front[0];
    }
};