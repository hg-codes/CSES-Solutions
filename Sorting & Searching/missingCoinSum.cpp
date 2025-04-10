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
    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    heapSort(arr, n);
    
    if(arr[0]!=1)
    {
        cout<<1;
        return 0;
    }

    ll prefarr[n]={0};
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        prefarr[i]+=sum;
    }

    ll flag=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==arr[i+1] || prefarr[i]+1>=arr[i+1])
        {
            continue;
        }
        if(arr[i]+1!=arr[i+1])
        {
            flag=i;
            break;
        }
    }
    
    if(flag==0)  flag=n-1;
    cout<<prefarr[flag]+1;
    return 0;
}