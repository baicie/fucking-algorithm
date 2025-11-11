package main

import "fmt"

type location2 struct {
	lat, lon float64
}

func main() {
	opportunity := location2{-1.9462, 354.4734}
	curiosity := location2{-4.5895, 137.4417}

	fmt.Println(curiosity, opportunity)
}
