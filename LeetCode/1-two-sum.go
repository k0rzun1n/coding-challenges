//go:build ignore

package main

import "fmt"

func twoSum(nums []int, target int) []int {
	// runtime.GC(); //rt:mem; 5:99 with; 100:15 without
	m := make(map[int]int)
	for i, num := range nums {
		if val, p := m[target-num]; p {
			return []int{val, i}
		}
		m[num] = i
	}
	return nil
}

func main() {
	// result := twoSum([]int{2, 7, 15, 11}, 18)
	result := twoSum([]int{3, 3}, 6)
	fmt.Print(result)
}
