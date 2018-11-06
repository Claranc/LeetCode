//������������Ƿ��ǵ�����
func isValidBST(root *TreeNode) bool {
    if root == nil {
        return true
    }
    a := []int{}
    ZhongxuBianli(root, &a)
    for i := 1; i < len(a); i++ {
        if a[i] <= a[i-1] {
            return false
        }
    }
    return true
}

func ZhongxuBianli(root *TreeNode, a  *[]int) {
    if root != nil {
        ZhongxuBianli(root.Left, a)
        (*a) = append((*a), root.Val)
        ZhongxuBianli(root.Right, a)
    }   
}

//��������ֵС�ڸ��ڵ㣬���������ڸ��ڵ�
func isValidBST(root *TreeNode) bool {
    if root == nil {
        return true
    }
    flag := Process(root, math.MinInt64, math.MaxInt64)
    return flag
}

func Process(root *TreeNode, min, max int) bool {
    if root == nil {
        return true
    }
    if root.Val <= min || root.Val >= max {
        return false
    }
    //���ж������������ж�������������ͬʱ��������true
    if Process(root.Left, min, root.Val) == false {
        return false
    } else {
        return Process(root.Right, root.Val, max)
    }
}