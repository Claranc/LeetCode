//中序遍历，看是否是递增的
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

//左子树的值小于根节点，右子树大于根节点
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
    //先判断左子树，后判断右子树，两个同时成立返回true
    if Process(root.Left, min, root.Val) == false {
        return false
    } else {
        return Process(root.Right, root.Val, max)
    }
}