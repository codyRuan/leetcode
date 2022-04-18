/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode();
        TreeNode* cur = res;
        vector<TreeNode*> stk;
        while (root || !stk.empty()) {
            if (root) {
                stk.push_back(root);
                root = root -> left;
            }
            else {
                TreeNode* node = stk.back();
                stk.pop_back();
                node -> left = nullptr;
                cur -> right = node;
                cur = node;
                root = node -> right;
            }
        }
        return res->right;
    }
};
// @lc code=end

