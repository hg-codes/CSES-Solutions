#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2000000000
#define mod 1000000007

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

    for (ll i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (ll i = n - 1; i > 0; i--)
    {
        ll temp = arr[0]; 
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    ll n,x;
    cin>>n>>x;

    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    heapSort(arr,n);

    ll l=0,r=n-1;
    ll gondola=0;
    
    while(l<r)
    {
        if(arr[l]+arr[r]<=x)
        {
            l++;
            r--;
            gondola++;

        }   
        else
        {
            r--;
            gondola++;
        }
    }
    if(l==r)
    {
        cout<<gondola+1;
    }
    else
    {
        cout<<gondola;
    }
    return 0;
}