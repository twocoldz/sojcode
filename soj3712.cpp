#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int v,nxt,l;
}edge[100005];
int head[50005];
int num[50005];
long long dp[50005];
int res[50005];
int n,e,m;
long long ans;

void Init()
{
    e=0;
    memset(head,-1,(n+1)*sizeof(head[0]));
    memset(num,0,(n+1)*sizeof(head[0]));
}

void AddEdge(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].l=w;
    edge[e].nxt=head[u];
    head[u]=e++;
}

void Dfs(int u,int fa)
{
    dp[u]=0;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(v!=fa)
        {
            Dfs(v,u);
            dp[u]+=(dp[v]+(long long)num[v]*2*(long long)edge[i].l);
            num[u]+=num[v];
        }
    }
}

void Dp(int u,int fa)
{
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(v!=fa)
        {
            dp[v]+=(dp[u]-dp[v])+2*((long long)num[u]-num[v]-num[v])*(long long)edge[i].l;
            if(dp[v]<ans)
                ans=dp[v];
            num[v]=num[u];
            Dp(v,u);
        }
    }
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&n);
        Init();
        int a,b,w;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            AddEdge(a,b,w);
            AddEdge(b,a,w);
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            num[a]=b;
        }
        Dfs(1,0);
        ans=dp[1];
        Dp(1,0);
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            if(ans==dp[i])
                res[tot++]=i;
        }
        printf("%lld\n",ans);
        for(int i=0;i<tot;i++)
        {
            i+1==tot?printf("%d\n",res[i]):printf("%d ",res[i]);
        }
    }
    return 0;
}
