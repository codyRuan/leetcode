/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        int res = 0;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            res = 0;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                res += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return res;
    }
};
// @lc code=end

