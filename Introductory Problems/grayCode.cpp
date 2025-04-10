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

    vector<string> gray;
    gray.push_back("0");
    gray.push_back("1");
    for(ll i=2;i<=n;i++)
    {
        ll len=gray.size();
        for(ll i=len-1;i>=0;i--)
        {
            gray.push_back(gray[i]);
        }
        for(ll i=0;i<len;i++)
        {
            gray[i]="0"+gray[i];
            gray[i+len]="1"+gray[len+i];
        }
    }

    for(auto it:gray)
    {
        cout<<it<<endl;
    }

    return 0;
}