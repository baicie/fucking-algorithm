package main

import "strings"

var t interface {
	talk() string
}

type martian struct{}

func (m martian) talk() string {
	return "nack nack"
}

type laser int

func (l laser) talk() string {
	return strings.Repeat("pew ", int(l))
}

func main() {
	t = martian{}
	println(t.talk())
	t = laser(3)
	println(t.talk())
}
