#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,q;
    cin>>n>>q;

    ll arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    ll prefarr[n]={0};
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        prefarr[i]+=sum;
    }

    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        ll pref=prefarr[a-2];
        if(a==1) pref=0;
        cout<<prefarr[b-1]-pref<<"\n";
    }
    return 0;
}