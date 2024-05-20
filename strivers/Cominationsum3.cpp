class Solution {
public:

    void sum(int i, int k, int n, vector<vector<int>> &ans, vector<int> &ds){
        if(n == 0 && ds.size() == k){
            ans.push_back(ds);
            ds.pop_back();
            return ;
        }

        if( i > 9){
            ds.pop_back();
            return;
        }

        ds.push_back(i);
        sum(i + 1,k,n-i,ans,ds);
        sum(i + 1,k,n,ans,ds);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> ans;
      vector<int> ds;
      sum(1,k,n,ans,ds);  
      return ans;
    }
};