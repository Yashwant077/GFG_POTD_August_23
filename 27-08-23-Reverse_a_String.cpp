/*
Problem Description: Reverse a String

You are given a string s. You need to reverse the string.

Example 1:

Input:
s = Geeks
Output: skeeG

Example 2:

Input:
s = for
Output: rof
Your Task:

You only need to complete the function reverseWord() that takes s as parameter and returns the reversed string.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1 <= |s| <= 10000

*/


class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
        int l=0;
        int r=str.size()-1;
        
        while(l<=r){
            swap(str[l++],str[r--]);
        }
        
        return str;
    }
};
