#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m=1e9+7;

ll diceCombinations(ll n)
{
    ll arr[n+1]={0};
    arr[0]=1;

    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(i-j-1>=0)
            {
                arr[i]=(arr[i]+arr[i-j-1])%m;
            }
        }
    }
    // for(int i=0;i<n+1;i++)
    // {
    //     cout<<arr[i]<<"\n";
    // }
    return arr[n];
}

int main()
{
    ll n;
    cin>>n;
    ll ans=diceCombinations(n);
    cout<<ans;
    return 0;
}