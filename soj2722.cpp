#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int v[2005];
int dp[2005][2005];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",v+i);
        }
        memset(dp,0,sizeof(dp));
        for(int i=n;i>=1;i--)
        {
            //printf("i=%d\n",i);
            dp[i][i]=v[i]*n;
            //printf("dp[i][i]=%d\n",dp[i][i]);
            for(int j=i+1;j<=n;j++)
            {
                dp[i][j]=max(dp[i][j-1]+v[j]*(n-j+i),dp[i+1][j]+v[i]*(n-j+i));
                //printf("dp[i][j]=%d\n",dp[i][j]);
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
