package grades

func init() {
	students = []Student{
		{
			ID:        1,
			FirstName: "John",
			LastName:  "Doe",
			Grades: []Grade{
				{
					Title: "Quiz 1",
					Type:  GradeQuiz,
					Score: 85,
				},
				{
					Title: "Quiz 2",
					Type:  GradeExam,
					Score: 88,
				},
				{
					Title: "Quiz 3",
					Type:  GradeTest,
					Score: 92,
				},
			},
		},
		{
			ID:        2,
			FirstName: "Jane",
			LastName:  "Smith",
			Grades: []Grade{
				{
					Title: "Quiz 1",
					Type:  GradeQuiz,
					Score: 90,
				},
				{
					Title: "Quiz 2",
					Type:  GradeExam,
					Score: 92,
				},
				{
					Title: "Quiz 3",
					Type:  GradeTest,
					Score: 88,
				},
			},
		},
		{
			ID:        3,
			FirstName: "David",
			LastName:  "Johnson",
			Grades: []Grade{
				{
					Title: "Quiz 1",
					Type:  GradeQuiz,
					Score: 78,
				},
				{
					Title: "Quiz 2",
					Type:  GradeExam,
					Score: 85,
				},
				{
					Title: "Quiz 3",
					Type:  GradeTest,
					Score: 90,
				},
			},
		},
		{
			ID:        4,
			FirstName: "Emily",
			LastName:  "Brown",
			Grades: []Grade{
				{
					Title: "Quiz 1",
					Type:  GradeQuiz,
					Score: 92,
				},
				{
					Title: "Quiz 2",
					Type:  GradeExam,
					Score: 88,
				},
				{
					Title: "Quiz 3",
					Type:  GradeTest,
					Score: 85,
				},
			},
		},
		{
			ID:        5,
			FirstName: "Michael",
			LastName:  "Davis",
			Grades: []Grade{
				{
					Title: "Quiz 1",
					Type:  GradeQuiz,
					Score: 85,
				},
				{
					Title: "Quiz 2",
					Type:  GradeExam,
					Score: 90,
				},
				{
					Title: "Quiz 3",
					Type:  GradeTest,
					Score: 92,
				},
			},
		},
		{
			ID:        6,
			FirstName: "Olivia",
			LastName:  "Wilson",
			Grades: []Grade{
				{
					Title: "Quiz 1",
					Type:  GradeQuiz,
					Score: 88,
				},
				{
					Title: "Quiz 2",
					Type:  GradeExam,
					Score: 92,
				},
				{
					Title: "Quiz 3",
					Type:  GradeTest,
					Score: 90,
				},
			},
		},
	}
}
