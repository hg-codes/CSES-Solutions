#include <bits/stdc++.h>
using namespace std;
#define ll long long

void heapify(ll* arr, ll n, ll i)
{
    ll largest = i; 
    ll l = 2 * i + 1; 
    ll r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        ll temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(ll* arr, ll n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        ll temp = arr[0]; 
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    ll n,S;
    cin>>n>>S;

    ll arr[n],refarr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        refarr[i]=arr[i];
    }

    heapSort(refarr, n);
    
    ll x=0,y=0;
    bool flag=false;
    ll l=0,r=n-1;
    while(l<r)
    {
        if(refarr[l]+refarr[r]==S)
        {
            x=refarr[l];
            y=refarr[r];
            flag=true;
            break;
        }
        else if(refarr[l]+refarr[r]<S)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    ll ans1,ans2;
    if(flag)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]==x)
            {
                ans1=i+1;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]==y)
            {
                ans2=i+1;
                break;
            }
        }
        cout<<ans1<<" "<<ans2;
    }
    else
    {
        cout<<"IMPOSSIBLE";
    }
    
    return 0;
}