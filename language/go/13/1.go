package main

import "fmt"

func main() {
	type demo float64

	const degrees = 20
	var temp demo = degrees
	temp += 10
	fmt.Println(temp)
}
