#include<stdio.h>

int main(){
    int N;
    float weight;
    printf("Enter number of products: ");
    scanf("%d",&N);
    printf("Enter weights (in grams): ");

    int accepetedcount = 0;
    int rejectedcount = 0;
    for(int i=1;i<=N;i++){
    scanf("%f",&weight);
    if(weight>=950 && weight<=1050){
        accepetedcount++;
    }
    else{
        rejectedcount++;
    }
    }
    printf("Accepted Product = %d\n",accepetedcount);
    printf("Rejected Product = %d\n",rejectedcount);
    return 0;
}