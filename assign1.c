#include<stdio.h>

void main(){
    int choice;
    printf("Enter the order status(1-4):\n");
    printf("1.Order Placed\n");
    printf("2.Preparing Food\n");
    printf("3.Out for Delivery\n");
    printf("4.Delivered\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1: printf("Your order has been placed.\n");
                break;
        case 2: printf("Your food is being prepared.\n");
                break;
        case 3: printf("Your food is out for delivery.\n");
                break;
        case 4: printf("Your order has been delivered. Enjoy your meal!\n");
                break;
        default: printf("Invalid status. Please enter a number between 1 and 4.\n");
                 break;
    }
}