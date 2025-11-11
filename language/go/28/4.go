package main

import (
	"errors"
	"fmt"
	"os"
)

const rows, colums = 9, 9

type Grid [rows][colums]int8

var (
	ErrBounds = errors.New("out of bounds")
	ErrDigit  = errors.New("invalid digit")
)

func (g *Grid) Set(row, colum int, digit int8) error {
	if !isBounds(row, colum) {
		return ErrBounds
	}
	g[row][colum] = digit
	return nil
}

func isBounds(row, colum int) bool {
	if row < 0 || row > rows {
		return false
	}
	if colum < 0 || colum > colums {
		return false
	}
	return true
}

func main() {
	var g Grid
	err := g.Set(10, 0, 5)
	if err != nil {
		switch err {
		case ErrBounds, ErrDigit:
			fmt.Println("error setting value")
		default:
			fmt.Println(err)
		}
		os.Exit(1)
	}
}
