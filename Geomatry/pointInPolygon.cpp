#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 2000000000

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

bool intersect(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3,ll x4,ll y4)
{
    ll a1=location(x1,y1,x2,y2,x3,y3);
    ll a2=location(x1,y1,x2,y2,x4,y4);
    ll a3=location(x3,y3,x4,y4,x1,y1);
    ll a4=location(x3,y3,x4,y4,x2,y2);

    if(a1!=a2 && a3!=a4)    return true;
    else if(a1==0 && a2==0)
    {
        if((min(x1,x2)<=x3 && x3<=max(x1,x2) && min(y1,y2)<=y3 && y3<=max(y1,y2)) || (min(x1,x2)<=x4 && x4<=max(x1,x2) && min(y1,y2)<=y4 && y4<=max(y1,y2))) return true;
        if((min(x3,x4)<=x1 && x1<=max(x3,x4) && min(y3,y4)<=y1 && y1<=max(y3,y4)) || (min(x3,x4)<=x2 && x2<=max(x3,x4) && min(y3,y4)<=y2 && y2<=max(y4,y3))) return true;
    }
    return false;
}

bool onLine(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3)
{
    if(location(x1,y1,x2,y2,x3,y3)==0)
    {
        if(min(x1,x2)<=x3 && x3<=max(x1,x2) && min(y1,y2)<=y3 && y3<=max(y1,y2))    return true;
    }
    return false;
}

int main()
{
    ll v,p;
    cin>>v>>p;

    ll x[v],y[v];
    for(ll i=0;i<v;i++)
    {
        cin>>x[i]>>y[i];
    }

    while(p--)
    {
        ll px,py;
        cin>>px>>py;

        ll countInt=0;
        ll flag=1;
        for(int i=0;i<v;i++)
        {
            if(onLine(x[i],y[i],x[(i+1)%v],y[(i+1)%v],px,py))
            {
                cout<<"BOUNDARY\n";
                flag=0;
                break;
            }
            if(intersect(x[i],y[i],x[(i+1)%v],y[(i+1)%v],px,py,INF,INF+2))
            {
                countInt++;
            }
        }
        if(flag)
        {
            if(countInt%2)  cout<<"INSIDE\n";   // odd
            else    cout<<"OUTSIDE\n";           // even
        }
    }

    return 0;
}