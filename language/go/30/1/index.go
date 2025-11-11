package main

import (
	"fmt"
	"time"
)

func main() {
	go sleepyGopher()
	time.Sleep(4 * time.Second)
}

func sleepyGopher() {
	time.Sleep(2 * time.Second)
	fmt.Println("...snore...")
}
