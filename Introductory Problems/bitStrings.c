#include <stdio.h>

long long int power2(long long int a, long long int b)
{
    long long int m=1000000007;
    long long int ans=1;
    if(b==0)
    {
        return 1;
    }
    else if(b==1)
    {
        return a;
    }

    if(b%2==0)
    {
        ans=(power2(a,b/2)%m)*(power2(a,b/2)%m);
    }
    else
    {
        ans=(power2(a,b/2)%m)*(power2(a,b/2)%m)*a;
    }
    return ans;
}

int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int ans=power2(2,n);
    printf("%lld",ans%1000000007);
    return 0;
}