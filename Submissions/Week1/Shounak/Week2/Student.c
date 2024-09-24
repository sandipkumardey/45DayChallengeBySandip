#include <stdio.h>
#include <string.h>

#define MAX_GRADES 100

typedef struct {
    char name[50];
    int grades[MAX_GRADES];
    int grade_count;
} Student;

void initializeStudent(Student *student, const char *name) {
    strcpy(student->name, name);
    student->grade_count = 0;
}

void addGrade(Student *student, int grade) {
    if (student->grade_count < MAX_GRADES) {
        student->grades[student->grade_count] = grade;
        student->grade_count++;
    } else {
        printf("Cannot add more grades. Maximum limit reached.\n");
    }
}

float calculateAverage(const Student *student) {
    if (student->grade_count == 0) {
        return 0.0;
    }

    int sum = 0;
    for (int i = 0; i < student->grade_count; i++) {
        sum += student->grades[i];
    }
    return (float)sum / student->grade_count;
}

void displayStudentInfo(const Student *student) {
    printf("Student Name: %s\n", student->name);
    printf("Grades: ");
    for (int i = 0; i < student->grade_count; i++) {
        printf("%d ", student->grades[i]);
    }
    printf("\n");
    printf("Average Grade: %.2f\n", calculateAverage(student));
}

int main() {
    Student student;
    initializeStudent(&student, "John Doe");
    addGrade(&student, 85);
    addGrade(&student, 90);
    addGrade(&student, 78);

    displayStudentInfo(&student);

    return 0;
}
