class Solution {
public:
    string longestPalindrome(string s) {
        int d[s.length()][s.length()];
        int mlen = -1;
        string ans = s.substr(0,1);
        for (int i = 0; i < s.length(); i++){
            d[i][i] = true;
            if(i != s.length()-1) d[i][i+1] = (s[i] == s[i+1]);
        }
            
        for (int i = 0; i < s.length(); i++){
            for (int j = 0; j < s.length()-i; j++){
                if (i != 0 && i != 1) d[j][j+i] = ((d[j+1][j+i-1]) && (s[j] == s[j+i]));
                if (d[j][j+i] && i+1 > mlen){
                    mlen = i+1;
                    ans = s.substr(j, mlen);
                }
            }
        }
        return ans;
    }
};