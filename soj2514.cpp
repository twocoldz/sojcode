#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

#define inf -5000000

using namespace std;
struct Node
{
    int w;
    vector<int> son;
}v[505];
int dp[505][2][505];
int n;

/*void Dfs(int rt)
{
    dp[rt][0][0]=0;
    dp[rt][0][1]=node[rt].w;
    int len=node[rt].son.size();
    for(int i=0;i<len;i++)
    {
        int tt=node[rt].son[i];
        Dfs(tt);
        for(int j=n-1;j>=0;j--)
        {
            int t=dp[rt][j][0];
            for(int k=j;dp[rt][j-k][0]>inf&&k>=0;k--)
            {
                t=max(t,dp[rt][j-k][0]+max(dp[tt][k][0],dp[tt][k][1]));
            }
            dp[rt][j][0]=t;
        }

        for(int j=n-1;j>=0;j--)
        {
            int t=max(dp[rt][j][1],dp[rt][0][1]+dp[tt][j][0]);
            for(int k=j-1;dp[rt][j-k-1][1]>inf&&k>=0;k--)
            {
                t=max(t,max(dp[rt][j-k][1]+dp[tt][k][0],dp[rt][j-k-1][1]+dp[tt][k][1]));
            }
            dp[rt][j][1]=t;
        }
    }
}*/

void Dfs(int now)
{
     int size=v[now].son.size();
     dp[now][0][0]=0;
     dp[now][1][0]=v[now].w;
     for(int i=0;i<size;i++)
     {
         int son=v[now].son[i];
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

void Init()
{
    for(int i=0;i<=500;i++)
    {
        for(int j=0;j<=500;j++)
        {
            dp[i][0][j]=dp[i][1][j]=inf;
        }
    }
    for(int i=0;i<=n;i++)
    {
        v[i].son.clear();
    }
}

int main()
{
    int m;
    while(scanf("%d%d",&n,&m)==2)
    {
        Init();
        int y;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&v[i].w,&y);
            v[y].son.push_back(i);
        }
        v[0].w=0;
        Dfs(0);

        int flag=1;
        for(int i=n-1;i>=0;i--)
            if(dp[0][0][i]>=m)
            {
                printf("%d\n",i);
                flag=0;
                break;
            }
        if(flag)
            puts("-1");
    }
    return 0;
}
