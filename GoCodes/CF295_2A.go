package main

import "fmt"

func main() {
	var T int
	var str string
	fmt.Scanf("%d", &T)
	fmt.Scan("%d", &str)
	mymap := make(map[string]bool)
	for _, char := range str {
		mymap[char] = true
	}
	if len(mymap) == 26 {
		fmt.Printf("YES\n")
	} else {
		fmt.Printf("NO\n")
	}

}
