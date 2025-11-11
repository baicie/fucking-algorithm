package main

import (
	"fmt"
)

func main() {
	temp := map[string]int{
		"Washington": 1789,
		"Adams":      1797,
	}

	temp2 := temp
	fmt.Println("temp2[\"Washington\"] = ", temp2)

	temp2["Washington"] = 1800
	fmt.Println("temp2[\"Washington\"] = ", temp)

	moon := temp["Washington"]

	fmt.Println("moon = ", moon)
}
