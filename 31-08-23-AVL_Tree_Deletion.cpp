/*
Problem Description: AVL Tree Deletion

Given an AVL tree and N values to be deleted from the tree. Write a function to delete a given value from the tree. All the N values which needs to be deleted are passed one by one as input data by driver code itself, you are asked to return the root of modified tree after deleting the value.

Example 1:

Tree = 
        4
      /   \
     2     6
    / \   / \  
   1   3 5   7

N = 4
Values to be deleted = {4,1,3,6}

Input: Value to be deleted = 4
Output:
        5    
      /   \
     2     6
    / \     \  
   1   3     7

Input: Value to be deleted = 1
Output:
        5    
      /   \
     2     6
      \     \  
       3     7

Input: Value to be deleted = 3
Output:
        5    
      /   \
     2     6
            \  
             7

Input: Value to be deleted = 6
Output:
        5    
      /   \
     2     7

Your Task:  
You dont need to read input or print anything. Complete the function delelteNode() which takes the root of the tree and the value of the node to be deleted as input parameters and returns the root of the modified tree.

Note: The tree will be checked after each deletion. 
If it violates the properties of balanced BST, an error message will be printed followed by the inorder traversal of the tree at that moment.
If instead all deletion are successful, inorder traversal of tree will be printed.
If every single node is deleted from tree, 'null' will be printed.

Expected Time Complexity: O(height of tree)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ N ≤ 500

*/

void getElements(Node* root, vector<int>& inorder, int data){
    if(!root)
        return;
    getElements(root -> left, inorder, data);
    if(data != root -> data)
        inorder.push_back(root -> data);
    getElements(root -> right, inorder, data);
}

Node* getBalancedTree(vector<int> elements, int height){
    if(elements.size() == 0){
        return NULL;
    }
    int mid = elements.size() >> 1;
    Node* temp = new Node(elements[mid]);
    temp -> height = height;
    if(elements.size() == 1){
        
        return temp;
    }
    vector<int> left(elements.begin(), elements.begin() + mid), right(elements.begin() + mid + 1, elements.end());
    temp -> left = getBalancedTree(left, height + 1);
    temp -> right = getBalancedTree(right, height + 1);
    return temp;
    
}

Node* deleteNode(Node* root, int data)
{
    vector<int> inorder;
    getElements(root, inorder, data);
    return getBalancedTree(inorder, 1);
}
