/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

 // soluton 1: 使用哨兵节点
func mergeKLists(lists []*ListNode) *ListNode {
    PreNode := ListNode{-1, nil}
    sum := 0 //记录合并的总数量
    for i := 0; i < len(lists); i++ {
        cur := lists[i]
        if cur == nil {
            continue
        }
        temp := cur
        for cur != nil {
            sum++
            temp = cur
            cur = cur.Next
        }
        //在每个非空链表后面加上哨兵节点（INT_MAX)
        TailNode := new(ListNode)
        TailNode.Val = math.MaxInt64
        TailNode.Next = nil
        temp.Next = TailNode
    }
    count := 0 //记录当前处理到多少个节点
    cur := &PreNode
    for count < sum {
        //找出最小值添加进去
        min := math.MaxInt64
        var ins int
        for i:= 0; i < len(lists); i++ {
            if lists[i] != nil && lists[i].Val < min {
                min = lists[i].Val
                ins = i
            }
        }
        //添加进输出的链表中
        NewNode := new(ListNode)
        NewNode.Val = min
        NewNode.Next = nil
        cur.Next = NewNode
        cur = cur.Next
        //当前最小值的链表向后移一位
        lists[ins] = lists[ins].Next
        count++
    }
    return PreNode.Next
}

// solution 2
func mergeKLists(lists []*ListNode) *ListNode {
    PreNode := ListNode{-1, nil}
    cur := &PreNode
    k := 0 //保存有多少条链表已经处理完了
    for i := 0; i < len(lists); i++ {
        if lists[i] == nil {
            k++
        }
    }
    if k == len(lists) {
        return nil
    }
    for {
        min := math.MaxInt64
        var ins int
        for i:= 0; i < len(lists); i++ {
            if lists[i] != nil && lists[i].Val < min {
                min = lists[i].Val
                ins = i
            }
        }
        //添加进输出的链表中
        NewNode := new(ListNode)
        NewNode.Val = min
        NewNode.Next = nil
        cur.Next = NewNode
        cur = cur.Next
        //当前最小值的链表向后移一位
        lists[ins] = lists[ins].Next
        if lists[ins] == nil {
            k++
        }
        if k == len(lists) {
            break
        }
    }
    return PreNode.Next
}