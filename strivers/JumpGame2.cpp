class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0,last = 0, reach = 0;

        for(int i = 0;i< nums.size() - 1; i++){
            reach = max(reach,i + nums[i]);
            if(i ==  last){
                last = reach;
                count++;
            }
        }
        return count;
    }
};