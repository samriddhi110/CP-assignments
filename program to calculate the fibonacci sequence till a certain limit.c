#include <stdio.h>

int main()
{
    int n, a = 0 , b = 1 ,c , i;
    printf("please define the limit of numbers to be printed for the fibonacci series:");
    scanf("%d",&n);
     for(i = 0 ; i < n ; i++){
         printf("%d\t" ,a);
         c = a + b;
         a = b;
         b = c;
         }
         

    return 0;
}

