/*
Problem Description: Largest prime factor

Given a number N, the task is to find the largest prime factor of that number.
 Example 1:

Input:
N = 5
Output:
5
Explanation:
5 has 1 prime factor i.e 5 only.
Example 2:

Input:
N = 24
Output:
3
Explanation:
24 has 2 prime factors 2 and 3 in which 3 is greater.
Your Task:
You don't need to read input or print anything. Your task is to complete the function largestPrimeFactor() which takes an integer N as input parameters and returns an integer, largest prime factor of N.

Expected Time Complexity: O(sqrt(N))
Expected Space Complexity: O(1)

Constraints:
2 <= N <= 10^9

*/

class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        int maxi = INT_MIN;
        
        for(int i=2; i<=N; i++){
            while(N%i==0){
                maxi=max(maxi,i);
                N=N/i;
            }
        }
        
        return maxi;
    }
};
