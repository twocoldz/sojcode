#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define modd 19871118

using namespace std;
int dp[2][1<<20];
int cnt[1<<20];

void Init()
{
    for(int i=0;i<(1<<20);i++)
    {
        int ii=i;
        cnt[i]=0;
        while(ii)
        {
            cnt[i]+=ii%2;
            ii/=2;
        }
    }
}

int main()
{
    Init();
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        int r=0;
        int state;
        int x;
        if(n<k||m<k)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    scanf("%d",&x);
                }
            }
            printf("0\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            r^=1;
            state=0;
            for(int j=0;j<m;j++)
            {
                scanf("%d",&x);
                state=(state<<1)|x;
            }
            for(int j=0;j<(1<<m);j++)
            {
                dp[r][j]=dp[r^1][j];
                if(cnt[j]<=i&&cnt[j]<=k)
                {
                    if(cnt[j]==1)
                    {
                        if(state&j)
                            dp[r][j]++;
                        continue;
                    }
                    for(int l=0;l<m;l++)
                    {
                        if(j&(1<<l)&state)
                        {
                            int t=j^(1<<l);
                            dp[r][j]=(dp[r][j]+dp[r^1][t])%modd;
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<(1<<m);i++)
        {
            if(cnt[i]==k)
            {
                ans=(ans+dp[r][i])%modd;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
