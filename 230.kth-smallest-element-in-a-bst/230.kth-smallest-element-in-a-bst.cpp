/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> stk;
        while (root || !stk.empty()) {
            if (root) {
                stk.push_back(root);
                root = root -> left;
            }
            else {
                TreeNode* node = stk.back();
                stk.pop_back();
                if (--k == 0) return node -> val;
                root = node -> right;
            }
        }
        return root -> val;
    }
};
// @lc code=end

