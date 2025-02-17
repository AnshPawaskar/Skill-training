#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    long long card;
    char upiID[50];
    int bankChoice;
    
    printf("Select Payment Method (1-3):\n");
    printf("1. Credit/Debit Card\n");
    printf("2. UPI\n");
    printf("3. Net Banking\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter 16-digit Card Number: ");
        scanf("%lld", &card);
        if (card >= 1000000000000000 && card <= 9999999999999999){
            printf("Payment Successful!\n");
        }
        else {
            printf("Transaction Failed. Please try again.\n");
        }
    }

    else if (choice == 2) {
        printf("Enter your UPI ID (e.g., user@upi): ");
        scanf("%s", upiID);
        if (strchr(upiID, '@') != NULL) {
            printf("Payment Successful!\n");
        } else {
            printf("Transaction Failed. Please try again.\n");
        }
    }
    else if (choice == 3) {
        printf("Select Bank:\n");
        printf("1. SBI\n");
        printf("2. HDFC\n");
        printf("Enter bank choice (1-2): ");
        scanf("%d", &bankChoice);
      
        if (bankChoice == 1 || bankChoice == 2) {
            printf("Payment Successful!\n");
        } else {
            printf("Transaction Failed. Please try again.\n");
        }
    }
    else {
        printf("Invalid payment method. Please try again.\n");
    }
    return 0;
}
