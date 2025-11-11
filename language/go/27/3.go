package main

import "fmt"

func mirepoix(ingrdients []string) []string {
	return append(ingrdients, "onion", "carrot", "celery")
}

func main() {
	suop := mirepoix(nil)
	fmt.Println(suop)
}
