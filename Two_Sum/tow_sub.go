package main

import "fmt"

//引数がintのスライスnumとintのtargetで，返り値がintのスライスって意味
func twoSum(nums []int, target int) []int {
	var rnum [] int

	rnum = make([]int, 2)
	for i := 0; (i + 1) <  len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
            if (nums[i] + nums[j]) == target {
				rnum[0] = i
				rnum[1] = j
				return rnum
			}
		}
	}
    return rnum
}

func main() {
	var rnum [] int

	nums := []int{1,2,3,4,5}
	target := 3
	rnum = twoSum(nums, target)
	fmt.Println(rnum[0], rnum[1]);
}