#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int a[10005];
int dp[10005][102];  //前i个最多有j个没有被上黑色
int n,m;

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            sum+=a[i];
        }
        memset(dp,inf,sizeof(dp));
        a[0]=a[n+1]=0;
        for(int i=1;i<=n+1;i++)
        {
            for(int j=1;j<m&&j<=i;j++)
            {
                if(i<=m)
                {
                    dp[i][j]=min(a[i]+a[i-j],dp[i][j-1]);
                }
                else
                {
                    dp[i][j]=min(dp[i-j][m-j]+a[i],dp[i][j-1]);
                }
            }
        }
        printf("%d\n",dp[n+1][m-1]);
    }
    return 0;
}
