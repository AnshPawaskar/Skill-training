#include <stdio.h>
#include <string.h>

struct Student_t {
    int id;
    char name[100];
    int marks[3];
    int total;
    float avg;
    char grade[10];
};

typedef struct Student_t Student;

void readStudents(Student students[], int n);
void calculateGrades(Student students[], int n);
void displayStudents(Student students[], int n);

int main() {
    int n;
    Student students[100];
    printf("Enter number of students: ");
    scanf("%d", &n);
    readStudents(students, n);
    calculateGrades(students, n);
    displayStudents(students, n);
    return 0;
}

void readStudents(Student students[], int n) {
    printf("Enter details (ID, Name, Marks in 3 subjects):\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks in 3 subjects:\n");
        for (int j = 0; j < 3; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
    }
}

void calculateGrades(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += students[i].marks[j];
        }
        students[i].total = sum;
        students[i].avg = (float)sum / 3;

        if (students[i].avg >= 90) {
            strcpy(students[i].grade, "A");
        } else if (students[i].avg >= 75) {
            strcpy(students[i].grade, "B");
        } else {
            strcpy(students[i].grade, "C");
        }
    }
}

void displayStudents(Student students[], int n) {
    printf("Student Report Card:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s - Total: %d, Average: %.2f, Grade: %s\n",
               students[i].name, students[i].total, students[i].avg, students[i].grade);
    }
}
