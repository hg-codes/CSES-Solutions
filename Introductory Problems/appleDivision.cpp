#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2000000000
#define mod 1000000007
#define FOR(i,n) for(ll i=0;i<n;i++)
ll mini=INF;

void appleDivide(ll i,ll n,ll sum1,ll sum2,vector<ll>& v)
{
    if(i==n)
    {
        mini=min(mini,abs(sum1-sum2));
        // cout<<"sum1"<<sum1<<" sum2"<<sum2<<endl;
        return;
    }
    else
    {
        appleDivide(i+1,n,sum1+v[i],sum2,v);
        appleDivide(i+1,n,sum1,sum2+v[i],v);
    }
}

int main()
{
    ll n;
    cin>>n;

    vector<ll> v(n);
    FOR(i,n)
    {
        cin>>v[i];
    }
    appleDivide(0,n,0,0,v);
    cout<<mini;
    return 0;
}