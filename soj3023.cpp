#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int v,nxt;
}edge[200005],q[200005];
const int N=100005;
int heade[N],headq[N];
bool vis[N];
int fa[N],dp[N];
int n,m,e;
long long ans;

void Init()
{
    e=ans=0;
    memset(heade,-1,(n+1)*sizeof(heade[0]));
    memset(headq,-1,(n+1)*sizeof(headq[0]));
    memset(dp,0,(n+1)*sizeof(dp[0]));
    memset(vis,0,(n+1)*sizeof(vis[0]));
}

void AddEdge(int u,int v)
{
    edge[e].v=v;
    edge[e].nxt=heade[u];
    heade[u]=e++;
}

void AddQuery(int u,int v)
{
    q[e].v=v;
    q[e].nxt=headq[u];
    headq[u]=e++;
}

int FindFa(int x)
{
    if(fa[x]!=x)
    {
        fa[x]=FindFa(fa[x]);
    }
    return fa[x];
}

void tarjan(int u)
{
    vis[u]=1;
    for(int i=headq[u];~i;i=q[i].nxt)
    {
        int v=q[i].v;
        if(vis[v])
        {
            dp[FindFa(v)]-=2;
        }
    }
    for(int i=heade[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(!vis[v])
        {
            tarjan(v);
            fa[v]=u;
            dp[u]+=dp[v];
            if(dp[v]==1)
                ans++;
            if(dp[v]==0)
                ans+=m;
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        int a,b;
        Init();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            AddEdge(a,b);
            AddEdge(b,a);
        }
        e=0;
        for(int i=1;i<=n;i++)
            fa[i]=i;//vis[i]=0,dp[i]=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            if(a!=b)
            {
                AddQuery(a,b);
                AddQuery(b,a);
                dp[a]++;
                dp[b]++;
            }
        }
        tarjan(1);
        printf("%lld\n",ans);
    }
    return 0;
}
