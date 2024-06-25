class Solution {
public:

    int solve(vector<int>& nums, int k){
         
        int len = 0;
        int r = 0, l = 0;
        map<int,int> mp;

        while(r < nums.size()){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            len += r-l+1;
            r++;
        }

        return len;
        


    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};