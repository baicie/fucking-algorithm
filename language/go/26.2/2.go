package main

import "fmt"

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
}
