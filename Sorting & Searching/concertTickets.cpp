#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2000000000
#define mod 1000000007
#define FOR(i,n) for(ll i=0;i<n;i++)

int main()
{
    ll n,m;
    cin>>n>>m;

    multiset<ll,greater<ll>> tickets;
    
    FOR(i,n)
    {
        ll a;
        cin>>a;
        tickets.insert(a);
    }

    while(m--)
    {
        ll maxprice;
        cin>>maxprice;

        auto it=tickets.lower_bound(maxprice);
        if(it==tickets.end())
        {
            cout<<"-1\n";
        }
        else
        {   
            cout<<*it<<"\n";
            tickets.erase(tickets.find(*it));
        }
    }
    return 0;
}