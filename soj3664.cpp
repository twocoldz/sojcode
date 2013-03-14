#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[1255];
int v[105],h[105];

int main()
{
    int n,H,m;
    while(scanf("%d%d%d",&n,&H,&m)==3)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",v+i,h+i);
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        int ans=0;
        for(int i=0;i<=(H*5/4)+1;i++)
        {
            if(dp[i]==-1)
                continue;
            for(int j=1;j<=n;j++)
            {
                if(i+h[j]>=(H*5/4)+1)
                    continue;
                dp[i+h[j]]=max(dp[i+h[j]],dp[i]+v[j]);
                if(h[j]<m&&i+h[j]<=H&&dp[i+h[j]]>ans)
                    ans=dp[i+h[j]];
                if(h[j]>=m&&i*4/5+h[j]<=H&&dp[i+h[j]]>ans)
                    ans=dp[i+h[j]];
                //printf("i=%d j=%d h[j]=%d v[j]=%d dp[i+h[j]]=%d\n",i,j,h[j],v[j],dp[i+h[j]]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
