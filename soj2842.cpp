#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int dp[(1<<20)+5][21];  //dp[i][j]表示状态为i时最后一个为j的最小花费
int c[21][21];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",c[i]+j);
            }
        }
        n--;
        memset(dp,inf,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[1<<i][i]=c[i][n];
        }
        for(int i=1;i<(1<<n);i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    for(int k=0;k<n;k++)
                    {
                        if(!(i&(1<<k)))
                        {
                            int t=i^(1<<k);
                            dp[t][k]=min(dp[i][j]+c[j][k],dp[t][k]);
                            //printf("dp[%d][%d]=%d\n",t,k,dp[t][k]);
                        }
                    }
                }
            }
        }
        int ans=inf;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,dp[(1<<n)-1][i]+c[i][n]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
