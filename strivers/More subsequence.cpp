void check(int k, int n, string s,string ds,set<string> &ans){
 if(k == n){
     ans.insert(ds);
     return;
 }

 for(int i = 0; i < n; i++){
     ds += s[i];
     check(k+1, n, s, ds, ans);
     int temp = ds.size();
     ds = ds.erase(temp-1,1);
 } 


}


string moreSubsequence(int n, int m, string a, string b)
{
set<string> s1;
set<string> s2;
string r1 = "";
string r2 = "";
check(0,n,a,r1,s1);
check(0,m,b,r2,s2);

if(s1.size() > s2.size()) return a;
else return b;
}