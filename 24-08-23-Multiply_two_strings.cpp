/*
Problem Description: Multiply two strings

Given two numbers as strings s1 and s2. Calculate their Product.

Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers.

Example 1:

Input:
s1 = "0033"
s2 = "2"
Output:
66

Example 2:

Input:
s1 = "11"
s2 = "23"
Output:
253

Your Task: You don't need to read input or print anything. Your task is to complete the function multiplyStrings() which takes two strings s1 and s2 as input and returns their product as a string.

Expected Time Complexity: O(n1* n2)
Expected Auxiliary Space: O(n1 + n2); where n1 and n2 are sizes of strings s1 and s2 respectively.

Constraints:
1 ≤ length of s1 and s2 ≤ 10^3

*/

class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
        bool negative = false;
        
        if(s1[0]=='-' && s2[0]=='-'){
            s1 = s1.substr(1);
            s2 = s2.substr(1);
        }
        else if(s1[0]=='-'){
            s1 = s1.substr(1);
            negative = true;
        }
        else if(s2[0]=='-'){
            s2 = s2.substr(1);
            negative = true;
        }
        
        int m = s2.length();
        int n = s1.length();
        
        string ans = "";
        
        for(int j=m-1; j>=0; j--){
            int val1 = s2[j]-'0';
            int carry = 0;
            
            for(int i=n-1, k=m-j-1; i>=0; i--,k++){
                int sum = ((s1[i]-'0')*val1)+carry;
                
                carry = sum/10;
                
                if(ans[k]!='\0'){
                    int val1 = (sum%10) + (ans[k]-'0');
                    carry+=(val1/10);
                    ans[k]=(val1%10+'0');
                }
                else
                     ans.push_back(sum%10+'0');
            }
            
            if(carry)
                 ans.push_back(carry+'0');
        }
        
        reverse(ans.begin(), ans.end());
        
        int size=ans.length();
        
        int i=0;
        
        while(i<size-1){
            if(ans[i]!='0')
                 break;
            i++;
        }
        
        ans = ans.substr(i);
        
        if(size==1 && ans[0]=='0')
            return "0";
            
        if(negative)
            return "-"+ans;
            
        return ans;
    }

};


