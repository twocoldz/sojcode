#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int h[105],dp[105][105],ma[105][105];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)
        {
            break;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",h+i);
        }
        for(int i=1;i<=n;i++)
        {
            ma[i][i]=h[i];
            for(int j=i+1;j<=n;j++)
            {
                ma[i][j]=max(ma[i][j-1],h[j]);
            }
        }
        dp[1][1]=h[1];
        for(int i=2;i<=n;i++)
        {
            dp[i][1]=max(dp[i-1][1],h[i]);
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=i&&j<=m;j++)
            {
                dp[i][j]=0x3f3f3f3f;
                for(int k=i-1;k>=j-1;k--)
                {
                    dp[i][j]=min(dp[i][j],dp[k][j-1]+ma[k+1][i]);
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
