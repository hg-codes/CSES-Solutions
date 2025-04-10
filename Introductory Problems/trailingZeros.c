#include <stdio.h>

long long int power(long long int a, long long int b)
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
        ans=(power(a,b/2)%m)*(power(a,b/2)%m);
    }
    else
    {
        ans=(power(a,b/2)%m)*(power(a,b/2)%m)*a;
    }
    return ans;
}

int main()
{
    long long int n;
    scanf("%lld",&n);

    long long int ans=0;
    for(int k=1;k<15;k++)
    {
        ans+=n/(power(5,k));
        if(n/(power(5,k))==0)
        {
            break;
        }
    }
    printf("%lld",ans);
    return 0;
}