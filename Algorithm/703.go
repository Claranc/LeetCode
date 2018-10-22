//Solution1  用一个数组保存最大的k个值，每次更新后排序，输出第一个值
type KthLargest struct {
    k int //输出第k大的数
    arr []int //保存最大的k个数
}

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

//Solution 2: 使用min heap
type IntHeap []int  // 定义一个类型

func (h IntHeap) Len() int { return len(h) }  // 绑定len方法,返回长度

func (h IntHeap) Less(i, j int) bool {  // 绑定less方法
	return h[i] < h[j]  // 如果h[i]<h[j]生成的就是小根堆，如果h[i]>h[j]生成的就是大根堆
}
func (h IntHeap) Swap(i, j int) {  // 绑定swap方法，交换两个元素位置
	h[i], h[j] = h[j], h[i]
}

func (h *IntHeap) Pop() interface{} {  // 绑定pop方法，从最后拿出一个元素并返回
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (h *IntHeap) Push(x interface{}) {  // 绑定push方法，插入新元素
	*h = append(*h, x.(int))
}

type KthLargest struct {
    k int //输出第k大的数
    arr *IntHeap //总数为k个的min heap
}


func Constructor(k int, nums []int) KthLargest {
    h := &IntHeap{} //建立空堆
    heap.Init(h)
    for _,v := range nums {
        heap.Push(h, v) //将初始值添加进去
    }
    for h.Len() > k { //超出范围就把多的pop出来
        heap.Pop(h)
    }
    return KthLargest{k, h}
}

func (this *KthLargest) Add(val int) int {
    if this.arr.Len() < this.k {
        heap.Push(this.arr, val)
        if this.arr.Len() == this.k { 
            return (*this.arr)[0]
        } 
    }
    if val <= (*this.arr)[0] {
        return (*this.arr)[0]
    } else {
        heap.Pop(this.arr)
        heap.Push(this.arr, val)
        return (*this.arr)[0]
    }
}