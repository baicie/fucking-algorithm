package main

import "fmt"

func main() {
	canada := "Canada"

	var home *string
	fmt.Printf("%T\n", home)

	home = &canada
	println(*home)
}
