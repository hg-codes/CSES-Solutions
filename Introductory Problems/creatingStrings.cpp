#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2000000000
#define mod 1000000007
#define FOR(i,n) for(ll i=0;i<n;i++)

set<string> arrangemenets;

void permutation(string s,ll low,ll high)
{
    if(low==high)
    {
        arrangemenets.insert(s);
    }
    else
    {
        for(ll i=low;i<=high;i++)
        {
            swap(s[i],s[low]);
            permutation(s,low+1,high);
            swap(s[i],s[low]);
        }
    }
}

int main()
{
    string s;
    cin>>s;

    ll low=0;
    ll high=s.length()-1;

    permutation(s,low,high);

    cout<<arrangemenets.size()<<"\n";

    for(auto it:arrangemenets)
    {
        cout<<it<<"\n";
    }
    return 0;
}