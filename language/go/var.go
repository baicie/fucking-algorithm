package main

import "fmt"

func main(){
	const lightSpeed = 299792
	var distance = 10000000

	fmt.Println(distance/lightSpeed,"seconds")

	distance = 40000000
	
	fmt.Println(distance/lightSpeed,"seconds")
}