class Solution {
public:
    int reverse(int x) {
        //�ж�x����
        bool flag = (x > 0 ? true : false);
        //��x��Ϊ���ľ���ֵ
        x = flag ? x : -x;
        //��x�м�λ��
        int num = x;
        int SIZE = 0;
        while (num) {
            SIZE++;
            num/= 10;
        }
        //��ֻ��1λ�����ر���
        if (1 == SIZE) {
            return x;
        }
        //��ȡÿ��������temp ��
        vector<int> temp;
        for (int i = 0; i < SIZE; i++) {
            int k = x % 10;
            if (0 == i && 0 == k);
            else
                temp.push_back(k);
            x /= 10;
        }
        //�õ�������
        long long result = 0;
        for (int i = 0; i < temp.size(); i++) {
            result *= 10;
            result += temp[i];
        }
        result = (flag ? result : -result);
        //�ж��Ƿ����, ��long long ������result
        if (result > INT_MAX || result < INT_MIN) {
            return 0;
        }
        return result;
    }
};