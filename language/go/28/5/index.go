package main

import (
	"errors"
	"fmt"
	"os"
	"strings"
)

const rows, colums = 9, 9

type Grid [rows][colums]int8

var (
	ErrBounds = errors.New("out of bounds")
	ErrDigit  = errors.New("invalid digit")
)

type SudokuError []error

func (se SudokuError) Error() string {
	var s []string
	for _, err := range se {
		s = append(s, err.Error())
	}
	return strings.Join(s, "\n")
}

func (g *Grid) Set(row, colum int, digit int8) error {
	var errs SudokuError
	if !isBounds(row, colum) {
		errs = append(errs, ErrBounds)
	}

	if !validDigit(digit) {
		errs = append(errs, ErrDigit)
	}

	g[row][colum] = digit
	return nil
}

func validDigit(digit int8) bool {
	if digit < 1 || digit > 9 {
		return false
	}
	return true
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
