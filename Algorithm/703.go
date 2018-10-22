type KthLargest struct {
    k int //�����k�����
    arr []int //��������k����
}

//��һ�����鱣������k��ֵ��ÿ�θ��º����������һ��ֵ
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