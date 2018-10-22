type KthLargest struct {
    k int //输出第k大的数
    arr []int //保存最大的k个数
}

//用一个数组保存最大的k个值，每次更新后排序，输出第一个值
func Constructor(k int, nums []int) KthLargest {
    sort.Ints(nums)
    if(len(nums) - k >= 0) { //能填满数组arr
        temp := nums[len(nums) - k:] 
        p := KthLargest{k, temp}
        return p
    } else { //不能填满数组arr
        p := KthLargest{k, nums}
        return p
    }
    
}


func (this *KthLargest) Add(val int) int {
    if len(this.arr) < this.k { //如果未填满则补充进去
        this.arr = append(this.arr, val)
        sort.Ints(this.arr)
        if len(this.arr) == this.k { //补充后刚好填满就输出（不考虑补充后还没满）
            return this.arr[0]
        } 
    }
    //如果已经是满的
    if val <= this.arr[0] {
        return this.arr[0]
    } else {
        this.arr[0] = val
        sort.Ints(this.arr)
        return this.arr[0]
    }
}