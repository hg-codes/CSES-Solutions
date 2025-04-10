#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll location(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3)
{
    // -1 ->    anticlockwise/left 
    // 1 ->     clockwise/right
   // 0 ->      collinear 
   ll exp = (x3-x2)*(y2-y1)-(y3-y2)*(x2-x1);
   
   if(exp>0)    return 1;
   else if(exp<0)   return -1;
   else     return 0;
}

int main()
{
    ll n;
    cin>>n;

    while(n--)
    {
        ll x[3],y[3];
        for(int i=0;i<3;i++)
        {
            cin>>x[i]>>y[i];
        }
        ll loc=location(x[0],y[0],x[1],y[1],x[2],y[2]);
        if(loc>0)   cout<<"RIGHT\n";
        else if(loc<0)   cout<<"LEFT\n";
        else   cout<<"TOUCH\n";
    }

    return 0;
}