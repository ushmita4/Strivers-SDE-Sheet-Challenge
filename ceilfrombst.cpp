#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
int findCeil(BinaryTreeNode < int > * node, int x) {
  
  int ceil = -1;

  
  while (node != NULL) {

    
    if (x == node -> data) {
      return node -> data;
    }

    
    if (x > node -> data) {

      node = node -> right;
    }

   
    else {
      ceil = node -> data;
      node = node -> left;
    }
  }

 
  return ceil;

}
