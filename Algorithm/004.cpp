class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //��������������ϲ���һ���������飨��С����
        vector<int> temp;
        int p_size = nums1.size();
        int q_size = nums2.size();
        int p = 0, q = 0;
        while (p < p_size || q < q_size) {
            //������Χ��INT_MAX��ʾ�����ᱻѡȡ
            if ((p < p_size ? nums1[p] : INT_MAX) < (q < q_size ? nums2[q] : INT_MAX)) {
                temp.push_back(nums1[p]);
                p++;
            }
            else {
                temp.push_back(nums2[q]);
                q++;
            }
        }
        //����������˫
        int num = p_size + q_size;
        if (0 == num % 2) {
            double t1 = (double)temp[(num / 2) - 1];
            double t2 = (double)temp[num / 2];
            return (t1 + t2) / 2;
        }
        else {
            return (double)temp[(num - 1) / 2];
        }
    }
};