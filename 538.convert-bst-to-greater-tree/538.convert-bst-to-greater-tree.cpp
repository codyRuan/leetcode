/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
    TreeNode* convertBST(TreeNode* root) {
        int count = 0;
        vector<TreeNode*> stk;
        TreeNode* ptr = root;
        while (ptr || !stk.empty()) {
            if (ptr) {
                stk.push_back(ptr);
                ptr = ptr -> right;
            }
            else {
                TreeNode* node = stk.back();
                stk.pop_back();
                node -> val += count;
                count = node -> val;
                ptr = node -> left;
            }
        }
        return root;
    }
    
};
// @lc code=end

