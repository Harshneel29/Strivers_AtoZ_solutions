#include <bits/stdc++.h>
using namespace std;

int sol(int i, int k, vector<int> &h, vector<int> &dp)
{
 if (i == 0)
  return 0;
 if (dp[i] != -1)
  return dp[i];

 int min_steps = INT_MAX;

 for (int j = 1; j <= k; j++)
 {
  if (i - j >= 0)
  {
   int jump = sol(i - j, k, h, dp) + abs(h[i] - h[i - j]);
   min_steps = min(min_steps, jump);
  }
 }

 return dp[i] = min_steps;
}

int minimizeCost(int n, int k, vector<int> &height)
{
 vector<int> dp(n + 1, -1);
 return sol(n - 1, k, height, dp);
}