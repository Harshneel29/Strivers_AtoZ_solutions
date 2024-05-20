class Solution {
public:

     bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }

    void fun(int i,vector<vector<string>> &res,vector<string> &path, string s){
        int n = s.size();
        if(i == n){
            res.push_back(path);
            return;
        }

        for(int j = i; j < s.size(); ++j){
            if(isPalindrome(s,i,j)){
                path.push_back(s.substr(i,j-i+1));
                fun(j+1,res,path,s);
                path.pop_back();
            }
        }


    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        fun(0,res,path,s);
        return res;
    }
};