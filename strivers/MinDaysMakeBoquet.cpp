class Solution {
public: 
int maximum(vector<int> &v){
    int n = v.size();
    int maxi = INT_MIN;


    for(int i = 0; i < n; i++){
        maxi = max(maxi,v[i]);

    }

    return maxi;
}
int minimum(vector<int> &v){
    int n = v.size();
    int mini = INT_MAX;

    for(int i = 0; i < n; i++){
        mini = min(mini,v[i]);

    }

    return mini;
}
    bool possible(vector<int>&v,int mid,int k ,int m){
        int n = v.size();
        int count = 0;
        int Nob = 0;

        for(int i = 0; i < n; i++){
            if(mid >= v[i]){
                count++;
            }else{
                Nob += (count/k);
                count = 0;
            }
        }
        Nob += (count/k);

        if(Nob >= m) return true;
        else return false;

        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l,h;
        int n = bloomDay.size();
        int res = -1;;

        l = minimum(bloomDay);
        h = maximum(bloomDay);
        

        while(l<=h){
            int mid = (l + h)/2;
            bool ans = possible(bloomDay,mid,k , m);

            if(ans == true){
                res = mid;
                h = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return res;
    }
};