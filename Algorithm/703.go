//Solution1  ��һ�����鱣������k��ֵ��ÿ�θ��º����������һ��ֵ
type KthLargest struct {
    k int //�����k�����
    arr []int //��������k����
}

func Constructor(k int, nums []int) KthLargest {
    sort.Ints(nums)
    if(len(nums) - k >= 0) { //����������arr
        temp := nums[len(nums) - k:] 
        p := KthLargest{k, temp}
        return p
    } else { //������������arr
        p := KthLargest{k, nums}
        return p
    }
    
}


func (this *KthLargest) Add(val int) int {
    if len(this.arr) < this.k { //���δ�����򲹳��ȥ
        this.arr = append(this.arr, val)
        sort.Ints(this.arr)
        if len(this.arr) == this.k { //�����պ�����������������ǲ����û����
            return this.arr[0]
        } 
    }
    //����Ѿ�������
    if val <= this.arr[0] {
        return this.arr[0]
    } else {
        this.arr[0] = val
        sort.Ints(this.arr)
        return this.arr[0]
    }
}

//Solution 2: ʹ��min heap
type IntHeap []int  // ����һ������

func (h IntHeap) Len() int { return len(h) }  // ��len����,���س���

func (h IntHeap) Less(i, j int) bool {  // ��less����
	return h[i] < h[j]  // ���h[i]<h[j]���ɵľ���С���ѣ����h[i]>h[j]���ɵľ��Ǵ����
}
func (h IntHeap) Swap(i, j int) {  // ��swap��������������Ԫ��λ��
	h[i], h[j] = h[j], h[i]
}

func (h *IntHeap) Pop() interface{} {  // ��pop������������ó�һ��Ԫ�ز�����
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (h *IntHeap) Push(x interface{}) {  // ��push������������Ԫ��
	*h = append(*h, x.(int))
}

type KthLargest struct {
    k int //�����k�����
    arr *IntHeap //����Ϊk����min heap
}


func Constructor(k int, nums []int) KthLargest {
    h := &IntHeap{} //�����ն�
    heap.Init(h)
    for _,v := range nums {
        heap.Push(h, v) //����ʼֵ��ӽ�ȥ
    }
    for h.Len() > k { //������Χ�ͰѶ��pop����
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