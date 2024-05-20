class Solution {
public:
    int checkPart(vector<int> &v, int m,int h){
        int n = v.size();
        long long last = v[0];
        int count  = 1;

        for(int i = 1; i < n;i++){
            if(last + v[i] > m){
                last = v[i];
                count++;
            }else{
                last += v[i];
            }
        }
        return count;

    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end());
        int h = accumulate(nums.begin(),nums.end(),0);

        while(l <= h){
            int mid = (l+h)/2;

            int res = checkPart(nums,mid,k);

            if(res > k){
                l = mid+1;

            }else{
                h = mid - 1;
            }
        }

        return l;

        
    }
};