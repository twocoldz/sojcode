#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
int v[60005];
int n,m;

int Cal(int x)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=abs(v[i]-x);
    }
    return sum;
}

int Binl(int l,int r)
{
    if(l+1==r)
    {
        return r;
    }
    int mid=(l+r)>>1;
    int ans=Cal(mid);
    if(ans==m)
    {
        return mid;
    }
    else if(ans>m)
    {
        return Binl(mid,r);
    }
    else
    {
        return Binl(l,mid);
    }
}

int Binr(int l,int r)
{
    if(l+1==r)
    {
        return l;
    }
    int mid=(l+r)>>1;
    int ans=Cal(mid);
    if(ans==m)
    {
        return mid;
    }
    else if(ans>m)
    {
        return Binr(l,mid);
    }
    else
    {
        return Binr(mid,r);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",v+i);
        }
        sort(v,v+n);
        int mi=v[0],ma=v[n-1];
        if(Cal(v[n/2])>m)
        {
            printf("0\n");
            continue;
        }
        else
        {
            int l=Cal(mi);
            int r=Cal(ma);
            if(l>m)
            {
                l=Binl(mi,v[n/2]);
            }
            else
            {
                l=mi-(m-l)/n;         //左值比mi还小
            }
            if(r>m)
            {
                r=Binr(v[n/2],ma);
            }
            else
            {
                r=ma+(m-r)/n;
            }
            printf("%d\n",r-l+1);
        }

    }
    return 0;
}
