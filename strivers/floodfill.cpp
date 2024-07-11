class Solution {
public:

    void dfs(int row, int col,vector<vector<int>>& ans,vector<vector<int>>& image,int drow[], int dcol[], int inicolor, int color){
        ans[row][col] = color;
        int m = image.size();
        int n = image[0].size();

        for(int i = 0; i < 4; i++){
            int ncol = col + dcol[i];
            int nrow = row + drow[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && ans[nrow][ncol] != color && image[nrow][ncol] == inicolor) {
                dfs(nrow,ncol,ans,image,drow,dcol,inicolor,color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int inicolor = image[sr][sc];
        int drow[] = {0,1,0,-1};
        int dcol[] = {-1,0,1,0};
        dfs(sr,sc,ans,image,drow,dcol,inicolor,color);
        return ans;
    }
};