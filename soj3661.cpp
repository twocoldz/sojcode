#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int a[185],b[185];
int dp[185][185];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        for(int i=1;i<=m;i++)
            scanf("%d",b+i);
        dp[0][0]=0;
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(a[i]==b[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans=max(ans,dp[i][j]);
                }
                else
                    dp[i][j]=0;
            }

        printf("%d\n",ans);
    }
    return 0;
}
