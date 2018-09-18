/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //����ͷ���
        ListNode dummy(-1), *cur = &dummy;
        ListNode *p = l1, *q = l2;
        int jinwei = 0;
        while (p != NULL || q != NULL) {
            int result = jinwei + (p ? p->val : 0) + (q ? q->val : 0);  //ѡ����ʽ
            if (result / 10) {
                jinwei = 1;
            }
            else {
                jinwei = 0;
            }
            ListNode *temp = new ListNode(result % 10);
            cur->next = temp;
            cur = cur->next;
            if (p != NULL) {
                p = p->next;
            }
            if (q != NULL) {
                q = q->next;
            }
        }
        //���������һ����λ�����
        if (jinwei) {
            ListNode *temp = new ListNode(1);
            cur->next = temp;
        }
        return dummy.next;
    }
};