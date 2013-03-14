#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;

int a[105];
int dp[105][105]; //dp[i][j]表示在前i个中选取j个最小的误差值
int d[105][105]; //选取两端值为i，j产生的误差

int main()
{
    int n,e;
    while(scanf("%d%d",&n,&e)==2)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                d[i][j]=0;
                for(int k=i+1;k<j;k++)
                {
                    d[i][j]+=abs(a[k]+a[k]-a[i]-a[j]);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            d[0][i]=0;
            for(int j=1;j<i;j++)
            {
                d[0][i]+=abs(a[i]-a[j])*2;
            }
        }
        for(int i=1;i<=n;i++)
        {
            d[i][n+1]=0;
            for(int j=i;j<=n;j++)
            {
                d[i][n+1]+=abs(a[i]-a[j])*2;
            }
        }
        //memset(dp,inf,sizeof(dp));
         int ans=n+1,dif=e;
         for(int i=1;i<=n;i++)
         {
             dp[i][1]=d[0][i];
             if(dp[i][1]+d[i][n+1]<dif)
             {
                 ans=1;
                 dif=dp[i][1]+d[i][n+1];
             }
         }
         for(int j=2;j<=n;j++)
         {
             for(int i=j;i<=n;i++)
             {
                 dp[i][j]=dp[j-1][j-1]+d[j-1][i];
                 for(int k=j;k<i;k++)
                     dp[i][j]=min(dp[i][j],dp[k][j-1]+d[k][i]);
                 if(j<=ans&&dp[i][j]+d[i][n+1]<dif)
                 {
                     ans=j;
                     dif=dp[i][j]+d[i][n+1];
                 }
             }
         }
         printf("%d %d\n",ans,dif);
    }
    return 0;
}
