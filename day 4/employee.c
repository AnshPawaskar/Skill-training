#include<stdio.h>

struct Employee_T{
    int id;
    char name[200];
    float salary;
    char  department[50];
};

typedef struct Employee_T Employee;
void readEmployees(Employee emp[],int n);
void displayEmployees(Employee emp[],int n);
Employee findhighestSalary(Employee emp[],int n);

int main(){
    int employeeCount;
    printf("Enter number of employees: ");
    scanf("%d",&employeeCount);
    Employee employees[1000];
    readEmployees(employees,employeeCount);
    displayEmployees(employees,employeeCount);
    Employee highestSalaryEmployees = findhighestSalary(employees,employeeCount);
    printf("\nEmployee with highest salary: %s, %.2f (%s)\n",
    highestSalaryEmployees.name,
    highestSalaryEmployees.salary,
    highestSalaryEmployees.department);
    return 0;
}

void readEmployees(Employee emp[],int n){
    printf("Enter details (ID,Name,Salary,Department):\n");
    for(int i = 0;i < n;i++){
        printf("Employee %d:\n",i+1);
        printf("\nID: ");
        scanf("%d",&emp[i].id);
        printf("Name: ");
        scanf("%s",emp[i].name);
        printf("Salary: ");
        scanf("%f",&emp[i].salary);
        printf("Department: ");
        scanf("%s",emp[i].department);
    }
}

void displayEmployees(Employee emp[],int n){
    printf("Employees:\n");
    for(int i = 0;i < n;i++){
        printf("%d - %s -%.2f - %s\n",emp[i].id,emp[i].name,emp[i].salary,emp[i].department);
    }
}

Employee findhighestSalary(Employee emp[],int n){
    Employee highestSalary = emp[0];
    for(int i = 0;i < n;i++){
        if(emp[i].salary > highestSalary.salary){
            highestSalary=emp[i];
        }            
    }
    return highestSalary;
}