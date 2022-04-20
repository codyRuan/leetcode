/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
private:
TreeNode* prev;
TreeNode* first;
TreeNode* second;
public:
    void recoverTree(TreeNode* root) {
        TreeNode* temp;
        traversal(root);
        swap(first->val, second->val);
    }
    void traversal(TreeNode* root) {
        if (!root) return;
        traversal(root -> left);
        if (prev && !first && prev->val > root->val)
            first = prev;
        if (first && root->val < prev->val)
            second = root;
        prev = root;
        traversal(root->right);
    }
};
// @lc code=end

