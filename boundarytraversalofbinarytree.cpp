#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void leftBoundary(TreeNode<int>* root, vector<int>& ans);
void rightBoundary(TreeNode<int>* root, vector<int>& ans);
void leafNodes(TreeNode<int>* root, vector<int>& ans);

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;

    if(root == NULL){
        return ans;
    }
     
    ans.push_back(root -> data);
    
    
    leftBoundary(root -> left, ans);
    

    leafNodes(root -> left, ans);
    leafNodes(root -> right, ans);
    
   
    rightBoundary(root -> right, ans);
    
    return ans;
}

void leftBoundary(TreeNode<int>* root, vector<int>& ans){
    if(root == NULL || (root -> left == NULL && root -> right == NULL)){
        return;
    }
    
    ans.push_back(root -> data);
    
    if(root -> left != NULL){
        leftBoundary(root -> left, ans);
    }

    else{
        leftBoundary(root -> right, ans);
    }
}

void rightBoundary(TreeNode<int>* root, vector<int>& ans){
    if(root == NULL || (root -> left == NULL && root -> right == NULL)){
        return;
    }
    
    if(root -> right != NULL){
        rightBoundary(root -> right, ans);
    }

    else{
        rightBoundary(root -> left, ans);
    }
    
    ans.push_back(root -> data);
}

void leafNodes(TreeNode<int>* root, vector<int>& ans){
    if(root == NULL){
        return;
    }
    
    if(root -> left == NULL && root -> right == NULL){
        ans.push_back(root -> data);
        return;
    }
    
    leafNodes(root -> left, ans);
    leafNodes(root -> right, ans);
}
