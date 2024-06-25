class Solution {
public:

    bool allStars(int i, string& p) {
    for (int j = i; j >= 0; j--) {
        if (p[j] != '*') return false;
    }
    return true;
}

int fmemo(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
    if (i < 0 && j < 0) return true;
    if (j < 0 && i >= 0) return false;
    if (i < 0 && j >= 0) {
        if (allStars(j, p)) return true;
        return false;
    }
    
    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == p[j] || p[j] == '?')
        return dp[i][j] = fmemo(i - 1, j - 1, s, p, dp);
    else {
        if (p[j] == '*')
            return dp[i][j] = (fmemo(i - 1, j, s, p, dp) || fmemo(i, j - 1, s, p, dp));
        return dp[i][j] = false;
    }
}

bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fmemo(n - 1, m - 1, s, p, dp);
}
};