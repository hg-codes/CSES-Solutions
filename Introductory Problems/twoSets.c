#include <stdio.h>

int main()
{   
    long long int n;
    scanf("%lld",&n);
    long long int arr[n+1];
    for(long long int i =1;i<=n;i++)
    {
        arr[i]=i;
    }

    if(n%4==0 || (n+1)%4==0)
    {
        printf("YES\n");
        
        if(n%2==0)
        {
            printf("%lld\n",n/2);
            for(long long int i =1;i<=n/4;i++)
            {
                printf("%lld ",arr[i]);
            }
            for(long long int i =n-n/4+1;i<=n;i++)
            {
                printf("%lld ",arr[i]);
            }
            printf("\n");

            printf("%lld\n",n/2);
            for(long long int i =n/4+1;i<=n-n/4;i++)
            {
                printf("%lld ",arr[i]);
            }
        }
        else
        {
            printf("%lld\n",(n-1)/2);
            for(long long int i =1;i<=n/4;i++)
            {
                printf("%lld ",arr[i]);
            }
            for(long long int i =n-n/4;i<=n;i++)
            {
                printf("%lld ",arr[i]);
            }
            printf("\n");

            printf("%lld\n",(n+1)/2);
            for(long long int i =n/4+1;i<=n-n/4-1;i++)
            {
                printf("%lld ",arr[i]);
            }
        }
    }
    else
    {
        printf("NO");
    }
    return 0;
}