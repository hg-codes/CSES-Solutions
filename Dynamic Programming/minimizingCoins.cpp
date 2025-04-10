#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2000000000
#define mod 1000000007
#define FOR(i,n) for(ll i=0;i<n;i++)

int main()
{
    ll n,x;
    cin>>n>>x;

    ll arr[n];
    FOR(i,n)
    {
        cin>>arr[i];
    }

    vector<ll> coins_dp(x+1,INF);
    coins_dp[0]=0;

    for(ll i=1;i<=x;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(arr[j]<=i)
            {
                coins_dp[i]=min(coins_dp[i],coins_dp[i-arr[j]]+1);
            }
        }
    }

    if(coins_dp[x]<INF)
    {
        cout<<coins_dp[x];
    }
    else
    {
        cout<<-1;
    }
    return 0;
}