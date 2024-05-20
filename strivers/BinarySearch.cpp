class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int mid;
        int i = 0;
        int j = n-1;

        while(i <= j){
            mid = (i+j)/2;

            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                i = mid + 1;
                mid = (i+j)/2;
            }else{
                j = mid - 1;
                mid = (i+j)/2;
            }
        }

        return -1;
    }
};