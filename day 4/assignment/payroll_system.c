#include <stdio.h>
#include <string.h>

struct Employee_t {
    int emp_id;
    char name[100];
    int basic_salary;
    int allowances;
    int gross_salary;
};

typedef struct Employee_t Employee;

void readEmployees(Employee employees[], int n);
void computeGrossSalary(Employee employees[], int n);
void saveToFile(Employee employees[], int n);
void searchEmployee(Employee employees[], int n, int emp_id);

int main() {
    int n;
    Employee employees[100];
    printf("Enter number of employees: ");
    scanf("%d", &n);
  
    readEmployees(employees, n);
   
    computeGrossSalary(employees, n);
    
    saveToFile(employees, n);
    
    int emp_id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &emp_id);
    
    searchEmployee(employees, n, emp_id);

    return 0;
}

void readEmployees(Employee employees[], int n) {
    printf("Enter employee details (Employee ID, Name, Basic Salary, Allowances):\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employees[i].emp_id);
        printf("Name: ");
        scanf("%s", employees[i].name);  
        printf("Basic Salary: ");
        scanf("%d", &employees[i].basic_salary);
        printf("Allowances: ");
        scanf("%d", &employees[i].allowances);
    }
}

void computeGrossSalary(Employee employees[], int n) {
    for (int i = 0; i < n; i++) {
        employees[i].gross_salary = employees[i].basic_salary + employees[i].allowances;
    }
}

void saveToFile(Employee employees[], int n) {
    FILE *file = fopen("payroll.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d, %s, ₹%d, ₹%d, ₹%d\n", employees[i].emp_id, employees[i].name,
                employees[i].basic_salary, employees[i].allowances, employees[i].gross_salary);
    }

    printf("\nRecord saved in \"payroll.txt\"\n");
    fclose(file);
}

void searchEmployee(Employee employees[], int n, int emp_id) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (employees[i].emp_id == emp_id) {
            found = 1;
            printf("\nEmployee: %s\n", employees[i].name);
            printf("Gross Salary: %d\n", employees[i].gross_salary);
            break;
        }
    }
    if (!found) {
        printf("Employee ID %d not found.\n", emp_id);
    }
}
