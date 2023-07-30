#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getTopView(TreeNode<int> *root) {
    
    vector<int> topView;

   
    map<int, int> visited;

   
    if (root == NULL) {
        return topView;
    }

  
    queue<pair<TreeNode<int> *, int>> level;

   
    level.push({root, 0});

   
    while (level.size() != 0) {
       
        int levelSize = level.size();

        while (levelSize != 0) {
    
            pair<TreeNode<int> *, int> curr = level.front();
            level.pop();

          
            int hrDistance = curr.second;

       
            TreeNode<int> *currNode = curr.first;

           
            if (visited.count(hrDistance) == 0) {
         
                visited.insert({hrDistance, currNode->val});
            }

           
            if (currNode->left != NULL) {
                level.push({currNode->left, hrDistance - 1});
            }

           
            if (currNode->right != NULL) {
                level.push({currNode->right, hrDistance + 1});
            }
            levelSize = levelSize - 1;
        }
    }

   
    for (auto x : visited) {
        topView.push_back(x.second);
    }

    return topView;
}
