#include<stdio.h>

float calculateBill(float amount){
    float discount = 0;
    if(amount >= 500 && amount <= 1000){
        discount =  0.1; 
    }
    else if(amount > 1000){
        discount =  0.2;  
    }
    return amount * (1-discount);
}

int main(){
    float final_amount, amount;
    printf("Enter total bill amount: ");
    scanf("%f", &amount);
    final_amount = calculateBill(amount);
    printf("Final Payable Amount: %.2f\n", final_amount);
    return 0;
}
