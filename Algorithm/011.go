func maxArea(height []int) int {
    max := 0
    for i,start := range height[:len(height)-1] {
        for j := i+1; j < len(height); j++ {
            temp := (j - i) * min(start, height[j])
            if(max < temp) {
                max = temp
            }
        }
    }
    return max
}

func min(x,y int) int {
    if x >=y {
        return y
    } else {
        return x
    }
}