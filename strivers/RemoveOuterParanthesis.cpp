class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;

        for(auto it : s){
            if(it == '(' && count  == 0){
                count++;
            }else if(it == '(' && count >= 1){
                ans = ans + it;
                count++;
            }else if(it == ')' && count > 1){
                ans =  ans + it;
                count--;
            }else if(it == ')' && count == 1){
                count--;
            }
        }

        return ans;
    }
};