#include <stdio.h>

void HanoiTower(long long int n,long long int a,long long int b)
{
    if(n==1)
    {
        printf("%lld %lld\n",a,b);
        return;
    }

    long long int other=6-(a+b);
    HanoiTower(n-1,a,other);
    printf("%lld %lld\n",a,b);
    HanoiTower(n-1,other,b);
    return;
}

long long int power2(long long int a, long long int b)
{
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
        ans=power2(a,b/2)*power2(a,b/2);
    }
    else
    {
        ans=power2(a,b/2)*power2(a,b/2)*a;
    }
    return ans;
}

int main()
{
    long long int n;
    scanf("%lld",&n);

    printf("%lld\n",power2(2,n)-1);
    HanoiTower(n,1,3);

    return 0;
}