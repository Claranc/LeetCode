//Solution 1
class Solution {
public:
    string convert(string s, int numRows) {
        if (1 == numRows) {
            return s;
        }
        //分析s.size()和numRows的大小关系，  s.size()小只有一列
        vector<string> result(s.size()<numRows ? s.size() : numRows);
        bool flag = 0;
        int column = 0; //当前行数
        for (int i = 0; i < s.size(); i++) {
            //将该字符添加到所处的行
            result[column] += s[i];
            //column处在第一行和最后一行变换方向
            if (0 == column || numRows - 1 == column) {
                flag = !flag;
            }
            //移动行数
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