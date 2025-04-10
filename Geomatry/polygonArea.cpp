#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll area(ll n, ll x[], ll y[])
{
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ll j=(i+1)%n;
        ans+=x[i]*y[j];
        ans-=y[i]*x[j];
    }
    if(ans<0)
    {
        ans*=-1;
    }
    return ans;
}

int main()
{
    ll n;
    cin>>n;

    ll x[n],y[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }

    cout<<area(n,x,y);
    return 0;
}