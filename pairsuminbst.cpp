#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    
   
    stack<BinaryTreeNode<int>*> start, end;

    BinaryTreeNode<int> *currNode = root;
    
   
    while (currNode != NULL)
    {
        start.push(currNode);
        currNode = currNode -> left;
    }

    
    currNode = root;
    
  
    while (currNode != NULL)
    {
        end.push(currNode);
        currNode = currNode -> right;
    }

    while (start.top() != end.top())
    {
        
       
        int val1 = start.top() -> data;
        
       
        int val2 = end.top() -> data;

        
        if (val1 + val2 == k)
        {
            return true;
        }

        
        if (val1 + val2 < k)
        {
            currNode = start.top() -> right;
            start.pop();
            
            while (currNode != NULL)
            {
                start.push(currNode);
                currNode = currNode -> left;
            }
        }

     
        else
        {
            currNode = end.top() -> left;
            end.pop();

            while (currNode != NULL)
            {
                end.push(currNode);
                currNode = currNode -> right;
            }
        }
    }

   
    return false;
}
