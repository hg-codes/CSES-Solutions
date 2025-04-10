#include <stdio.h>
#define ll long long
ll m = 1e9+7;
ll m1 =1e9+6;
// fermat's little theorem used

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

ll exponent1(ll a ,ll b)
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

    ll ans=exponent1(a,b/2)%m1;
    ans=(ans*ans)%m1;
    if(b%2!=0)
    {
        ans=(ans*a)%m1;
    }
    return ans;
}

int main()
{
    ll n;
    scanf("%lld",&n);

    while(n--)
    {
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        ll exp=exponent1(b,c);
        printf("%lld\n",exponent(a,exp));
    }
    return 0;
}