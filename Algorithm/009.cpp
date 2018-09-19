class Solution {
public:
    bool isPalindrome(int x) {
        //小于0肯定不是回文数
        if (x < 0 || (0 == x % 10 && x > 0)) {
            return false;
        }
        //0~9是回文数
        if (0 == x / 10) {
            return true;
        }
        //转化为字符串
        string s = to_string(x);
        int SIZE = s.size();
        //flag代表是否为回文数
        bool flag = true;
        //判断是否为回文数，分别判断字符串长度为奇数或偶数
        if (1 == SIZE % 2) {
            for (int i = 0; i < (SIZE + 1) / 2; i++) {
                if (s[i] != s[SIZE - 1 - i]) {
                    flag = false;
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < SIZE / 2; i++) {
                if (s[i] != s[SIZE - 1 - i]) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};