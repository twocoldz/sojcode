#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define inf -5000000

using namespace std;
struct Node
{
    int w;
    vector<int> s;
}v[505];
int dp[505][2][505];
int n,m;

void Init()
{
    v[0].w=0;
    for(int i=0;i<=500;i++)
        for(int j=0;j<=500;j++)
            dp[i][0][j]=dp[i][1][j]=inf;
    for(int i=0;i<=n;i++)
        v[i].s.clear();
}
/*
void Dfs(int rt)
{
    int len=v[rt].s.size();
    dp[rt][0][0]=0;
    dp[rt][0][1]=v[rt].w;
    //printf("len=%d rt=%d\n",len,rt);
    for(int i=0;i<len;i++)
    {
        int t=v[rt].s[i];
        Dfs(t);
        for(int j=n-1;j>=0;j--)
        {
            for(int k=j;k>=0&&dp[rt][j-k][0]>inf;k--)
            {
                dp[rt][j][0]=max(dp[rt][j][0],dp[rt][j-k][0]+max(dp[t][k][0],dp[t][k][1]));
            }
            //printf("dp[%d][%d][0]=%d\n",rt,j,dp[rt][j][0]);
        }
        for(int j=n-1;j>=0;j--)
        {
            for(int k=j-1;k>=0&&dp[rt][j-k-1][1]>inf;k--)
            {
                dp[rt][j][1]=max(dp[rt][j][1],max((dp[rt][j-k][1]+dp[t][k][0]),(dp[rt][j-k-1][1]+dp[t][k][1])));
            }
            //printf("dp[%d][%d][1]=%d\n",rt,j,dp[rt][j][1]);
        }
    }
}*/
void Dfs(int now)
{
     int size=v[now].s.size();
     dp[now][0][0]=0;
     dp[now][1][0]=v[now].w;
     for(int i=0;i<size;i++)
     {
         int son=v[now].s[i];
         Dfs(son);
         for(int j=n-1;j>=0;j--)
         {
             int t=dp[now][0][j];
             for(int k=j;dp[now][0][j-k]>inf && k>=0;k--)
             {
                 t=max(t,dp[now][0][j-k]+max(dp[son][0][k],dp[son][1][k]));
             }
             dp[now][0][j]=t;
         }
         for(int j=n-1;j>=0;j--)
         {
             int t=max(dp[now][1][j],dp[now][1][0]+dp[son][0][j]);
             for(int k=j-1;dp[now][1][j-k-1]>inf && k>=0;k--)
             {
                 t=max(t,max(dp[now][1][j-k]+dp[son][0][k],dp[now][1][j-k-1]+dp[son][1][k]));
             }
             dp[now][1][j]=t;
         }
     }
 }

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        int a;
        Init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&v[i].w,&a);
            v[a].s.push_back(i);
        }
        Dfs(0);
        int ans=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(dp[0][0][i]>=m)
            {
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
