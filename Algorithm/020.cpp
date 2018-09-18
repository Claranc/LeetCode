/*
假设在读入一串字符串以后，如果遇到对称符号的左边部分，则将其压入栈中，
当遇到对称符号的右边部分，则弹出栈中的一个对象，实现比对，如果是对称的，
则说明当前的符号是平衡的，如果不对称，则说明当前字符串是不平衡的，当字符
串读完以后，如果所有的符号都是平衡的，栈中此时应该就是为空，通过判断栈中
是否为空，说明字符串是否是符号平衡的。
*/
class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 1) {
            return false;
        }
        stack<char> mem;
        bool flag = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                mem.push(s[i]);
            }
            else {
                if (mem.size() == 0) {
                    return false;
                }
                char x = mem.top();
                mem.pop();
                if ((s[i] == ')' && x == '(') || (s[i] == '}' && x == '{') || (s[i] == ']' && x == '[')) {
                }
                else {
                    flag = 0;
                    break;
                }
            }
        }
        if (mem.size() != 0) {
            return false;
        }
        return flag;
    }
};