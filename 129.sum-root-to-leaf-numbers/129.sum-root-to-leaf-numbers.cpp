/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 */

// @lc code=start
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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    void dfs(TreeNode* root, int &sum) {
        if (root->left) {
            root->left->val += root->val*10;
            dfs(root->left, sum);
        }
        if (root->right) {
            root->right->val += root->val*10;
            dfs(root->right, sum);
        }
        if (!root->left && !root->right) sum += root->val;
    }
};
// @lc code=end

