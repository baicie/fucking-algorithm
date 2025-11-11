package main

import (
	"fmt"
	"math"
)

type loaction struct {
	lat, long float64
}

type world struct {
	radius float64
}

func (w world) distance(p1, p2 loaction) float64 {
	s1, c1 := math.Sincos(red(p1.lat))
	s2, c2 := math.Sincos(red(p2.lat))
	clong := math.Cos(red(p1.long - p2.long))
	return w.radius * math.Acos(s1*s2+c1*c2*clong)
}

func red(deg float64) float64 {
	return deg * math.Pi / 180
}

func main() {
	var mars = world{radius: 3389.5}
	spirit := loaction{-14.5684, 175.472636}
	opportunity := loaction{-1.9462, 354.4734}

	dist := mars.distance(spirit, opportunity)
	fmt.Printf("%.2f km\n", dist)
}
