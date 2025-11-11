package main

import (
	"fmt"
	"os"
)

func proverbs(name string) error {
	f, err := os.Create(name)
	if err != nil {
		return err
	}
	defer f.Close()

	_, err = fmt.Println(f, "Errors are values.")
	if err != nil {
		return err
	}

	_, err = fmt.Println(f, "Don't just check errors, handle them gracefully.")
	return err
}

func main() {
	err := proverbs("proverbs.txt")
	if err != nil {
		fmt.Println(err)
	}
}
