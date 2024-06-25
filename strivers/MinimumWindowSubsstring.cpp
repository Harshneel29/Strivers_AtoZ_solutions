class Solution {
public:
   string minWindow(string s, string t) {
    unordered_map<char, int> mp;

    for (auto it : t) {
        mp[it]++;
    }
    
    int count = mp.size();
    int start = 0, minlen = INT_MAX;
    int substrBegin = 0;

    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]--;
        
        if (mp[s[i]] == 0)
            count--;
        
        while (count == 0) {
            if (i - start + 1 < minlen) {
                substrBegin = start;
                minlen = i - start + 1;
            }
            
            mp[s[start]]++;
            
            if (mp[s[start]] > 0) {
                count++;
            }
            
            start++;
        }
    }
    
    return (minlen == INT_MAX) ? "" : s.substr(substrBegin, minlen);
}
};