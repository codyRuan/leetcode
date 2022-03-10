/*
 * @lc app=leetcode id=2062 lang=cpp
 *
 * [2062] Count Vowel Substrings of a String
 */

// @lc code=start
class Solution {
public:
    int countVowelSubstrings(string word) {
        map<char, bool> exist = {
            {'a',false}, {'e',false}, {'i',false},
            {'o',false}, {'u',false}};
        int res = 0;
        for (int i = 0; i < word.length(); i++) {
            exist['a'] = exist['e'] = exist['i'] = false;
            exist['o'] = exist['u'] = false;
            for (int j = i; j < word.length(); j++) {
                char c = word[j];
                if (isVowels(c)) exist[c] = true;
                else break;
                if (exist['a'] && exist['e'] && exist['i'] 
                   && exist['o'] && exist['u']) res++;
            }
        }
        return res;
    }
    
    bool isVowels(char a) {
        return a=='a' || a=='e' || a=='i' || a=='o' || a=='u';
    }
};
// @lc code=end

