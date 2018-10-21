/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
    PreNode := ListNode{-1, nil}
    sum := 0 //��¼�ϲ���������
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
        //��ÿ���ǿ������������ڱ��ڵ㣨INT_MAX)
        TailNode := new(ListNode)
        TailNode.Val = math.MaxInt64
        TailNode.Next = nil
        temp.Next = TailNode
    }
    count := 0 //��¼��ǰ�������ٸ��ڵ�
    cur := &PreNode
    for count < sum {
        //�ҳ���Сֵ��ӽ�ȥ
        min := math.MaxInt64
        var ins int
        for i:= 0; i < len(lists); i++ {
            if lists[i] != nil && lists[i].Val < min {
                min = lists[i].Val
                ins = i
            }
        }
        //��ӽ������������
        NewNode := new(ListNode)
        NewNode.Val = min
        NewNode.Next = nil
        cur.Next = NewNode
        cur = cur.Next
        //��ǰ��Сֵ�����������һλ
        lists[ins] = lists[ins].Next
        count++
    }
    return PreNode.Next
}