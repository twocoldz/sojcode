#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define inf 0x3f3f3f3f

using namespace std;


int dp[2][1505],a[1505];

int main()
{
    int n,s;
    while(scanf("%d%d",&n,&s)==2)
    {
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        int k=(s-1)/(n-1);
        for(int i=0,j=1;i<n;i++,j+=k)
            a[i]-=j;
        int t=(s-1)%(n-1);
        memset(dp,inf,sizeof(dp));
        int r=0;
        dp[0][0]=abs(a[0]);
        for(int i=1;i<n;i++)
        {
            r^=1;
            dp[r][0]=dp[r^1][0]+abs(a[i]);
            for(int j=1;j<=i&&j<=t;j++)
            {
                dp[r][j]=min(dp[r^1][j],dp[r^1][j-1]);
                dp[r][j]+=abs(a[i]-j);
            }
        }
        printf("%d\n",dp[r][t]);
    }
    return 0;
}
