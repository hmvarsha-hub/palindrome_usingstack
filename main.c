#include <stdio.h>
#include <stdlib.h>
gcd(int a,int b)
{
     if (a==b)
        return a;
     else if(a>b)
     {
         return gcd(a-b,b);
     }
     else {
        return gcd(b,a);
     }
}
int main()
{
    int a,b;
    printf("\n read values for a &b:");
    scanf("%d%d",&a,&b);
    printf("\n gcd of %d and %d is %d\n",a,b,gcd(a,b));
    return 0;
}
