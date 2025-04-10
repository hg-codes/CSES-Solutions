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
    ll n,m,k;
    cin>>n>>m>>k;

    ll a[n],p[m];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<m;i++)
    {
        cin>>p[i];
    }

    heapSort(a, n);
    heapSort(p, m);

    ll aptr=0,pptr=0;
    ll alloted=0;

    while(aptr<n && pptr<m)
    {
        if(a[aptr]<p[pptr]-k)
        {
            aptr++;
        }
        else if(a[aptr]>=p[pptr]-k && a[aptr]<=p[pptr]+k)
        {
            alloted++;
            aptr++;
            pptr++;
        }
        else
        {
            pptr++;
        }
    }
    cout<<alloted;
    return 0;
}