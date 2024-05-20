class Solution {
public:
    string decTobin(int goal){
        int num = goal;
        string s = "";
        while(num > 1){
            if(num % 2 == 0){
                s += '0';
            }else{
                s += '1';
            }
            num = num / 2;
        }
        if(s.empty()){
            if(goal == 1) s += '1';
            else s += '0';
        }
        else s += '1';
        return s;
    }
    int minBitFlips(int start, int goal) {
        string stgoal = decTobin(goal);
        string stStart = decTobin(start);
        string ans = "";
        string rem = "";
        int diff = stStart.length() - stgoal.length();
        diff = abs(diff);
        if(stStart.length() > stgoal.length()){ 
            ans = stgoal;
            rem = stStart;
            }
        else{ 
            ans = stStart;
            rem = stgoal;
        }

        for(int i = 0; i < diff; i++){
          ans += '0';   
        } 
        cout << ans << endl;
        cout << rem;

        int count = 0;
        for(int j = 0; j < ans.length(); j++){
            if(ans[j] != rem[j]) count++;
        }

        return count;
    }
};