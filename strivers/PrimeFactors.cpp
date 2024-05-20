//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    int n  = N;
	    vector<int> ans;
	    for(int i = 2; i * i <= n; i++){
	        if(n % i == 0){
	            ans.push_back(i);
	            while(n % i == 0){
	                n /= i;
	            }
	        }
	    }
	    if(n>1){
	        ans.push_back(n);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends