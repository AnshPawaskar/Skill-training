#include <stdio.h>
#include <string.h>

struct Car_t {
    int car_id;
    char model[100];
    union {
        int rent_per_day;  
    } rent;
};

typedef struct Car_t Car;

void readCars(Car cars[], int n);
void saveToFile(Car cars[], int n);
void displayCars(Car cars[], int n);
void updateCarRent(Car cars[], int n);
void updateCarRentInfo(Car *car);

int main() {
    int n;
    Car cars[100];

    printf("Enter number of cars: ");
    scanf("%d", &n);
    readCars(cars, n);
    displayCars(cars, n);
    saveToFile(cars, n);
    char choice;
    printf("\nDo you want to update rental information? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        updateCarRent(cars, n);
        saveToFile(cars, n);
    }

    return 0;
}

void readCars(Car cars[], int n) {
    printf("Enter car details (Car ID, Model, Rent Per Day):\n");
    for (int i = 0; i < n; i++) {
        printf("Car %d:\n", i + 1);
        printf("Car ID: ");
        scanf("%d", &cars[i].car_id);
        printf("Model: ");
        scanf("%s", cars[i].model);
        
        printf("Enter Rent per day: ");
        scanf("%d", &cars[i].rent.rent_per_day);
    }
}

void displayCars(Car cars[], int n) {
    printf("\nCars Available:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - ₹%d/day\n", i + 1, cars[i].model, cars[i].rent.rent_per_day);
    }
}

void saveToFile(Car cars[], int n) {
    FILE *file = fopen("car_rentals.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d, %s, ₹%d/day\n", cars[i].car_id, cars[i].model, cars[i].rent.rent_per_day);
    }
    printf("\nData saved in \"car_rentals.txt\"\n");
}

void updateCarRent(Car cars[], int n) {
    int car_id;
    printf("\nEnter the Car ID to update rent information: ");
    scanf("%d", &car_id);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (cars[i].car_id == car_id) {
            found = 1;
            printf("Updating details for Car ID: %d\n", car_id);
            updateCarRentInfo(&cars[i]);
            break;
        }
    }
    if (!found) {
        printf("Car ID not found!\n");
    }
}

void updateCarRentInfo(Car *car) {
    printf("Current Rent per day: ₹%d/day\n", car->rent.rent_per_day);

    printf("Enter new Rent per day: ₹");
    scanf("%d", &car->rent.rent_per_day);
}
