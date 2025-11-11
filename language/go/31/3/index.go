package main

import (
	"time"
)

func worker() {
	n := 0
	next := time.After(time.Second)
	for {
		select {
		case <-next:
			n++
			println(n)
			next = time.After(time.Second)
		}
	}
}

func main() {
	go worker()
}
