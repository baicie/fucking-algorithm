package main

import "fmt"

func distance2(loc1, loc2 location) float64 {
	return 0
}

type location struct {
	lat float64
	lon float64
}

func main() {

	var curiosity location

	curiosity.lat = -4.5895
	curiosity.lon = 137.4417

	var opportunity location
	opportunity.lat = -1.9462
	opportunity.lon = 354.4734

	fmt.Println(curiosity, opportunity)
}
