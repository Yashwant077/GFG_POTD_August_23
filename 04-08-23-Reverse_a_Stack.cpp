/*
Problem Description: Reverse a Stack

You are given a stack St. You have to reverse the stack using recursion.

Example 1:

Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}
Explanation:
Input stack after reversing will look like the stack in the output.
Example 2:

Input:
St = {4,3,9,6}
Output:
{6,9,3,4}
Explanation:
Input stack after reversing will look like the stack in the output.
Your Task:

You don't need to read input or print anything. Your task is to complete the function Reverse() which takes the stack St as input and reverses the given stack.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= size of the stack <= 10^4
-109 <= Each element of the stack <= 10^9
Sum of N over all test cases doesn't exceeds 10^6
Array may contain duplicate elements.

*/

class Solution{
public:
    void Reverse(stack<int> &st){
        vector<int>v;
        
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            v.push_back(temp);
        }
        
        for(int i=0; i<v.size(); i++)
            st.push(v[i]);
            
        return;
    }
};
