class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //字符串长度为0或1时候的处理
        if (0 == s.size() || 1 == s.size()) {
            return s.size();
        }
        int max = 0; //记录最大匹配长度
        // i 为起点，j为当前检测到的位置
        for (int i = 0; i < s.size(); i++) {
            bool flag = 0;  //标记是否出现重复字符
            for (int j = i + 1; j < s.size(); j++) {
                for (int k = i; k < j; k++) {
                    if (s[k] == s[j]) {
                        flag = 1;
                        //此时出现重复，长度大于当前保存的长度，更新
                        if (j - i > max) { 
                            max = j - i;
                        }
                        break;
                    }
                }
                //从当前到字符串最后都未出现重复，输出当前和保存的最大值
                if (s.size() - 1 == j && 0 == flag) {
                    return max > s.size() - i ? max : s.size() - i;
                }
                //出现重复的了，更新起点
                if (1 == flag)
                    break;
            }
        }
        return max;
    }
};

// 解法二： 运用<set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") {
            return 0;
        }
        set<char> se;
        int cnt = 1;
        for (int i = 0, j = 0; i<s.length() && j<s.length();) {
            if (se.count(s[j])<1) {
                se.insert(s[j++]);
                cnt = max(cnt, j - i);
            }
            else {
                se.erase(s[i++]);
            }
        }
        return cnt;
    }
};