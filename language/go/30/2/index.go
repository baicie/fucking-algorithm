package main

import (
	"fmt"
	"time"
)

func main() {
	for i := 0; i < 5; i++ {
		go sleepyGopher(i)
	}

	time.Sleep(4 * time.Second)
}

func sleepyGopher(i int) {
	time.Sleep(2 * time.Second)
	fmt.Println("...snore...", i)
}
