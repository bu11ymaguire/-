#include<stdio.h>

void factorial (int n, int *a)
{
    if(n==1){
        printf("1 = %d\n", *a);
        return;
    }
    *a = *a * n;
    printf("%d * ",n);
    factorial(n-1, a);
}

int main()
{
    int input;
    printf("User Input: ");
    scanf("%d",&input);
    int result = 1;
    factorial(input,&result);

    return 0;
}
