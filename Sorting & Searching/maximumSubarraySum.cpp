#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2000000000
#define mod 1000000007
#define FOR(i,n) for(ll i=0;i<n;i++)

int main()
{
    ll n;
    cin>>n;

    ll arr[n];
    FOR(i,n)
    {
        cin>>arr[i];
    }

    ll maxsum=arr[0];
    ll sum=0;

    FOR(i,n)
    {
        sum+=arr[i];
        if(maxsum<sum)
        {
            maxsum=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    cout<<maxsum;

    return 0;
}