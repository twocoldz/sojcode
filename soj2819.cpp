#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

#define inf 10000000.0

using namespace std;
int w[10],b[10];
double d[10][10];
double dp[1<<10];
//int res[1<<10];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2&&n)
    {
        double t;
        for(int i=0;i<n;i++)
        {
            scanf("%d",w+i);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",b+i);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%lf",&t);
                d[i][j]=1.0-t;
            }
        }



        printf("%d\n",ans);
    }
    return 0;
}

/*
memset(res,0,sizeof(res));
        for(int i=0;i<(1<<n);i++)
         {
             for(int j=0;j<n;j++)
                 if((1<<j)&i)
                     res[i]+=b[j];
         }
         for(int i=1;i<1024;i++)
         {
             dp[i]=inf;
         }
         dp[0]=0;
        int ans=0;
        for(int i=0;i<(1<<n);i++)
         {
             for(int j=0;j<n;j++)
             {
                 if(!((1<<j)&i))
                 {
                     int k=i^(1<<j);
                     double ww=1.0;
                     for(int jj=0;jj<n;jj++)
                     {
                         if(i & (1<<jj))
                         {
                             ww*=d[jj][j];
                         }
                     }
                     ww*=w[j];
                     dp[k]=min(dp[k],dp[i]+ww);
                     if(dp[k]<=m)
                         ans=max(ans,res[k]);
                 }
             }
         }
*/
