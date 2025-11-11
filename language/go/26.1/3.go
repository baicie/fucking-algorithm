package main

import "fmt"

func main() {
	var administrator *string

	scolese := "Christopher J. Scolese"
	administrator = &scolese
	fmt.Println(*administrator)

	bolden := "Charles F. Bolden"
	administrator = &bolden
	fmt.Println(*administrator)

	bolden = "Maj. Gen. Charles F. Bolden Jr."
	fmt.Println(*administrator)

	*administrator = "Charlie Bolden"
	fmt.Println(bolden)

	major := administrator
	*major = "22222222"
	fmt.Println(bolden)

	println(administrator == major)

	lighefoot := "Robert M. Lightfoot Jr."
	administrator = &lighefoot
	println(administrator == major)

	charles := *major
	*major = "33333333"
	println(charles)
	println(bolden)

	charles = "33333333"
	println(charles == bolden)
	println(&charles == &bolden)
}
