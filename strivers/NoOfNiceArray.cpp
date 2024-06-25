class Solution {
public:
    int result(vector<int>& nums, int goal){
         if(goal<0){
            return 0;
        }
        int l=0;
        int r=0;
        int count=0;
        int sum=0;
        while(r<nums.size()){
           sum=sum+(nums[r]%2);
           while(sum>goal){
            sum=sum-(nums[l]%2);
            l++;
           }
           count=count+(r-l+1);
           r++;
        }
        return count;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        
        

        return result(nums,k)-result(nums,k-1);
    }
};