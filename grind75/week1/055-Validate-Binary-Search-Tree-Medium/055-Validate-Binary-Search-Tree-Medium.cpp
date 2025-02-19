// Problem link: https://leetcode.com/problems/validate-binary-search-tree/description/

// Problem link: https://leetcode.com/problems/validate-binary-search-tree/description/

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

    bool valid(TreeNode* node, long minimum, long maximum)
    {
        if(node == NULL) { return true; }

        if(node->val >= maximum || node->val <= minimum)
        {
            return false;
        }

        return valid(node->left, minimum, node->val) && valid(node->right, node->val, maximum);
    }

    bool isValidBST(TreeNode* root) {
        return valid(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
};
