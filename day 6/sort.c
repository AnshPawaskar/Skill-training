#include<stdio.h>
int sortInsertion(float* salaries, int size);
void printSalaries(float* salaries, int size);
int main() {
    float salaries[] = {20.0f, 10.0f, 15.0f, 12.0f, 13.0f};
    int salariiesCount = 5;
    printf("Before sort:\n");printSalaries(salaries, salariiesCount);
    sortInsertion(salaries, salariiesCount);
    printf("After sort:\n");printSalaries(salaries, salariiesCount);
    return 0;
}

void printSalaries(float* salaries, int size) {
    for(int i = 0; i < size; i++) {
        printf("%.2f ", salaries[i]);
    }
    printf("\n");
}
int sortInsertion(float* salaries, int size) {
    for(int i = 1; i < size; i++) {
        int targetIndex = i;
        float target = salaries[targetIndex];
        for( int sortedIndex = i - 1; sortedIndex >= 0 && salaries[sortedIndex] > target; sortedIndex--) {
            salaries[targetIndex] = salaries[sortedIndex];
            targetIndex--;
        }
        if(targetIndex != i) {
            salaries[targetIndex] = target;
        }
    }
}