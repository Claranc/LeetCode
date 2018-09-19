//reference: https://leetcode.com/problems/longest-palindromic-substring/discuss/147548/Direct-c++-DP
class Solution {
public:
    string longestPalindrome(string s) {
        //输入为空时
        if (s.empty()) {
            return "";
        }
        //初始化矩阵，0表示非回文数，1代表是
        int n = s.size();
        vector<int> pi(n, 0);
        vector<vector<int>> p;
        for (int i = 0; i < n; i++) {
            p.push_back(pi);
        }
        // base cases('a'，"aa")
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    p[i][j] = 1;
                }
                if (j - i == 1 && s[i] == s[j]) {
                    p[i][j] = 1;
                }
            }
        }
        //P(i, j) = { true, if the substring Si…Sj is a palindrome; false, otherwise}
        if (n >= 3) {
            for (int i = n - 3; i >= 0; i--) {
                for (int j = i + 2; j < n; j++) {
                    if (p[i + 1][j - 1] == 1 && i >= 0 && j < n && s[i] == s[j]) {
                        p[i][j] = 1;
                    }
                }
            }
        }
        //遍历矩阵找出最大值
        int max_len = 0;
        int start;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (1 == p[i][j] && (j - i + 1) > max_len) {
                    max_len = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, max_len);
    }

};