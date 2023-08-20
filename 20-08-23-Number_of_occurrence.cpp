/*
Problem Description: Number of occurrence

Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.
Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the
given array.
Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which takes the array of integers arr, n, and x as parameters and returns an integer denoting the answer.
If x is not present in the array (arr) then return 0.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 10^5
1 ≤ Arr[i] ≤ 10^6
1 ≤ X ≤ 10^6

*/

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int l = 0;
	    int r = n-1;
	    
	    while(l<=r){
	        
	        int mid = l + (r-l)/2;
	        
	        if(arr[mid]==x){
	            int freq=0;
	            int left = mid;
	            int right = mid;
	           // for counting left side elements
	            while(arr[left-1]==x && left>0){
	                freq++;
	                left--;
	            }
	           // for counting right side elements
	            while(arr[right+1]==x && right<n-1){
	                freq++;
	                right++;
	            }
	            freq++;      // for counting mid itself
	            return freq;
	        }
	        
	        else if(arr[mid]>x)
	            r = mid-1;
	           
	        else
	            l = mid+1;
	    }
	    
	    return 0;
	}
};
