#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f

using namespace std;
int mi[2050];
int c[1050];
int dp[1050][15];
int p;

int Dfs(int miss,int deep,int rt)
{
    if(deep==p)
    {
        if(miss<=mi[rt])
            return 0;
        else
            return inf;
    }
    if(dp[rt][miss]!=-1)
    {
        return dp[rt][miss];
    }
    if(miss>mi[rt])
        return dp[rt][miss]=inf;
    dp[rt][miss]=Dfs(miss,deep+1,rt<<1)+Dfs(miss,deep+1,rt<<1|1)+c[rt];
    int t=Dfs(miss+1,deep+1,rt<<1)+Dfs(miss+1,deep+1,rt<<1|1);
    if(t<dp[rt][miss])
        dp[rt][miss]=t;
    t=Dfs(miss+1,deep,rt);
    if(t<dp[rt][miss])
        dp[rt][miss]=t;
    return dp[rt][miss];
}

int main()
{
    int t;
    int cases=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&p);
        for(int i=(1<<p);i<(1<<(p+1));i++)
        {
            scanf("%d",mi+i);
        }

        for(int i=p-1;i>=0;i--)
        {
            for(int j=(1<<i);j<(1<<(i+1));j++)
            {
                mi[j]=min(mi[j<<1],mi[j<<1|1]);
            }
        }
        for(int i=p-1;i>=0;i--)
        {
            for(int j=(1<<i);j<(1<<(i+1));j++)
            {
                scanf("%d",c+j);
            }
        }
        memset(dp,-1,sizeof(dp));
        printf("Case #%d: %d\n",cases++,Dfs(0,0,1));
    }
    return 0;
}
