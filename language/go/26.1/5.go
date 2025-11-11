package main

import "fmt"

func main() {
	superpowers := &[3]string{"flying", "invisibility", "super strength"}
	fmt.Println(superpowers[0])
	fmt.Println(superpowers[1:2])
}
