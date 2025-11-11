package main

import "fmt"

func reset(board *[8][8]rune) {
	for i := range board {
		for j := range board[i] {
			board[i][j] = 'r'
		}
	}
}

func main() {
	var board [8][8]rune
	reset(&board)

	fmt.Printf("%c\n", board[0][0])
}
