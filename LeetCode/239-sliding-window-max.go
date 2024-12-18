//go:build ignore

package main

import "fmt"

//rt:mem 97:97
func maxSlidingWindow(nums []int, k int) []int {
	ans := make([]int, 0, len(nums)-k+1)
	dq := make([]int, k)

	front, back, cnt := 0, k-1, 0

	for i, n := range nums {
		if cnt > 0 && dq[front] <= i-k {
			front = (front + 1) % k
			cnt--
		}

		for cnt > 0 && nums[dq[back]] <= n {
			back = (k + back - 1) % k
			cnt--
		}
		back = (back + 1) % k
		cnt++
		dq[back] = i

		if i >= k-1 {
			ans = append(ans, nums[dq[front]])
		}
	}
	return ans
}

func main() {
	fmt.Println(maxSlidingWindow([]int{1, 3, -1, -3, 5, 3, 6, 7}, 3))
	fmt.Println(maxSlidingWindow([]int{7, 2, 4}, 2))
}
