#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int v,nxt,l;
}edge[100005*2];
int head[100005],num[100005];
long long dp[100005];
bool vis[100005];
int n,e;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
}

void AddEdge(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].nxt=head[u];
    edge[e].l=w;
    head[u]=e++;
}

void Dfs(int u)
{
    vis[u]=1;
    num[u]=1;
    dp[u]=0;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(!vis[v])
        {
            Dfs(v);
            num[u]+=num[v];
            dp[u]+=(long long)num[v]*(long long)edge[i].l+dp[v];
        }
    }
}

void Dp(int u)
{
    vis[u]=1;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(!vis[v])
        {
            dp[v]+=(long long)(num[u]-num[v]-num[v])*(long long)edge[i].l+dp[u]-dp[v];
            num[v]=num[u];
            Dp(v);
        }
    }
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        Init();
        int a,b,l;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&l);
            a++,b++;
            AddEdge(a,b,l);
            AddEdge(b,a,l);
        }
        Dfs(1);
        memset(vis,0,sizeof(vis));
        Dp(1);
        for(int i=1;i<=n;i++)
        {
            i==n?printf("%lld\n",dp[i]):printf("%lld ",dp[i]);
        }
    }
    return 0;
}
