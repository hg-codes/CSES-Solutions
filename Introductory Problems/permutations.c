#include <stdio.h>

int main()
{
    long long int n;
    scanf("%lld",&n);

    if(n==2||n==3)
    {
        printf("NO SOLUTION");
        return 0;
    }
    
    for(long long int i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            printf("%lld ",i);
        }
    }

    for(long long int i=0;i<=n;i++)
    {
        if(i%2!=0)
        {
            printf("%lld ",i);
        }
    }
    return 0;
}