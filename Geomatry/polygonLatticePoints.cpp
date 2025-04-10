#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll mod(ll a)
{
    if(a<0) return -1*a;
    return a;
}

ll gcd(ll a, ll b) 
{
    while (b != 0)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll boundaryLattice(ll x1,ll y1,ll x2,ll y2)
{
    ll a=mod(x2-x1);
    ll b=mod(y2-y1);
    ll lp;
    if(a==0)    lp=b-1;
    else if(b==0)    lp=a-1;
    else    lp=gcd(a,b)-1;

    // boundaries excluded
    return lp;
}

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
    // ans=2*area; 
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
    ll Area=area(n,x,y);
    ll blp=n;   // all vertices are lattice points

    for(int i=0;i<n;i++)
    {
        ll lp=boundaryLattice(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
        blp+=lp;
    }

    // pick's theorem
    // a=I+B/2-1
    ll ilp=(Area+2-blp)/2;

    // inside lattice points and boundary lattice points 
    // ilp and blp
    cout<<ilp<<" "<<blp;
    return 0;
}