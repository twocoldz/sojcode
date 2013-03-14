#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define mod 1000000007

using namespace std;
int dp[1<<20];
int a[1000005];
int cnt[1<<20];
int n,m;

void Init()
{
    a[0]=1;
    for(int i=1;i<=1000000;i++)
    {
        a[i]=(int)(((long long)a[i-1]*(long long)2)%mod);
    }
    for(int i=0;i<(1<<20);i++)
    {
        cnt[i]=0;
        for(int j=0;j<20;j++)
        {
            if(i&(1<<j))
                cnt[i]++;
        }
    }
}

int main()
{
    Init();
    while(scanf("%d%d",&n,&m)==2)
    {
        int x,k,t;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            t=0;
            scanf("%d",&k);
            for(int j=0;j<k;j++)
            {
                scanf("%d",&x);
                x--;
                t|=(1<<x);
            }
            dp[t]++;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<(1<<m);j++)
            {
                if(j&(1<<i))
                    dp[j]+=dp[j-(1<<i)];
            }
        }
        int ans=0;
        for(int i=0;i<(1<<m);i++)
        {
            if(cnt[i]&1)
                ans+=(mod-a[dp[(1<<m)-i-1]]);
            else
                ans+=a[dp[(1<<m)-i-1]];
            ans%=mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
