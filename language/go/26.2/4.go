package main

import "fmt"

type stats struct {
	level            int
	endurance, helth int
}

func levelUp(s *stats) {
	s.level++
	s.endurance = 42 + (14 * s.level)
	s.helth = 5 + (s.endurance / 10)
}

type character struct {
	name  string
	stats stats
}

func main() {
	player := character{name: "Matilda"}
	levelUp(&player.stats)

	fmt.Printf("%+v\n", player.stats)
}
