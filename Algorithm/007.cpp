class Solution {
public:
    int reverse(int x) {
        //判断x正负
        bool flag = (x > 0 ? true : false);
        //把x变为它的绝对值
        x = flag ? x : -x;
        //求x有几位数
        int num = x;
        int SIZE = 0;
        while (num) {
            SIZE++;
            num/= 10;
        }
        //若只有1位，返回本身
        if (1 == SIZE) {
            return x;
        }
        //提取每个数放入temp 中
        vector<int> temp;
        for (int i = 0; i < SIZE; i++) {
            int k = x % 10;
            if (0 == i && 0 == k);
            else
                temp.push_back(k);
            x /= 10;
        }
        //得到逆序数
        long long result = 0;
        for (int i = 0; i < temp.size(); i++) {
            result *= 10;
            result += temp[i];
        }
        result = (flag ? result : -result);
        //判断是否溢出, 用long long 来保存result
        if (result > INT_MAX || result < INT_MIN) {
            return 0;
        }
        return result;
    }
};