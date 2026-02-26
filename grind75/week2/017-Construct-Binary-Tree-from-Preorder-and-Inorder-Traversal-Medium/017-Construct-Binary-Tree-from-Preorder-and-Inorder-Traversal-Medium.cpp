// link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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

    // Notes: So when you find the root in the preorder list, wherever that root is in the inorder list,
    // everything to the left of the root in that inorder list will be in the left subtree,
    // everything to the right of that value will be in the right subtree for the output

    // 1.) Use preorder to find the root
    // 2.) Find the root in inorder. Everything to the left of that value in the inorder list will be in the 
    //     left subtree for the output, everything to the right of that value in the inorder list will be in the right subtree
    //     for the output
    // 3.) Now that we found the root in the inorder list. Recursively call the function on everything to the left of the
    //     root in inorder (left subtree of the output) to find what the root should be. And also recursively call 
    //     the function on everything to the right of the root in inorder list (right subtree) to find the root. 
    //     This will build your output. Recursively find on the left subtree to find what the root should be, and recursively 
    //     call the function on the right subtree to find what the root should be for that

    unordered_map<int, int> mapping; // stores value -> index in inorder
    int current = 0; // tracks current root index in preorder

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // in order to not have to go through inorder to find the root every time,
        // let's store the indexes in a hashmap for fast lookup,
        // otherwise our solution would be O(N^2)

        for (int i = 0; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }

        return parse_inorder(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* parse_inorder(vector<int>& preorder, int left, int right) {

        // base case
        if (left > right) {
            return nullptr;
        }

        int rootVal = preorder[current];
        current++;

        int middle = mapping[rootVal];

        TreeNode* node = new TreeNode(rootVal);

        node->left = parse_inorder(preorder, left, middle - 1);
        node->right = parse_inorder(preorder, middle + 1, right);

        return node;
    }
};
