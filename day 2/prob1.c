#include<stdio.h>

void readDetails(float* p_salary,int* p_score,int* p_work){
    printf("Enter Salary: ");
    scanf("%f",p_salary);
    printf("Enter Credit score: ");
    scanf("%d",p_score);
    printf("Enter Experience(Years): ");
    scanf("%f",p_work);
}

int eligible_condition(float salary,int score,int work){
    if (salary >= 30000 && score >= 750 && work >= 2){
    printf("Loan Approved");
    }
    else{
        printf("Loan Rejected");
    }
    return (salary,score,work);
} 

int main(){
    float salary;
    int score;
    int work;
    readDetails(&salary,&score,&work);
    eligible_condition(salary,score,work);
    return 0;
}
