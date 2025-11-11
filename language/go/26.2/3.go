package main

import (
	"fmt"
	"time"
)

type person struct {
	name, superpower string
	age              int
}

func (p *person) birthday() {
	p.age++
}

func main() {
	rebecca := person{
		name:       "Rebecca",
		superpower: "imagination",
		age:        14,
	}
	rebecca.birthday()
	fmt.Printf("%+v\n", rebecca)

	nathan := person{
		name: "Nathan",
		age:  17,
	}
	nathan.birthday()
	fmt.Printf("%+v\n", nathan)

	const layout = "Mon, Jan 2, 2006"
	day := time.Now()
	tomorrow := day.Add(24 * time.Hour)

	fmt.Println(day.Format(layout))
	fmt.Println(tomorrow.Format(layout))
}
