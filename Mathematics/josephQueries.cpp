#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2000000000
#define mod 1000000007

ll joseph(ll n, ll k)
{
    if(n==1)    return 1;
    if(k<=(n+1)/2)
    {
        if(2*k>n)
        {
            return (2*k)%n;
        }
        else
        {
            return 2*k;
        }
    }
    else
    {
        ll temp=joseph(n/2,k-(n+1)/2);
        if(n%2!=0)
        {
            // odd
            return 2*temp+1;
        }
        else
        {
            // even
            return 2*temp-1;
        }
    }
}

int main()
{
    ll q;
    cin>>q;

    while(q--)
    {
        ll n,k;
        // a and b are according to 1 base indexing not zero
        cin>>n>>k;
        cout<<joseph(n,k)<<"\n";
    }
    return 0;
}