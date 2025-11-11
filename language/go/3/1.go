package main

import (
	"fmt"
	"strings"
)

func main()  {
	var str = "wolk oytside"
	var exit = strings.Contains(str,"oytside")

	fmt.Println(exit)
}