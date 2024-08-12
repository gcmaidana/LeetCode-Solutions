// Problem link: https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    int maxDiameter = 0;
    int dfs(TreeNode* root)
    {
        if (root == NULL) {return 0;}
        int left = dfs(root->left);
        int right = dfs(root->right);

        // set max diameter
        maxDiameter = std::max(maxDiameter, left + right);


        return 1 + std::max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDiameter;
    }
};
