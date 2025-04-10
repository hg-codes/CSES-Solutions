#include <stdio.h>

int main()
{
    long long int t;
    long long int x;
    long long int y;
    scanf("%lld",&t);
    // y rows and x columns
    long long int num=0;

    while(t--)
    {
        scanf("%lld %lld",&y ,&x);
        if(x==y)
        {
            num=x*x-(x-1);
            printf("%lld\n",num);
        }
        else if(y>x)
        {
            if(y%2==0)
            {
                num=y*y;
                num=num-(x-1);
            }
            else
            {
                num=(y-1)*(y-1)+1;
                num=num+(x-1);
            }
            printf("%lld\n",num);
        }
        else
        {
            if(x%2!=0)
            {
                num=x*x;
                num=num-(y-1);
            }
            else
            {
                num=(x-1)*(x-1)+1;
                num=num+(y-1);
            }
            printf("%lld\n",num);
        }
    }

    return 0;
}