class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //�ַ�������Ϊ0��1ʱ��Ĵ���
        if (0 == s.size() || 1 == s.size()) {
            return s.size();
        }
        int max = 0; //��¼���ƥ�䳤��
        for (int i = 0; i < s.size(); i++) {
            bool flag = 0;  //����Ƿ�����ظ��ַ�
            for (int j = i + 1; j < s.size(); j++) {
                for (int k = i; k < j; k++) {
                    if (s[k] == s[j]) {
                        flag = 1;
                        //��ʱ�����ظ������ȴ��ڵ�ǰ����ĳ��ȣ�����
                        if (j - i > max) { 
                            max = j - i;
                        }
                        break;
                    }
                }
                //�ӵ�ǰ���ַ������δ�����ظ��������ǰ�ͱ�������ֵ
                if (s.size() - 1 == j && 0 == flag) {
                    return max > s.size() - i ? max : s.size() - i;
                }
                //�����ظ����ˣ��������
                if (1 == flag)
                    break;
            }
        }
        return max;
    }
};