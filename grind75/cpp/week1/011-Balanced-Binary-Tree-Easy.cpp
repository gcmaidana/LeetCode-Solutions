// Problem link: https://leetcode.com/problems/balanced-binary-tree/

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

        int dfs(TreeNode* root) 
        {
            if (root == NULL)
            {
                return 0;
            }

            int left = dfs(root->left);
            int right = dfs(root->right);

            int balanced = std::abs(left - right);

            if (left == -1 || right == -1 || balanced > 1)
            {
                return -1;
            }

            return 1 + std::max(left, right);
        }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) {return true;}

        return dfs(root) != -1;

        
    }
};
