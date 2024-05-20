class Solution {
public:

    void combsum(int i, int target, vector<int>& arr, vector<vector<int>> &ans, vector<int> &ds){
 
            if(target == 0){
                ans.push_back(ds);
                return;
            }


            for(int j = i; j < arr.size(); j++){
                if(j > i && arr[j] == arr[j-1]) continue;
                if(arr[j] > target) break;
                ds.push_back(arr[j]);
                combsum(j + 1, target - arr[j], arr, ans, ds);
                ds.pop_back();
            }


    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        combsum(0,target,candidates,ans,ds);
        return ans;
    }
};