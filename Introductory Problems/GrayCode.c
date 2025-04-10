#include <stdio.h>
#define ll long long

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
    ll n;
    scanf("%lld",&n);

    ll arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        printf("%lld",arr[i]);
    }
    printf("\n");

    for(int i=power2(2,n);i>1;i--)
    {   
        for(int j=n-1;j>=0;j--)
        {   
            if(i%power2(2,j)==1 || j==0)
            {
                arr[j]^=1;
            }
            printf("%lld",arr[j]);
        }
        printf("\n");
    }
    return 0;
}