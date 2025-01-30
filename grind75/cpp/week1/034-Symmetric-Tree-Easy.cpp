// Problem link: https://leetcode.com/problems/symmetric-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool dfs(TreeNode* left, TreeNode* right)
    {
        if (left == NULL && right == NULL)
        {
            return true;
        }
        if(left == NULL || right == NULL)
        {
            return false;
        }
        return dfs(left->left, right->right) && dfs(left->right, right->left) && left->val == right->val;
    }

    bool isSymmetric(TreeNode* root) {
        
        return dfs(root->left, root->right);
    }
};


