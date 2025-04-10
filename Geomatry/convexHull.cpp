#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll ConvexHull()
{
    
    return chp;
}

int main()
{
    ll n;
    cin>>n;

    ll x[n],y[n],chpx[n],chpy[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }

    ll chp=ConvexHull();
    cout<<chp<<"\n";
    for(int i=0;i<chp;i++)
    {
        cout<<chpx[i]<<" "<<chpy[i]<<"\n";
    }

    return 0;
}