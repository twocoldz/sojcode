#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define inf 0x3f3f3f3f
using namespace std;

int h[100005];
int d[105],pre[105],next[105];

int main()
{
    int n,c;
    while(scanf("%d%d",&n,&c)==2)
    {
        int x;
        scanf("%d",&x);
        for(int i=1;i<=100;i++)
        {
            d[i]=i<x?inf:(x-i)*(x-i);
        }

        for(int i=1;i<n;i++)
        {
            scanf("%d",&x);
            for(int t=inf,j=100;j>=1;j--)
            {
                t=min(t,d[j]+j*c);
                pre[j]=t;
            }
            for(int t=inf,j=1;j<=100;j++)
            {
                t=min(t,d[j]-j*c);
                next[j]=t;
                d[j]=inf;
            }
            for(int j=x;j<=100;j++)
            {
                d[j]=(j-x)*(j-x)+min(pre[j]-j*c,next[j]+j*c);
            }
        }
        int ans=inf;
        for(int i=1;i<=100;i++)
        {
            ans=min(ans,d[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}


/*int main()
{
    int n,c;
    while(scanf("%d%d",&n,&c)==2)
    {
        int ans=inf;
        int maxh=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",h+i);
            maxh=max(maxh,h[i]);
        }
        pre[0]=next[maxh+1]=inf;

        for(int i=1;i<=maxh;i++)
        {
            pre[i]=-c*i;
            next[i]=c*i;
        }
        int r=0;
        for(int i=1;i<=n;i++)
        {
            r^=1;
            for(int j=h[i];j<=maxh;j++)
            {
                dp[r][j]=min(pre[j]+c*j,next[j]-c*j)+(h[i]-j)*(h[i]-j);
            }
            for(int j=1;j<h[i];j++)
            {
                pre[j]=inf;
            }
            for(int j=h[i];j<=maxh;j++)
            {
                pre[j]=min(pre[j-1],dp[r][j]-c*j);
            }
            for(int j=maxh;j>=h[i];j--)
            {
                next[j]=min(next[j+1],dp[r][j]+c*j);
            }
            for(int j=1;j<h[i];j++)
            {
                next[j]=next[h[i]];
            }
        }
        for(int i=h[n];i<=maxh;i++)
        {
            ans=min(ans,dp[r][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}*/
