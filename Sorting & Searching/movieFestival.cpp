#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2000000000
#define mod 1000000007
#define FOR(i,n) for(ll i=0;i<n;i++)

bool comp(const pair<int, int>& a,const pair<int, int>& b)
{
    return a.second < b.second;
}

// sort the movie on the basis of their end time, so that we have extra time to watch the left over movies

int main()
{
    ll n;
    cin>>n;

    vector<pair<ll,ll>> mov;
    FOR(i,n)
    {
        ll start, end;
        cin>>start>>end;

        mov.push_back({start,end});
    }

    sort(mov.begin(),mov.end(),comp);

    ll end=mov[0].second;
    ll watch=1;
    for(ll i=1;i<n;i++)
    {
        if(mov[i].first>=end)
        {
            end=mov[i].second;
            watch++;
        }
    }
    cout<<watch;
    return 0;
}