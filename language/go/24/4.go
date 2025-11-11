package main

import "time"

type stardater interface {
	YearDay() int
	Hour() int
}

type sol int

func (s sol) YearDay() int {
	return int(s % 668)
}

func (s sol) Hour() int {
	return 0
}

func stardate(t stardater) float64 {
	doy := float64(t.YearDay())
	h := float64(t.Hour()) / 24.0
	return 1000.0 + doy + h
}

func main() {
	day := time.Date(2419, time.January, 1, 0, 0, 0, 0, time.UTC)
	println(stardate(day))

	s := sol(1422)
	println(stardate(s))
}
