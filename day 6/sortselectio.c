#include<stdio.h>
int sortInsertion(float* salaries, int size);
void printSalaries(float* salaries, int size);
void swap(float* first ,float* second);
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

void swap(float* first,float* second){
    float temp = (*first);
    (*first) = (*second);
    (*second) = temp;
}

int sortInsertion(float* salaries, int size) {
    for(int i = 0; i < (size-1); i++) {
        int midIndex = i;
        for( int j = i + 1; j < size; j++) {
            if(salaries[j] < salaries[midIndex]){
                midIndex = j;
            }
        }
        if(i != midIndex) {
            swap(&salaries[i],&salaries[midIndex]);
        }
    }
}