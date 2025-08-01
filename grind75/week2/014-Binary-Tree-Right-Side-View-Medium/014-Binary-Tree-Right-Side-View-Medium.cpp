// link: https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        // edge case
        if (!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_len = q.size();

            for (int i = 0; i < level_len; i++) 
            {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                
                if (node->right)
                    q.push(node->right);

                if (i == level_len - 1) // rightmost node at this level
                    ans.push_back(node->val);
            }
        }

        return ans;
    }
};
