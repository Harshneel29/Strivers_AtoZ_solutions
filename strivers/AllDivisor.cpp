class Solution
{
public:
 int countPrimes(int n)
 {
  vector<bool> primes(n + 1, true);
  int count = 0;
  for (long long i = 2; i < n; i++)
  {
   if (primes[i])
   {
    count++;
    for (long long j = i * i; j <= n; j += i)
    {
     primes[j] = false;
    }
   }
  }
  return count;
 }
};