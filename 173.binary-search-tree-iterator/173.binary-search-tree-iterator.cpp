/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
private:
    TreeNode* ptr;
    vector<TreeNode*> stk;
public:
    BSTIterator(TreeNode* root) {
        ptr = root;
    }
    
    int next() {
        while (ptr || !stk.empty()) {
            if (ptr) {
                stk.push_back(ptr);
                ptr = ptr -> left;
            }
            else {
                TreeNode* node = stk.back();
                stk.pop_back();
                ptr = node -> right;
                return node -> val;
            }
        }
        return -1;
    }
    
    bool hasNext() {
        if (!ptr && stk.empty()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

