#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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

int revInorder(TreeNode<int>* root, int &visCount, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    
  
    int right = revInorder(root -> right, visCount, k);
    
    if (right != -1)
    {
        return right;
    }

    visCount++;

    if (visCount == k)
    {
        return root -> data;
    }

   
    int left = revInorder(root -> left, visCount, k);
    
    return left;
}


int KthLargestNumber(TreeNode<int>* root, int k)
{
    int visCount = 0;

    return revInorder(root, visCount, k);
}
