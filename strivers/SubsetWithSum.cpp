//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:


    bool f(vector<int>arr, int sum, int i,vector<vector<int>> &dp){
        if(sum == 0) return true;
        if(i == 0) return (arr[0] == sum);
        if(dp[i][sum] != -1) return dp[i][sum];
        
        bool notake = f(arr,sum,i-1,dp);
        bool take = false;
        if(arr[i] <= sum){
            take = f(arr,sum - arr[i],i-1,dp);
        }
        
        return dp[i][sum] = take | notake;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(arr,sum,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends 