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
    //记录总个数
    sum := 0
    for cur != nil {
        sum++
        cur = cur.Next
    }
    if sum == 1 && n == 1 {
        return nil
    }
    //从头结点开始，便于删除第一个节点
    cur = &PreNode
    count := 0
    for {
        //找到删除节点的前一个节点
        if count == sum - n {
            cur.Next = cur.Next.Next
            break
        }
        cur = cur.Next
        count++
    }
    return PreNode.Next
}