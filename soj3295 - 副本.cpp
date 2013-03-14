#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
struct Node
{
    int v,nxt;
}edge[20005];
int head[10005],e;
int n,L;
int dp[10005][105];
int sum[10005],dis[10005];
int ans,f[10005][105];

inline void AddEdge(int u,int v)
{
    edge[e].v=v;
    edge[e].nxt=head[u];
    head[u]=e++;
}

void Dfs1(int x,int r)
{
    int v;
    sum[x]=1;
    dis[x]=0;
    for(int i=head[x]; i; i=edge[i].nxt)
    {
        v=edge[i].v;
        if(v==r)continue;
        Dfs1(v,x);
        sum[x]+=sum[v];
        dis[x]+=dis[v]+sum[v];
    }
    dp[x][0]=dis[x];
    for(int i=head[x]; i; i=edge[i].nxt)
    {
        v=edge[i].v;
        if(v==r)
            continue;
        for(int j=1; j<=L; j++)
        {
            dp[x][j]=min(dp[x][j],dp[v][j-1]+dis[x]-dis[v]-sum[v]);
            dp[x][j]=min(dp[x][j],dp[x][j-1]);
        }
    }
}

void Dfs2(int x,int r)
{
    int v,Min=inf,tans;
    if(x==0)
        tans=0;
    else
        tans=(dis[r]-dis[x]-sum[x])+(n-sum[x]);

    memset(f[x],inf,sizeof(f[x]));
    for(int i=head[x]; i; i=edge[i].nxt)
    {
        v=edge[i].v;
        if(v==r)
            continue;
        for(int j=2; j<=L; j++)
        {
            Min=min(Min,dp[v][j-2]+f[x][L-j]+dis[x]-dis[v]-sum[v]);
        }
        for(int j=0; j<=L; j++)
        {
            f[x][j]=min(f[x][j],dp[v][j]-dis[v]-sum[v]);
            f[x][j]=min(f[x][j],f[x][j-1]);
        }
        Min=min(Min,dp[v][L-1]+dis[x]-dis[v]-sum[v]);
    }
    tans+=Min;
    ans=min(tans,ans);
    if(x)
        dis[x]=dis[r]-sum[x]-sum[x]+n;
    for(int i=head[x];i;i=edge[i].nxt)
    {
        v=edge[i].v;
        if(v==r)
            continue;
        Dfs2(v,x);
    }
}

int main()
{
    //int t;
    //scanf("%d",&t);
    while(scanf("%d%d",&n,&L)&&n+L)
    {
        //scanf("%d%d",&n,&L);
        //if(n==0&&L==0)
        //    break;
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        e=1;
        memset(head,0,sizeof(head));
        int x,y;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            AddEdge(x,y);
            AddEdge(y,x);
        }
        memset(dp,inf,sizeof(dp));
        Dfs1(0,-1);
        ans=inf;
        Dfs2(0,-1);
        printf("%d\n",ans);
    }
    return 0;
}
