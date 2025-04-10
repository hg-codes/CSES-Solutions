#include <bits/stdc++.h>
#define ll long long

ll countDivisors(ll n)
{
    ll count = 1;
    ll exp = 0;

    while (n % 2 == 0)
    {
        n /= 2;
        exp++;
    }
    count *= (exp + 1);

    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        exp = 0;
        while (n % i == 0)
        {
            n /= i;
            exp++;
        }
        count *= (exp + 1);
    }

    if (n > 2)
    {
        count *= (1 + 1);
    }

    return count;
}

int main()
{
    ll n;
    scanf("%lld",&n);

    while(n--)
    {
        ll x;
        scanf("%lld",&x);
        ll ans=countDivisors(x);
        printf("%lld\n",ans);
    }
    return 0;
}