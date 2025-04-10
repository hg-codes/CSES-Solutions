#include <stdio.h>

int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int s=n*(n+1)/2;
    long long int s1=0;
    long long int arr[n];
    for(int i=0;i<n-1;i++)
    {
        scanf("%lld",&arr[i]);
        s1+=arr[i];
    }
    printf("%lld",s-s1);
    return 0;
}