package main

import "fmt"

func main() {
	type location struct {
		name string
		lat  float64
		lon  float64
	}

	lats := []float64{35.0, 45.0, 55.0}
	lons := []float64{15.0, 25.0, 35.0}

	locations := []location{
		{"Bradbury Landing", lats[0], lons[0]},
		{"Columbia Memorial Station", lats[1], lons[1]},
		{"Challenger Memorial Station", lats[2], lons[2]},
	}

	fmt.Println(locations)
}
