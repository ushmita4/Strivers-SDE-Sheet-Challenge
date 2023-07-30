#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int kthSmallest(TreeNode<int> *root, int k)
{
    
    stack<TreeNode<int> *> st;

    while (1)
    {
        while (root != NULL)
        {
            
            st.push(root);

            root = root->left;
        }

        root = st.top();
        st.pop();

        if (k == 1)
        {
            return root->data;
        }

       
        k = k - 1;

        root = root->right;
    }
}
