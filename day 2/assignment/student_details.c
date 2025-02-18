#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int marks;
    char *name;
} student;

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    student *list = (student *)malloc(n * sizeof(student));
    if (list == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        list[i].name = (char *)malloc(100 * sizeof(char)); 
        if (list[i].name == NULL) {
            printf("Memory allocation for name failed!\n");
            return 1; 
        }

        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", list[i].name);
        printf("Enter Marks: ");
        scanf("%d", &list[i].marks); 
    }

    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %d\n", list[i].name, list[i].marks); 
    }

    for (int i = 0; i < n; i++) {
        free(list[i].name);
    }
    free(list);
    return 0;
}