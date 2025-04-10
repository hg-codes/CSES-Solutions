#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;

// matrix used
// 1 1 
// 1 0

ll** matrixMult(ll** a,ll** b,ll rA,ll cA,ll cB)
{
    ll** ans= new ll*[rA];
    for(ll i=0;i<rA;i++)
    {
        ans[i] = new ll[cB]();
        // ans[i] = new ll[cB];    this will not initialise every element to be zero
    }

    for(ll i=0;i<rA;i++)
    {
        for(ll j=0;j<cB;j++)
        {
            for(int k=0;k<cA;k++)
            {
                ans[i][j]+=(a[i][k]*b[k][j])%mod;
            }
        }
    }
    return ans;
}

ll** matrixExp(ll** a,ll r,ll n)
{
    // for sq matrix only
    if(n==0)
    {
        ll** ans= new ll*[r];
        for(ll i=0;i<r;i++)
        {
            ans[i] = new ll[r];
        }
        for(ll i=0;i<r;i++)
        {
            for(ll j=0;j<r;j++)
            {
                ans[i][j]=1;
            }
        }
        return  ans;
    }
    if(n==1)
    {
        return a;
    }
    else
    {
        if(n%2) // odd
        {   
            return matrixMult(matrixMult(matrixExp(a,2,n/2),matrixExp(a,2,n/2),2,2,2),a,2,2,2);
        }
        else    // even
        {   
            return matrixMult(matrixExp(a,2,n/2),matrixExp(a,2,n/2),2,2,2);
        }
    }
}

void printMatrix(ll** matrix, ll rows, ll cols) {
    for (ll i = 0; i < rows; ++i) {
        for (ll j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ll n;
    cin>>n;

    if(n==0)
    {
        cout<<0;
        return 0;
    }
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    if(n==2)
    {
        cout<<1;
        return 0;
    }

    ll** arr = new ll*[2];
    for (ll i = 0; i < 2; ++i)
    {
        arr[i] = new ll[2];
    }

    arr[0][0]=1;
    arr[0][1]=1;
    arr[1][0]=1;
    arr[1][1]=0;
    ll** ansarr=matrixExp(arr,2,n-2);
    ll ans=(ansarr[0][0]+ansarr[0][1])%mod;
    cout<<ans;

    return 0;
}
