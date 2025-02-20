#include <stdio.h>
#include <string.h>

struct Medicine_t {
    int med_id;
    char name[100];
    char expiry_date[11];  
    float price;
};

typedef struct Medicine_t Medicine;

void readMedicines(Medicine medicines[], int n);
void saveToFile(Medicine medicines[], int n);
void displayMedicines(Medicine medicines[], int n);
int compareExpiryDate(const void *a, const void *b);

int main() {
    int n;
    Medicine medicines[100];
    printf("Enter number of medicines: ");
    scanf("%d", &n);
    
    readMedicines(medicines, n);
    qsort(medicines, n, sizeof(Medicine), compareExpiryDate);
    displayMedicines(medicines, n);
    saveToFile(medicines, n);
    return 0;
}

void readMedicines(Medicine medicines[], int n) {
    printf("Enter medicine details (ID, Name, Expiry Date, Price):\n");
    for (int i = 0; i < n; i++) {
        printf("Medicine %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &medicines[i].med_id);
        printf("Name: ");
        scanf("%s", medicines[i].name);
        printf("Expiry Date (YYYY-MM-DD): ");
        scanf("%s", medicines[i].expiry_date);
        printf("Price: ");
        scanf("%f", &medicines[i].price);
    }
}

int compareExpiryDate(const void *a, const void *b) {
    return strcmp(((Medicine*)a)->expiry_date, ((Medicine*)b)->expiry_date);
}

void displayMedicines(Medicine medicines[], int n) {
    printf("\nSorted Medicines (by Expiry Date):\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %s\n", i + 1, medicines[i].name, medicines[i].expiry_date);
    }  
}

void saveToFile(Medicine medicines[], int n) {
    FILE *file = fopen("medicine_inventory.txt", "w");
    if (file == NULL) {
        printf("Error saving the file\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d, %s, %s, ₹%.2f\n", medicines[i].med_id, medicines[i].name, medicines[i].expiry_date, medicines[i].price);
    }
    printf("\nRecords saved in""medicine_inventory.txt""\n");
}
