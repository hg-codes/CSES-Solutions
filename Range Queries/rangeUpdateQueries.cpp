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
    return segmentTree[ind]=buildTree(2*ind+1,l,mid)+buildTree(2*ind+2,mid+1,r);
}

ll getSum(ll ind, ll start, ll end, ll l, ll r)
{
    if(l>end || r<start)
    {
        return 0;
    }
    else if(l<=start && end<=r)
    {
        return segmentTree[ind];
    }

    ll mid= start+((end-start)>>1);
    return getSum(2*ind+1,start,mid,l,r)+getSum(2*ind+2,mid+1,end,l,r);
}

void update(ll ind, ll pos, ll l, ll r, ll value)
{
    if(l==r)
    {
        segmentTree[ind]=value;
        return;
    }
    ll mid= l+((r-l)>>1);
    if(l<=pos && pos<=mid)
    {
        update(2*ind+1,pos,l,mid,value);
    }
    else
    {
        update(2*ind+2,pos,mid+1,r,value);
    }
    segmentTree[ind]=segmentTree[2*ind+1]+segmentTree[2*ind+2];
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
        ll t,a,b,u,k;
        // a and b are according to 1 base indexing not zero
        cin>>t;
        if(t==1)
        {
            cin>>a>>b>>u;
            update(0,a-1,0,n-1,b);
        }
        else
        {
            cin>>k;
        }
    }
    return 0;
}