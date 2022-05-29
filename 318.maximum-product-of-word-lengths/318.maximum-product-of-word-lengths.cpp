/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size());
        int result = 0;

        for (int i = 0; i < words.size(); i++) {
            for (auto w : words[i])
                mask[i] |= 1 << (w - 'a');
            
            for (int j = 0; j < i; j++) 
                if (!(mask[i] & mask[j]))
                    result = max(result, int(words[i].size() * words[j].size()));
        }

        return result;
    }
};
// @lc code=end
