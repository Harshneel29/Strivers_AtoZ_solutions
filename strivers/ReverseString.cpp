class Solution {
public:
    void reverseString(vector<char>& s) {
        int e = s.size() - 1;
        int i = 0;

        while(i < s.size()/2){
            int temp = s[i];
            s[i] = s[e];
            s[e] = temp;
            i++;
            e--;
        }
    }
};