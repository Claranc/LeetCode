class Solution {
public:
    bool isPalindrome(int x) {
        //С��0�϶����ǻ�����
        if (x < 0 || (0 == x % 10 && x > 0)) {
            return false;
        }
        //0~9�ǻ�����
        if (0 == x / 10) {
            return true;
        }
        //ת��Ϊ�ַ���
        string s = to_string(x);
        int SIZE = s.size();
        //flag�����Ƿ�Ϊ������
        bool flag = true;
        //�ж��Ƿ�Ϊ���������ֱ��ж��ַ�������Ϊ������ż��
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