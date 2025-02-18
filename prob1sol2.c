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
    printf("Loan Approved\n");
    }
    else{
        printf("Loan Rejected\n");
    }
    return (salary,score,work);
} 

int doTask(){
    float salary;
    int score;
    int work;
    readDetails(&salary,&score,&work);
    eligible_condition(salary,score,work);
}

int main(){
    int choice;
    do{
        doTask();
        printf("Do you want to continue(1/0)\n");
        scanf("%d",&choice);
    }while(choice == 1);
    return 0;
}