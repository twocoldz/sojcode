#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
struct Node
{
    int v,n;
}edge[205];
int dp[105][205][2];
bool vis[105];
int head[205];
int num[105];
int n,m,e;

void AddEdge(int u,int v)
 {
     edge[e].v=v;
     edge[e].n=head[u];
     head[u]=e++;
 }

void Dfs(int rt)
{
    vis[rt]=1;
    for(int i=0;i<=m;i++)
    {
        dp[rt][i][1]=dp[rt][i][0]=num[rt];
    }

    for(int i=head[rt];~i;i=edge[i].n)
    {
        int v=edge[i].v;
        if(!vis[v])
        {
            Dfs(v);
            for(int j=m;j>=0;j--)
            {
                for(int k=0;k<=j;k++)
                {
                    dp[rt][j+2][0]=max(dp[rt][j+2][0],dp[v][k][0]+dp[rt][j-k][0]);
                    dp[rt][j+2][1]=max(dp[rt][j+2][1],dp[v][k][0]+dp[rt][j-k][1]);
                    dp[rt][j+1][1]=max(dp[rt][j+1][1],dp[v][k][1]+dp[rt][j-k][0]);
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));
        e=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",num+i);
        }
        int x,y;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            AddEdge(x,y);
            AddEdge(y,x);
        }
        Dfs(1);
        printf("%d\n",dp[1][m][1]);
    }
    return 0;
}
