class Solution {
public:

    bool divisor(vector<int>&v, int m, int t){
        int n = v.size();
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += ceil((double)v[i]/(double)m);
        }

        if(sum <= t) return true;
        else return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int h = INT_MIN;
        int n = nums.size();
        int res;

        for(int i = 0; i < n; i++){
            h = max(h,nums[i]);
        }

        while(l <= h){
            int mid = (l+h)/2;

            res = divisor(nums,mid,threshold);

            if(res){
                h = mid-1;

            }else{
                l = mid + 1;
            }

        }

        return l;
    }
};