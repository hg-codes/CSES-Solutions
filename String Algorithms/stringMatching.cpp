#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main()
{
    bool flag=true;
    string str,refstr;
    cin>>str>>refstr;

    ll n=str.size();
    ll k=refstr.size();
    ll count=0;

    for(ll i=0;i<n-1;i++)
    {
        if(str[i]!=str[i+1])
        {
            flag=false;
        }
    }

    for(ll i=0;i<k-1;i++)
    {
        if(refstr[i]!=refstr[i+1])
        {
            flag=false;
        }
    }

    if(flag && n!=1)
    {
        cout<<n-k+1;
        return 0;
    }

    for(ll i=0;i<=n-k;i++)
    {       
        if(str[i]==refstr[0] && str[i+k-1]==refstr[k-1])
        {
            if(str.substr(i,k)==refstr)
            {
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}