package main

import "fmt"

type celsius float64
type kelvin float64

func main() {
	const k kelvin = 294
	c := demo(k)
	fmt.Printf("%c°K is %c°C\n", k, c)
}

func demo(k kelvin) celsius {
	return celsius(k - 273.15)
}

func (k kelvin) celsius() celsius {
	return celsius(k - 273.15)
}
