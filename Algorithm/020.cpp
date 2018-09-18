/*
�����ڶ���һ���ַ����Ժ���������ԳƷ��ŵ���߲��֣�����ѹ��ջ�У�
�������ԳƷ��ŵ��ұ߲��֣��򵯳�ջ�е�һ������ʵ�ֱȶԣ�����ǶԳƵģ�
��˵����ǰ�ķ�����ƽ��ģ�������Գƣ���˵����ǰ�ַ����ǲ�ƽ��ģ����ַ�
�������Ժ�������еķ��Ŷ���ƽ��ģ�ջ�д�ʱӦ�þ���Ϊ�գ�ͨ���ж�ջ��
�Ƿ�Ϊ�գ�˵���ַ����Ƿ��Ƿ���ƽ��ġ�
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