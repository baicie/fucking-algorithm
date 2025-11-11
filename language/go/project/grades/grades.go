package grades

import (
	"fmt"
	"sync"
)

type Student struct {
	ID        int
	FirstName string
	LastName  string
	Grades    []Grade
}

func (s Student) Average() float64 {
	var result float64

	for _, grade := range s.Grades {
		result += grade.Score

	}
	return result / float64(len(s.Grades))
}

type Students []Student

var (
	students      Students
	studentsMutex sync.Mutex
)

func (ss Students) GetByID(id int) (*Student, error) {
	for i := range ss {
		if ss[i].ID == id {
			return &ss[i], nil
		}
	}
	return nil, fmt.Errorf("Student with ID %d not found", id)
}

type GradeType string

const (
	GradeQuiz = GradeType("quiz")
	GradeTest = GradeType("test")
	GradeExam = GradeType("exam")
)

type Grade struct {
	Title string
	Type  GradeType
	Score float64
}
