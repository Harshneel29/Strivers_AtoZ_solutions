class Solution {
public:
    void dfs(vector<vector<int>>& vis, vector<vector<int>>& arr,int row,int col, int drow[], int dcol[]){
        vis[row][col] = 1;
        int m = arr.size();
        int n = arr[0].size();
        for(int i = 0; i < 4; i++){
            int r = row + drow[i];
            int c = col+ dcol[i];
            if(r < m && r >= 0 && c < n && c >= 0 && vis[r][c] != 1 && arr[r][c] == 1){
                dfs(vis,arr,r,c,drow,dcol);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int drow[] = {1,-1,0,0};
        int dcol[] = {0,0,1,-1};
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1){
                dfs(vis,grid,i,0,drow,dcol);
            }
            if(grid[i][n-1] == 1){
                dfs(vis,grid,i,n-1,drow,dcol);
            }
        }

        for(int i = 0; i < n; i++){
            if(grid[0][i] == 1){
                dfs(vis,grid,0,i,drow,dcol);
            }
            if(grid[m-1][i] == 1){
                dfs(vis,grid,m-1,i,drow,dcol);
            }
        }
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) count++;
            }
        }

        return count;
    }
};