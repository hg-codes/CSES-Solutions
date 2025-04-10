#include <stdio.h>

int main()
{
    long long int n;
    scanf("%lld",&n);

    for(long long int i=1;i<=n;i++)
    {
        long long int total=((i*i)*((i*i)-1))/2;
        long long int attackable=4*(i-1)*(i-2);
        printf("%lld\n",total-attackable);
    }

    // long long int total=((n*n)*((n*n)-1))/2;
    // long long int attackable=4*(n-1)*(n-2);
    // printf("%lld\n",total-attackable);
    return 0;
}