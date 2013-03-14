#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
long long dp[1<<16][16];
int s[16];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",s+i);
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[1<<i][i]=1;
        }
        for(int i=0;i<(1<<n);i++)
        {
            for(int j=0;j<n;j++)
            {
                int tt=i&(1<<j);
                //printf("tt=%d\n",tt);
                if(!tt)
                {
                    for(int k=0;k<n;k++)
                    {
                        if(((1<<k)&i)&&abs(s[j]-s[k])>m)
                        {
                            dp[i^(1<<j)][j]+=dp[i][k];
                            //printf("dp[%d][%d]=%lld\n",tt,j,dp[tt][j]);
                        }
                    }
                }
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=dp[(1<<n)-1][i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
