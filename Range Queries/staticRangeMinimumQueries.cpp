#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2000000000

const int N = 200001;
ll arr[N];
ll segmentTree[4*N];

ll buildTree(ll ind, ll l, ll r)
{
    // base case
    if(l==r)
    {
        return segmentTree[ind]=arr[l];
    }

    ll mid= l+((r-l)>>1);
    return segmentTree[ind]=min(buildTree(2*ind+1,l,mid),buildTree(2*ind+2,mid+1,r));
}

ll getMin(ll ind, ll start, ll end, ll l, ll r)
{
    if(l>end || r<start)
    {
        return INF;
    }
    else if(l<=start && end<=r)
    {
        return segmentTree[ind];
    }

    ll mid= start+((end-start)>>1);
    return min(getMin(2*ind+1,start,mid,l,r),getMin(2*ind+2,mid+1,end,l,r));
}

int main()
{
    ll n,q;
    cin>>n>>q;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    buildTree(0,0,n-1);

    while(q--)
    {
        ll a,b;
        // a and b are according to 1 base indexing not zero
        cin>>a>>b;
        cout<<getMin(0,0,n-1,a-1,b-1)<<"\n";
    }
    return 0;
}