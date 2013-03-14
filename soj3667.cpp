#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int v,nxt;
}edge[100005*2];
int head[100005],dp[100005];
bool vis[100005];
int n,e,m,ans;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
}

void AddEdge(int u,int v)
{
    edge[e].v=v;
    edge[e].nxt=head[u];
    head[u]=e++;
}

void Dfs(int u)
{
    vis[u]=1;
    bool f=0;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(!vis[v])
        {
            f=1;
            Dfs(v);
            dp[u]+=dp[v];
        }
    }
    if(!f)
        dp[u]=1;
    else if(dp[u]>m)
        ans+=m/2,dp[u]=0;
    else
        ans+=dp[u]/2,dp[u]%=2;
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        Init();
        int a,b;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            dp[a]++;
            dp[b]++;
            AddEdge(a,b);
            AddEdge(b,a);
        }
        int rt;
        for(int i=1;i<=n;i++)
            if(dp[i]>=2)
            {
                rt=i;
                break;
            }
        memset(dp,0,sizeof(dp));
        m*=2;
        ans=0;
        Dfs(rt);
        printf("%d\n",ans);
    }
    return 0;
}
