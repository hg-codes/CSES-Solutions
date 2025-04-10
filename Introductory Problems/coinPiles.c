#include <stdio.h>
#include <math.h>
#define ll long long

int main()
{
    ll t;
    scanf("%lld",&t);

    while(t--)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);

        // a=2x+y && b=x+2y
        // x and y should be positive integer for this to be follow

        // use double according to constraints
        double x=(2*a-b)/3.0;
        double y=(2*b-a)/3.0;

        if(floor(x)==x && floor(y)==y && x>=0 && y>=0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}