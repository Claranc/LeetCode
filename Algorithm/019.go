/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    PreNode := ListNode{-1, head}
    cur := head
    //��¼�ܸ���
    sum := 0
    for cur != nil {
        sum++
        cur = cur.Next
    }
    if sum == 1 && n == 1 {
        return nil
    }
    //��ͷ��㿪ʼ������ɾ����һ���ڵ�
    cur = &PreNode
    count := 0
    for {
        //�ҵ�ɾ���ڵ��ǰһ���ڵ�
        if count == sum - n {
            cur.Next = cur.Next.Next
            break
        }
        cur = cur.Next
        count++
    }
    return PreNode.Next
}