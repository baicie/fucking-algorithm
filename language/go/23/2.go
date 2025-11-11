package main

import "fmt"

type report struct {
	sol int
	temperature
	location
}
type temperature struct {
	high, low celsius
}

type location struct {
	lat, long float64
}

type celsius float64

func (t temperature) average() celsius {
	return (t.high + t.low) / 2
}

func main() {
	bradbury := location{-4.5895, 137.4417}
	t := temperature{high: -1.0, low: -78.0}
	fmt.Println(t.average())
	report := report{sol: 15, temperature: t, location: bradbury}

	fmt.Println(report)
	fmt.Println(report.average())
	fmt.Printf("A balmy %v C\n", report.temperature.high)
}
