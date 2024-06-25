class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0,l = 0, r = 0,z = 0;

        while(r < n){
           if(nums[r] == 0) z++;
           if(z > k){
            if(nums[l] == 0) z--;
            l++;
           }
           if(z <= k) maxlen = max(maxlen,r-l+1);
           r++;
        }

        return maxlen;
    }
};