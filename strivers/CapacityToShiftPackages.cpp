class Solution {
public:
    int counter(vector<int>&v,int m){
        int n = v.size();
        int sum = 0;
        int count = 1;

        for(int i = 0; i < n; i++){

            if(sum+v[i] > m){
                count++;
                sum = v[i];
            }else{
                sum += v[i];
            }
        }

        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low <= high){
            int mid = (low+high)/2;
            
            int res = counter(weights,mid);

            if(res <= days){
                high = mid - 1;
                
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};