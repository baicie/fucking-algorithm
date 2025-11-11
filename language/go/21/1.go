package main

import "fmt"

func distance(lat1 float64, lon1 float64, lat2 float64, lon2 float64) float64 {
	return 0
}

func main() {
	var curiosity struct {
		lat float64
		lon float64
	}

	curiosity.lat = -4.5895
	curiosity.lon = 137.4417

	fmt.Println(curiosity.lat, curiosity.lon)
	fmt.Println(curiosity)
}
