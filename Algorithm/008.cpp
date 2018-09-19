class Solution {
public:
    int myAtoi(string str) {
        //若输入为空
        if (str.empty()) {
            return 0;
        }
        //查看第一个非空格字符是否为正负号或数字
        int j = str.find_first_not_of(' ');
        if ((48 <= str[j] && str[j] <= 57) || str[j] == '-' || str[j] == '+');
        else {
            return 0;
        }
        //正负的标志, false为负，true为正
        bool flag;
        //符号后一个字符必须为数字
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
        //保存数字，flag2为是否开始记录的标志
        int num = 0;
        bool flag2 = false;
        for (int i = 0; i<str.size(); i++) {
            if ((48 <= str[i] && str[i] <= 57)) {
                flag2 = true;
                int tmp = num;
                num = num * 10 + (str[i] - 48);
                //判断是否溢出
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