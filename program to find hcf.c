#include <stdio.h>

int main()
{
    int x , y , i , HCF;
    printf("enter two numbers to find their HCF");
    scanf("%d""%d" , &x ,&y);
    
    for(i = 1 ; i <= x || i <= y ; i++){
        if(x % i == 0 && y % i == 0)
        HCF = i;
    }
    printf("the HCF is %d" , HCF);


    return 0;
}

