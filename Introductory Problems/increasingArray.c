#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n;
    scanf("%lld",&n);

    long long int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    long long int d=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            d+=arr[i]-arr[i+1];
            // printf("%lld\n",d);
            arr[i+1]=arr[i];
            // for(int i=0;i<n;i++)
            // {
            //     printf("%lld ",arr[i]);
            // }
            // printf("\n");
            // printf("\n");
        }
    }
    printf("%lld",d);
    return 0;
}