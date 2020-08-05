package main

import (
	"fmt"
	"sort"
)

func intScanln(n int) []int {
	x := make([]int, n)
	y := make([]interface{}, len(x))
	for i := range x {
		y[i] = &x[i]
	}
	n, err := fmt.Scanln(y...)
	if err == nil {
		x = x[:n]
	}
	return x
}

func main() {
	var T int
	fmt.Scanf("%d\n", &T)
	for T > 0 {
		T--
		var n, x int
		fmt.Scanf("%d %d\n", &n, &x)
		savings := intScanln(n)
		// for i := 0; i < n; i++ {
		// 	fmt.Scanf("%d", &savings[i])

		// }
		sort.Ints(savings)
		ans := 0
		sum := 0
		for i := n - 1; i >= 0; i-- {
			div := n - i
			sum = sum + savings[i]
			eq := x * div
			if eq > sum {
				break
			} else {
				ans = div
			}
		}
		fmt.Printf("%d\n", ans)
	}
}
