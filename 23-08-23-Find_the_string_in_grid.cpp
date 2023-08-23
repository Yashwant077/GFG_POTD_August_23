/*
Problem Description: Find the string in grid

Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down, and 4 diagonal directions.

Note: The returning list should be lexicographically smallest. If the word can be found in multiple directions starting from the same coordinates, the list should contain the coordinates only once. 

Example 1:

Input: 
grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output: 
{{0,0}}
Explanation: 
From (0,0) we can find "abc" in horizontally right direction.

Example 2:

Input: 
grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
word = "abe"
Output: 
{{0,0},{0,2},{1,0}}
Explanation: 
From (0,0) we can find "abe" in right-down diagonal. 
From (0,2) we can find "abe" in left-down diagonal. 
From (1,0) we can find "abe" in horizontally right direction.

Your Task:
You don't need to read or print anything, Your task is to complete the function searchWord() which takes grid and word as input parameters and returns a list containing the positions from where the word originates in any direction. If there is no such position then returns an empty list.

Expected Time Complexity: O(n*m*k) where k is constant
Expected Space Complexity: O(1)

Constraints:
1 <= n <= m <= 50
1 <= |word| <= 15

*/


class Solution {
public:

    int dx[8] = {-1,-1,0,1,1,1,0,-1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
    
    bool isValid(int x, int y, int n, int m){
        if(x>=0 && x<n && y>=0 && y<m)
            return true;
        return false;
    }
    
    bool possible(int x, int y, vector<vector<char>>& grid, string &word, int ind, int dr){
        if(ind==word.size())
            return true;
            
        int n = grid.size();
        int m = grid[0].size();
        
        if(!isValid(x,y,n,m))
            return false;
        
        if(grid[x][y]!=word[ind])
            return false;
            
        bool res = possible(x+dx[dr], y+dy[dr], grid, word, ind+1, dr);
        
        return res;
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>ans;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==word[0]){
                    for(int k=0; k<8; k++){
                        if(possible(i,j,grid,word,0,k)){
                            ans.push_back(vector<int>{i,j});
                            break;
                        }
                    }
                }
            }
        }
        
        return ans;
	}
};
