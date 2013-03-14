#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int c,n;
int m[1002][1002];
int dp[1002][1002];

inline int min3(int a,int b,int c)
{
    return min(min(a,b),c);
}

int main()
{
    while(scanf("%d%d",&c,&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                scanf("%d",m[i]+j);
            }
        }
        memset(dp,inf,sizeof(dp));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++)
        {
            dp[1][i]=dp[1][0]+m[1][i]+c;
        }
        int ans=dp[1][n];
        for(int i=2;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                dp[i][j]=min3(dp[i-1][i-1]+m[i][j]+c,dp[i-1][j],dp[i-1][j-1]+m[j][j]+c);
                //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
            }
            if(dp[i][n]<ans)
                ans=dp[i][n];
        }
        printf("%d\n",ans);
    }
    return 0;
}
