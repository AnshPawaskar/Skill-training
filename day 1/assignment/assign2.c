#include<stdio.h>
void main(){
    int N;
    printf("Enter the number of integers:");
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
        printf("*");
        }
        printf("\n");
    }
}
