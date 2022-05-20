/*
 * @lc app=leetcode id=1379 lang=cpp
 *
 * [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* res;
    void DFS(TreeNode* root, TreeNode* target) {
        if (root->val == target->val) res = root;
        if (root->left) DFS(root->left, target);
        if (root->right) DFS(root->right, target);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        DFS(cloned, target);
        return res;
    }
};
// @lc code=end

