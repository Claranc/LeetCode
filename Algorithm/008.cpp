class Solution {
public:
    int myAtoi(string str) {
        //������Ϊ��
        if (str.empty()) {
            return 0;
        }
        //�鿴��һ���ǿո��ַ��Ƿ�Ϊ�����Ż�����
        int j = str.find_first_not_of(' ');
        if ((48 <= str[j] && str[j] <= 57) || str[j] == '-' || str[j] == '+');
        else {
            return 0;
        }
        //�����ı�־, falseΪ����trueΪ��
        bool flag;
        //���ź�һ���ַ�����Ϊ����
        if (str[j] == '-') { 
            flag = false; 
            if (str[j + 1]<48 || str[j + 1]>57)
                return 0;
        }
        else {
            flag = true;
            if(str[j] == '+') {
                if (str[j + 1] < 48 || str[j + 1]>57)
                    return 0;
            }
        }
        //�������֣�flag2Ϊ�Ƿ�ʼ��¼�ı�־
        int num = 0;
        bool flag2 = false;
        for (int i = 0; i<str.size(); i++) {
            if ((48 <= str[i] && str[i] <= 57)) {
                flag2 = true;
                int tmp = num;
                num = num * 10 + (str[i] - 48);
                //�ж��Ƿ����
                if (num / 10 != tmp && flag) {
                    return INT_MAX;
                }
                if (num / 10 != tmp && !flag) {
                    return INT_MIN;
                }
            }
            else {
                if (flag2 && ((str[i] < 48) || (str[i] > 57))) {
                    break;
                }
            }
        }
        return flag?num : -num;
    }
};