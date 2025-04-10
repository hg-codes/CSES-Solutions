#include <stdio.h>
#define ll long long
ll m = 1e9+7;

ll exponent(ll a ,ll b)
{
    if(a==0 && b==0)
    {
        return 1;
    }
    else if(b==0)
    {
        return 1;
    }
    else if(b==1)
    {
        return a;
    }

    ll ans=exponent(a,b/2)%m;
    ans=(ans*ans)%m;
    if(b%2!=0)
    {
        ans=(ans*a)%m;
    }
    return ans;
}

int main()
{
    ll n;
    scanf("%lld",&n);

    while(n--)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",exponent(a,b));
    }
    return 0;
}