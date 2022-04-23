/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 */

// @lc code=start
class Solution {
private:
    map<string,string> mapping;
    const string alphanum = "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    string geturl(string longUrl) {
        string url = "";
        for (int i = 0; i < 10; i++) {
            url += alphanum[rand() % alphanum.length()];
        }
        return url;
    }
public:

    // Encodes a URL to a shortened URL.
    Solution() {
        srand(time(0));
    }
    string encode(string longUrl) {
        string sht = "https://tinyurl.com/";
        sht += geturl(longUrl);
        mapping[sht] = longUrl;
        return sht;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mapping[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

