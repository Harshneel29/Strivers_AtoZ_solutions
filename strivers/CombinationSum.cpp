class Solution {
public:

    void combsum(int i, int target,vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds){
        if(i == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(candidates[i] <= target){
            ds.push_back(candidates[i]);
            combsum(i,target - candidates[i],candidates,ans,ds);
            ds.pop_back();
        }

        combsum(i + 1,target,candidates,ans,ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combsum(0,target,candidates,ans,ds);

        return ans;
    }
};