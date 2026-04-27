// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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

    void inorder(TreeNode* root, int k, vector<int>& ans) 
    {
        // base case
        if (root == nullptr) return;

        inorder(root->left, k, ans);

        // early stop if we already have k elements
        if (ans.size() == k) return;

        ans.push_back(root->val);

        inorder(root->right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, k, ans);
        return ans.back();
       
    }
};


