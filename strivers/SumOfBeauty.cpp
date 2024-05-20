class Solution {
public:


    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n  ; i++){
            map<char,int> m1;
            for(int j = i; j < n;j++){
                m1[s[j]]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;

                for(auto x : m1){
                    maxi = max(maxi,x.second);
                    mini = min(mini,x.second);
                }
                ans += maxi - mini;
                
            }
        }

        return ans;
    }
};