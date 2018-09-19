//Solution 1
class Solution {
public:
    string convert(string s, int numRows) {
        if (1 == numRows) {
            return s;
        }
        //����s.size()��numRows�Ĵ�С��ϵ��  s.size()Сֻ��һ��
        vector<string> result(s.size()<numRows ? s.size() : numRows);
        bool flag = 0;
        int column = 0; //��ǰ����
        for (int i = 0; i < s.size(); i++) {
            //�����ַ���ӵ���������
            result[column] += s[i];
            //column���ڵ�һ�к����һ�б任����
            if (0 == column || numRows - 1 == column) {
                flag = !flag;
            }
            //�ƶ�����
            if (flag) {
                column++;
            }
            else {
                column--;
            }
        }
        string ret;
        for (auto a : result) {
            ret += a;
        }
        return ret;
    }
};