#include<stdio.h>
#include<string.h>

int main(){
    int vehicleCount;
    char vehicleType[10];
    
    printf("Enter number of vehicles: ");
    scanf("%d",&vehicleCount);
    printf("Enter vehicle types: ");

    float collection = 0;
    for(int i=1;i<=vehicleCount;i++){
    scanf("%s",&vehicleType);
    if(strcmp(vehicleType, "Car") == 0){
        collection += 50;
    }else if(strcmp(vehicleType, "Truck") == 0){
        collection += 100;
    }else if(strcmp(vehicleType, "Bike") == 0){
        collection += 20;
    }
} 
    printf("Total toll collection = %.2f\n",collection);
    return 0;
}