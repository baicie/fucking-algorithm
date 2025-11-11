package main

import "fmt"

func terraform(perfix string, worlds ...string) []string {
	newWorlds := make([]string, len(worlds))
	for i := range worlds {
		newWorlds[i] = perfix + " " + worlds[i]
	}
	return newWorlds
}

func main() {
	towWorlds := []string{"New", "Venus", "Mars"}
	fmt.Println(towWorlds)

	planets := []string{"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"}
	newPlanets := terraform("New", planets...)
	fmt.Println(newPlanets)
}
