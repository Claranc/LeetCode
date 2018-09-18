class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //把两个有序数组合并成一个有序数组（从小到大）
        vector<int> temp;
        int p_size = nums1.size();
        int q_size = nums2.size();
        int p = 0, q = 0;
        while (p < p_size || q < q_size) {
            //超出范围用INT_MAX表示，不会被选取
            if ((p < p_size ? nums1[p] : INT_MAX) < (q < q_size ? nums2[q] : INT_MAX)) {
                temp.push_back(nums1[p]);
                p++;
            }
            else {
                temp.push_back(nums2[q]);
                q++;
            }
        }
        //总数单或者双
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