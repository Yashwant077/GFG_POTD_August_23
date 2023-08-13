/*
Problem Description: Nth Fibonacci Number

Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.

Example 1:

Input: 
n = 2
Output: 
1 
Explanation: 
1 is the 2nd number of fibonacci series.

Example 2:

Input: 
n = 5
Output: 
5
Explanation: 
5 is the 5th number of fibonacci series.
Your Task:  
You dont need to read input or print anything. Complete the function nthFibonacci() which takes n as input parameter and returns nth fibonacci number.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1<= n <=10^5

*/


class Solution {
  public:
    int nthFibonacci(int n){
        
        int dp[n+1];
        dp[0] = dp[1] = dp[2] = 1;
        int mod = 1e9+7;
        
        if(n==1 || n==2)
            return 1;
        
        for(int i=3; i<=n; i++){
            dp[i] = (dp[i-1]+dp[i-2])%mod;
        }
        
        return dp[n];
    }
};
