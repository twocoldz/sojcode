#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N=100005;
struct node
{
    int v,nxt,l;
}edge[N*2];
int head[N];
long long dp[N],c[N],a[N];
int n,e;
long long ans;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
}

void AddEdge(int v,int u,int w)
{
    edge[e].v=v;
    edge[e].l=w;
    edge[e].nxt=head[u];
    head[u]=e++;
}

void Dfs(int u,int fa)
{
    dp[u]=c[u]=0;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(v!=fa)
        {
            Dfs(v,u);
            dp[u]+=dp[v]+c[v]*edge[i].l;
            c[u]+=c[v];
        }
    }
    c[u]+=a[u];
}

void Dp(int u,int fa)
{
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(v!=fa)
        {
            long long t=dp[u]-edge[i].l*c[v]+(c[u]-c[v])*edge[i].l;
            dp[v]=t;
            ans=min(t,ans);
        }
    }
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(v!=fa)
        {
            c[v]=c[u];
            Dp(v,u);
        }
    }
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        Init();
        int c,b,l;
        for(int i=1;i<=n;i++)
            scanf("%lld",a+i);
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&c,&b,&l);
            AddEdge(c,b,l);
            AddEdge(b,c,l);
        }
        Dfs(1,0);
        ans=dp[1];
        Dp(1,0);
        //for(int i=1;i<=n;i++)
        //    printf("dp[%d]=%d\n",i,dp[i]);
        printf("%lld\n",ans);
    }
    return 0;
}
