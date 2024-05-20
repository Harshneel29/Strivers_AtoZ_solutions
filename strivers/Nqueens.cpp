class Solution {
public:

    bool isSafe(int row,int col,int n, vector<string> &ds){
        int drow = row;
        int dcol = col;

        while(row >= 0 && col >= 0){
            if(ds[row][col] == 'Q') return false;
            col--;
            row--;
        }

        row = drow;
        col = dcol;

        while(col >= 0){
            if(ds[row][col] == 'Q') return false;
            col--;
        }

        col = dcol;

        while(row < n && col >= 0){
            if(ds[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;

    }

    void solve(int col, int n, vector<vector<string>> &ans,vector<string> &ds){
        if( col == n){
            ans.push_back(ds);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(row,col,n,ds)){
                ds[row][col] = 'Q';
                solve(col+1,n,ans,ds);
                ds[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ds(n);
        string s(n,'.');

        for(int i = 0; i < n; i++){
            ds[i] = s;
        }

        solve(0,n,ans,ds);
        return ans;
    }
};